#!/usr/bin/env python3

'''
A utility to track real-time and make optimal decision how long enable
green/red light on crossroads based on the traffic.
'''

import os
import sys
import cv2
import time
import copy
import numpy as np
from datetime import datetime
from imutils.video import FPS
from imutils.video import VideoStream
from Xlib.display import Display
from src.config_parser import configParser
from src.entity import entity
from multiprocessing import Process

# Check if machine is Raspberry PI.
RUNNING_ON_RPI = False
os_info = os.uname()
if os_info[4][:3] == 'arm':
    RUNNING_ON_RPI = True

class text_colors:
    '''
    Class holding ASCII color codes as members.
    '''
    UNDERLINE = '\033[4m'
    WARNING = '\033[33m'
    HEADER = '\033[95m'
    BOLD = '\033[1m'
    BLUE = '\033[94m'
    STRONG_BLUE = '\033[38;5;21m'
    CYAN = '\033[36m'
    GREEN = '\033[32m'
    RED = '\033[31m'
    END = '\033[0m'

# Custom log message configuration.
log_level = 1
log_levels = {
              'CRITICAL': 4,
              'ERROR': 3,
              'WARNING': 2,
              'INFO': 1,
              'DEBUG': 0
             }

# Utility window name.
WINDOW_NAME = "Traffic Control."

class trafficLight(Process):
    def __init__(self):
        self.state = ""
        self.green_time = 0
        self.red_time = 0
        self.yellow_time = 1
        self.end_flag = False
        self.worker_process = Process(target = self.do_work)

    def update_green_time(self, new_time):
        if not self.green_time == new_time:
            self.green_time = new_time

    def update_red_time(self, new_time):
        if not self.red_time == new_time:
            self.red_time = new_time

    def get_state(self):
        return self.state

    def start_processing(self):
        """
        Starts process execution.
        """
        self.worker_process.start()

    def stop_processing(self):
        """
        Stops process execution, joins to the main process.
        """
        self.worker_process.join()

    def close(self):
        """
        Terminate the process.
        """
        self.worker_process.terminate()

    def do_work(self):
        """
        Simulates traffic light.
        """
        while not self.end_flag:
            start_time = time.time()
            while time.time() - start_time < self.green_time:
                self.state = "green"
                time.sleep(1)
            start_time = time.time()
            while time.time() - start_time < self.yellow_time:
                self.state = "yellow"
                time.sleep(1)
            start_time = time.time()
            while time.time() - start_time < self.red_time:
                self.state = "red"
                time.sleep(1)
            start_time = time.time()
            while time.time() - start_time < self.yellow_time:
                self.state = "yellow"
                time.sleep(1)

def colorize_text(log_level):
    '''
    Functionality that colorizes message log level.
    First argument - log level of the message.
    '''
    if log_level == "CRITICAL":
        log_level = text_colors.UNDERLINE\
                    + text_colors.BOLD\
                    + text_colors.RED\
                    + log_level\
                    + text_colors.END
    elif log_level == "ERROR":
        log_level = text_colors.RED\
                    + log_level\
                    + text_colors.END
    elif log_level == "WARNING":
        log_level = text_colors.WARNING\
                    + log_level\
                    + text_colors.END
    elif log_level == "INFO":
        log_level = text_colors.GREEN\
                    + log_level\
                    + text_colors.END
    elif log_level == "DEBUG":
        log_level = text_colors.CYAN\
                    + log_level\
                    + text_colors.END
    return log_level

def log(level, message):
    '''
    Functionality that validates all given arguments and outputs corresponding message.
    First argument - level of the message.
    Second argument - message body.
    '''
    if log_levels[level.upper()] >= log_level:
        current_date = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        level = colorize_text(level)
        current_date = text_colors.HEADER + current_date + text_colors.END
        print(f"[{current_date}] [{level}]: {message}")

def get_frame(stream, input_file):
    '''
    Functionality that return a copy of the frame based on the stream base,
    i.e. from camera or video.
    First argument - stream object.
    Second argument - input file path.
    '''
    frame = stream.read()
    frame = frame[1] if input_file else frame
    image_for_result = frame.copy()
    return image_for_result

def configure_output_writer(output_file, frame):
    '''
    Functionality that configures output video writer.
    First argument - output video filename,
    Second argument - frame,
    '''
    fourcc = cv2.VideoWriter_fourcc(*"mp4v")
    writer = cv2.VideoWriter(output_file,
                             fourcc,
                             30,
                             (frame.shape[1],
                              frame.shape[0]),
                             True)
    return writer

def predict(frame, net, confidence, DB):
    '''
    Functionality that predicts and returns detected object DB.
    First argument - frame.
    Second argument - model network.
    Third argument - model confidence.
    Fourth argument - DB object.
    '''
    try:
        input_width = int(cp.get_value_from_config('Accelerator', 'model_detect_width'))
    except:
        input_width = 512
    try:
        input_height = int(cp.get_value_from_config('Accelerator', 'model_detect_height'))
    except:
        input_height = 512
    blob = cv2.dnn.blobFromImage(frame,
                                 size = (input_width,
                                         input_height),
                                 ddepth = cv2.CV_8U)
    net.setInput(blob)
    out = net.forward()
    predictions = []
    counters = {
                "Car": 0,
                "Bike": 0,
                "Person": 0,
               }
    # The net outputs a blob with the shape: [1, 1, N, 7], where N is the number of detected bounding boxes.
    # For each detection, the description has the format: [image_id, label, conf, x_min, y_min, x_max, y_max]
    frame_height, frame_width, _ = frame.shape
    DB.clear()
    for detection in out.reshape(-1, 7):
        image_id, label, conf, x_min, y_min, x_max, y_max = detection
        if conf > confidence:
            x_min = int(x_min * frame_width)
            y_min = int(y_min * frame_height)
            x_max = int(x_max * frame_width)
            y_max = int(y_max * frame_height)
            center_x = int((x_max - x_min) / 2) + x_min
            center_y = int((y_min - y_max) / 2) + y_min
            bounding_box = ((x_min, y_min), (x_max, y_max))
            if label == 1.0:
                label = "Car"
            elif label == 2.0:
                label = "Person"
            elif label == 3.0:
                label = "Bike"
            counters[label] += 1
            new_entity = entity()
            new_entity.set_type(label)
            new_entity.set_center_point(center_x, center_y)
            new_entity.set_confidence(conf)
            new_entity.set_bounding_box(bounding_box)
            DB.append(new_entity)
    return counters

def draw_light(frame, colors, timer):
    '''
    Functionality that draws traffic light with timer.
    First argument - frame.
    Second argument - traffic light colors.
    Third argument - timer.
    '''
    radius = 20
    font_size = 1
    font_weight = 2
    font_family = cv2.FONT_HERSHEY_SIMPLEX
    padding = int(radius * 1.5)
    step = int(padding * 1.5)
    x = frame.shape[1] - padding
    y = padding
    cv2.circle(frame,
               (x, y),
               radius,
               colors['green'],
               -1)
    y += step
    cv2.circle(frame,
               (x, y),
               radius,
               colors['yellow'],
               -1)
    if len(timer) > 1:
        font_size = 0.75
    size = cv2.getTextSize(timer,
                           font_family,
                           font_size,
                           font_weight)[0]
    text_x = int(x - size[0] / 2)
    cv2.putText(frame,
                timer,
                (text_x, int(y + size[1] / 2)),
                font_family,
                font_size,
                (0, 0, 255),
                font_weight)
    y += step
    cv2.circle(frame,
               (x, y),
               radius,
               colors['red'],
               -1)

def draw_traffic_light(frame, end_time, start_time_light, lights_info):
    '''
    Functionality that calculates timer and draws traffic light with timer on
    the frame.
    First argument - frame.
    Second argument - current time.
    Third argument - timer start time.
    '''
    green_time = lights_info['green']['timer']
    red_time = lights_info['red']['timer']
    difference_time_light = (end_time - start_time_light).seconds
    light_timer = 12
    yellow_light_timer = 1
    green_light_timer = green_time - 1
    first_yellow_light_timer = green_light_timer - 1 + yellow_light_timer
    red_light_timer = first_yellow_light_timer + red_time
    second_yellow_light_timer = red_light_timer + yellow_light_timer
    colors = {
              'green': (0, 0, 0),
              'yellow': (0, 0, 0),
              'red': (0, 0, 0)
             }
    if difference_time_light <= green_light_timer:
        colors['green'] = (0, 255, 0)
        lights_info['red']['enabled'] = False
        lights_info['green']['enabled'] = True
        diff_time = green_light_timer - difference_time_light
    elif difference_time_light <= first_yellow_light_timer:
        colors['yellow'] = (0, 255, 255)
        lights_info['red']['enabled'] = False
        lights_info['green']['enabled'] = False
        diff_time = first_yellow_light_timer - difference_time_light
    elif difference_time_light <= red_light_timer:
        colors['red'] = (0, 0, 255)
        lights_info['red']['enabled'] = True
        lights_info['green']['enabled'] = False
        diff_time = red_light_timer - difference_time_light
    elif difference_time_light <= second_yellow_light_timer:
        colors['yellow'] = (0, 255, 255)
        lights_info['red']['enabled'] = False
        lights_info['green']['enabled'] = False
        diff_time = second_yellow_light_timer - difference_time_light
    else:
        start_time_light = end_time
        diff_time = 0
    draw_light(frame, colors, str(diff_time + 1))
    return start_time_light

def draw_counters(frame, counters):
    '''
    Functionality draws counters on the frame.
    First argument - frame.
    Second argument - counters object.
    '''
    x = 0
    y = 25
    step = 20
    for counter in counters:
        cv2.putText(frame,
                    "%s: %s" % (counter, counters[counter]),
                    (x, y),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.75,
                    (0, 0, 0),
                    2)
        y += step

def calculate_time(counters, lights_info):
    '''
    Functionality that calculates approximate time for green and red time.
    First argument - overall counters.
    '''
    red_enabled = lights_info['red']['enabled']
    green_enabled = lights_info['green']['enabled']
    if counters['Car'] > 3:
        if not red_enabled:
            lights_info['red']['timer'] = 5
        if not green_enabled:
            lights_info['green']['timer'] = 3
    else:
        if not red_enabled:
            lights_info['red']['timer'] = 3
        if not green_enabled:
            lights_info['green']['timer'] = 2

def draw_on_frame(frame, DB, counters, lights_info, end_time, start_time_light):
    '''
    Functionality that draws rectangles and real-time counters.
    First argument - frame.
    Second argument - DB object.
    Third argument - counters object.
    '''
    for new_entity in DB:
        bounding_box = new_entity.get_bounding_box()
        confidence = new_entity.get_confidence()
        label = new_entity.get_type()
        direction = new_entity.get_direction()
        top_left = bounding_box[0]
        bottom_right = bounding_box[1]
        x_min = top_left[0]
        y_min = top_left[1]
        x_max = bottom_right[0]
        y_max = bottom_right[1]
        offset = 15
        y = y_min - offset if y_min - offset > offset else y_min + offset
        if label == "Bike":
            color = (255, 0, 0)
        elif label == "Car":
            color = (0, 0, 255)
        elif label == "Person":
            color = (0, 255, 0)
        label += ": {:.2f}%".format(confidence * 100)
        cv2.rectangle(frame,
                      (x_min, y_min),
                      (x_max, y_max),
                      color,
                      2)
        cv2.putText(frame,
                    label + direction,
                    (x_min, y),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.75,
                    color,
                    2)
    draw_counters(frame, counters)
    calculate_time(counters, lights_info)
    start_time_light = draw_traffic_light(frame,
                                          end_time,
                                          start_time_light,
                                          lights_info)
    return start_time_light

def get_screen_size():
    '''
    Functionality that gets and returns screen size in pixels.
    '''
    screen = Display(os.environ["DISPLAY"]).screen()
    screen_width, screen_height = screen.width_in_pixels, screen.height_in_pixels
    return screen_width, screen_height

def check_direction(previous_DB, DB):
    '''
    Functionality that check every entities movement direction.
    First argument - previous DB object.
    Second argument - DB object.
    '''
    try:
        direction_detection_difference = int(cp.get_value_from_config('General', 'direction_detection_difference'))
    except:
        direction_detection_difference = 5
    try:
        movement_detection_radius = int(cp.get_value_from_config('General', 'movement_detection_radius'))
    except:
        movement_detection_radius = 10
    for new_entity in DB:
        label = new_entity.get_type()
        bounding_box = new_entity.get_bounding_box()
        confidence = new_entity.get_confidence()
        center_point = new_entity.get_center_point()
        found_flag = False
        if previous_DB:
            new_x = center_point.x()
            new_y = center_point.y()
            for previous_entity in previous_DB:
                if found_flag:
                    break
                previous_center = previous_entity.get_center_point()
                previous_x = previous_center.x()
                previous_y = previous_center.y()
                difference_x = new_x - previous_x
                difference_y = new_y - previous_y
                log("DEBUG", f"DX : {difference_x} DY: {difference_y}")
                log("DEBUG", f"NX : {new_x} NY: {new_y}")
                log("DEBUG", f"PX : {previous_x} PY: {previous_y}")
                if abs(difference_x) < movement_detection_radius\
                   and abs(difference_y) < movement_detection_radius:
                    direction = new_entity.get_direction()
                    if difference_x > direction_detection_difference:
                        direction += ":RIGHT"
                    elif difference_x < -1 * direction_detection_difference:
                        direction += ":LEFT"
                    if difference_y > direction_detection_difference:
                        direction += ":DOWN"
                    elif difference_y < -1 * direction_detection_difference:
                        direction += ":UP"
                    found_flag = True
                    new_entity.set_direction(direction)
                    break

def write_data(counters, start_time, end_time):
    '''
    Functionality that writes collected data into the log file.
    First argument - counters object.
    Second argument - collecting start time.
    Third argument - collecting end time.
    '''
    data = "%s - %s | " % (start_time, end_time)
    for field in counters:
        data += "%ss: %s " % (field, counters[field])
    data += "\n"
    with open("data.log", "a") as f:
        f.write(data)

def get_average_data(average_counters, counters):
    '''
    Functionality that calculates average counter.
    First argument - average counter object.
    Second argument - counters object.
    '''
    if not average_counters:
        average_counters = counters
    else:
        for field in counters:
            average_counters[field] += counters[field]
    return average_counters

def check_quanity(end_time, start_time_check, average_counters, counters):
    '''
    Functionality that checks quantity of the entities in the frame.
    First argument - end time of checking.
    Second argument - start time of the checking.
    Third argument - average counters object.
    Fourth argument - counters object.
    '''
    difference_time_check = (end_time - start_time_check).seconds / 60
    if difference_time_check >= 0.1:
        average_counters = get_average_data(average_counters, counters)
        start_time_check = end_time
    return start_time_check, average_counters

def check_write_data(end_time, start_time_write, data_collecting_time, average_counters):
    '''
    Functionality that checks if it is time to write collected data into log.
    First argument - end time of the checking.
    Second argument - start time of the checking.
    Third argument - period in minutes of time to collect data and write into the log.
    Fourth argument - average counters object.
    '''
    difference_time_write = (end_time - start_time_write).seconds / 60
    if difference_time_write >= data_collecting_time:
        write_data(average_counters, start_time_write, end_time)
        start_time_write = end_time
        average_counters = {}
    return start_time_write, average_counters

def show_frame(fullscreen_mode, frame):
    '''
    Functionality that show frame.
    First argument - full-screen mode flag.
    Second argument - frame.
    '''
    if fullscreen_mode:
        screen_width, screen_height = get_screen_size()
        frame = cv2.resize(frame,
                                      (screen_width, screen_height),
                                      interpolation = cv2.INTER_AREA)
    cv2.imshow(WINDOW_NAME, frame)

def start_process(args, net, stream, fps, show_mode, input_file,\
                  fullscreen_mode, overlay_mode, traffic_light):
    '''
    Functionality that run the main process of detection and decision.
    First argument - configuration arguments object.
    Second argument - model network.
    Third argument - FPS counting object.
    Fourth argument - show mode flag.
    Fifth argument - input filename.
    Sixth argument - full-screen mode flag.
    Seventh argument - overlay mode flag.
    '''
    writer = None
    DB = []
    previous_DB = []
    average_counters = {}
    lights_info = {
                   'red': {
                           'timer': 5,
                           'enabled': False
                          },
                   'green': {
                             'timer': 5,
                             'enabled': False
                            }
                   }
    confidence = args['confidence']
    output_file = args['output_file']
    try:
        data_collecting_time = int(cp.get_value_from_config('General', 'data_collecting_time'))
    except:
        data_collecting_time = 1
    date_format = "%Y-%m-%d %H:%M:%S"
    current_date = time.strftime(date_format, time.localtime())
    start_time_check = datetime.strptime(current_date, date_format)
    start_time_write = datetime.strptime(current_date, date_format)
    start_time_light = datetime.strptime(current_date, date_format)
    while True:
        try:
            frame = get_frame(stream, input_file)
            counters = predict(frame, net, confidence, DB)
            check_direction(previous_DB, DB)
            previous_DB = copy.deepcopy(DB)
            current_date = time.strftime(date_format, time.localtime())
            end_time = datetime.strptime(current_date, date_format)
            if show_mode:
                if overlay_mode:
                    start_time_light = draw_on_frame(frame,
                                                     DB,
                                                     counters,
                                                     lights_info,
                                                     end_time,
                                                     start_time_light)
                show_frame(fullscreen_mode, frame)
                prop_val = cv2.getWindowProperty(WINDOW_NAME, cv2.WND_PROP_ASPECT_RATIO)
                if prop_val < 0:
                    break
            if output_file:
                if not isinstance(writer, type(None)):
                    writer.write(frame)
                else:
                    writer = configure_output_writer(output_file, frame)
            start_time_check, average_counters = check_quanity(end_time,
                                                               start_time_check,
                                                               average_counters,
                                                               counters)
            start_time_write, average_counters = check_write_data(end_time,
                                                                  start_time_write,
                                                                  data_collecting_time,
                                                                  average_counters)
            key = cv2.waitKey(1) & 0xFF
            if key == ord("q"):
                break
            fps.update()
        except KeyboardInterrupt:
            break
        except AttributeError as e:
            log("CRITICAL", e)
            break

def load_model():
    '''
    Functionality that load model and returns model network.
    '''
    try:
        MODEL_NAME = cp.get_value_from_config('General', 'model_name')
    except:
        MODEL_NAME = "person-vehicle-bike-detection-crossroad-1016"
    try:
        MODEL_PATH = cp.get_value_from_config('General', 'models_path')
    except:
        MODEL_PATH = "./models"
    GRAPH_FILENAME = MODEL_PATH + "/" + MODEL_NAME
    if RUNNING_ON_RPI:
        GRAPH_FILENAME += "/FP16/"
    else:
        GRAPH_FILENAME += "/FP32/"
    GRAPH_XML = GRAPH_FILENAME + MODEL_NAME + ".xml"
    GRAPH_BIN = GRAPH_FILENAME + MODEL_NAME + ".bin"
    net = cv2.dnn.readNet(GRAPH_XML, GRAPH_BIN)
    net.setPreferableTarget(cv2.dnn.DNN_TARGET_CPU)
    return net

def check_optimization():
    '''
    Functionality that checks if OpenCV optimization is being enabled or not.
    '''
    if not cv2.useOptimized():
        cv2.setUseOptimized(True)

def get_input(input_file):
    '''
    Functionality that gets input file data.
    First argument - input filename.
    '''
    if not input_file:
        dev_filenames = next(os.walk('/dev'), (None, None, []))[2]
        capture_devices = [video for video in dev_filenames if 'video' in video]
        stream = None
        log("INFO", f"found {text_colors.UNDERLINE+text_colors.GREEN}"\
                    f"{len(capture_devices)}{text_colors.END} connected video devices.\n")
        for device in capture_devices:
            device_id = ''.join([n for n in device if n.isdigit()])
            log("WARNING", f"trying to get stream from device with ID: "\
                           f"{text_colors.GREEN+text_colors.BOLD}{device_id}"\
                           f"{text_colors.END}.")
            stream = VideoStream(src = int(device_id)).start()
            try:
                get_frame(stream, None)
                log("INFO", f"starting video stream from device with ID: "\
                            f"{text_colors.GREEN+text_colors.BOLD}{device_id}"\
                            f"{text_colors.END}.\n")
                break
            except AttributeError:
                log("ERROR", f"{text_colors.RED}device with ID: {device_id} "\
                             f"is not streamable{text_colors.END}.\n")
                continue
        if not stream:
            log("CRITICAL", "no streamable device found. Terminating.")
            exit()
        return stream
    log("WARNING", "opening video file.")
    return cv2.VideoCapture(input_file)

def check_app_mode(fullscreen_mode):
    '''
    Functionality that checks application window mode.
    First argument - full-screen mode flag..
    '''
    if not fullscreen_mode:
        cv2.namedWindow(WINDOW_NAME)
    else:
        cv2.namedWindow(WINDOW_NAME, cv2.WND_PROP_FULLSCREEN)
        cv2.setWindowProperty(WINDOW_NAME,cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)

def parse_arguments(cp):
    '''
    Functionality that parses argument from from configuration file.
    First argument configuration parser.
    '''
    global log_level
    show_mode = eval(cp.get_value_from_config('Features', 'show_mode'))
    try:
        log_level = int(cp.get_value_from_config('General', 'log_level'))
    except:
        pass
    try:
        confidence = int(cp.get_value_from_config('Accelerator', 'confidence'))
    except:
        confidence = 0.75
    try:
        fullscreen_mode = eval(cp.get_value_from_config('Features', 'fullscreen_mode'))
    except:
        fullscreen_mode = False
    try:
        overlay_mode = eval(cp.get_value_from_config('Features', 'overlay_mode'))
    except:
        overlay_mode = True
    input_file = cp.get_value_from_config('General', 'input_video_file_path')
    output_file = cp.get_value_from_config('General', 'output_file')
    args = {
            'show_mode' : show_mode,
            'log_level' : log_level,
            'input_file' : input_file,
            'output_file' : output_file,
            'fullscreen_mode' : fullscreen_mode,
            'overlay_mode' : overlay_mode,
            'confidence' : confidence
           }
    return args

def main():
    '''
    Application start point.
    '''
    cp = configParser(log)
    args = parse_arguments(cp)
    show_mode = args['show_mode']
    input_file = args['input_file']
    fullscreen_mode = args['fullscreen_mode']
    check_optimization()
    check_app_mode(fullscreen_mode)
    net = load_model()
    stream = get_input(input_file)
    traffic_light = trafficLight()
    fps = FPS().start()
    start_process(args,
                  net,
                  stream,
                  fps,
                  show_mode,
                  input_file,
                  fullscreen_mode,
                  args['overlay_mode'],
                  traffic_light)
    log("WARNING", f"{text_colors.UNDERLINE}exiting the utility{text_colors.END}.\n")
    fps.stop()
    if show_mode:
        cv2.destroyAllWindows()
    if not input_file:
        stream.stop()
    else:
        stream.release()
    log("INFO", f"Elapsed time: {text_colors.GREEN}{round(fps.elapsed(), 2)}"\
                f"{text_colors.END}")
    log("INFO", f"Approximate FPS: {text_colors.GREEN}{round(fps.fps(), 2)}"\
                f"{text_colors.END}")

if __name__ == "__main__":
    sys.exit(main())
