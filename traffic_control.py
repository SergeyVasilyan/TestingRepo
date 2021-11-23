#!/usr/bin/env python3

import os
import sys
import cv2
import time
import copy
import numpy as np
from imutils.video import FPS
from imutils.video import VideoStream
from Xlib.display import Display
from src.config_parser import configParser
from src.entity import entity

RUNNING_ON_RPI = False
os_info = os.uname()
if os_info[4][:3] == 'arm':
    RUNNING_ON_RPI = True

class text_colors:
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

log_level = 1
log_levels = {
                'CRITICAL' : 4,
                'ERROR' : 3,
                'WARNING' : 2,
                'INFO' : 1,
                'DEBUG' : 0
             }

WINDOW_NAME = "Traffic Control."

def colorize_text(log_level):
    """
    Functionality that colorizes message log level.
    First argument - log level of the message.
    """
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
    """
    Functionality that validates all given arguments and outputs corresponding message.
    First argument - sub class of the message.
    Second argument - level of the message.
    Third argument - message body.
    """
    if log_levels[level.upper()] >= log_level:
        current_date = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        level = colorize_text(level)
        current_date = text_colors.HEADER + current_date + text_colors.END
        print("[%s] [%s]: %s" % (current_date, level, message))

def predict(frame, net, confidence, DB):
    '''
    Prepare input blob and perform an inference
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
                "Car" : 0,
                "Bike" : 0,
                "Person" : 0,
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

def draw_on_frame(image_for_result, DB):
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
        cv2.rectangle(image_for_result,
                      (x_min, y_min),
                      (x_max, y_max),
                      color,
                      2)
        cv2.putText(image_for_result,
                    label + direction,
                    (x_min, y),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.75,
                    color,
                    2)

def draw_counters(image_for_result, counters):
    x = 0
    y = 25
    step = 20
    for counter in counters:
        cv2.putText(image_for_result,
                    "%s: %s" % (counter, counters[counter]),
                    (x, y),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.75,
                    (0, 0, 0),
                    2)
        y += step

def get_screen_size():
    screen = Display(os.environ["DISPLAY"]).screen()
    screen_width, screen_height = screen.width_in_pixels, screen.height_in_pixels
    return screen_width, screen_height

def check_direction(previous_DB, DB):
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
                log("DEBUG", "DX : %s DY: %s" % (difference_x, difference_y))
                log("DEBUG", "NX : %s NY: %s" % (new_x, new_y))
                log("DEBUG", "PX : %s PY: %s" % (previous_x, previous_y))
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

def start_process(args, net, stream, fps, show_mode, input_file, fullscreen_mode, overlay_mode):
    writer = None
    confidence = args['confidence']
    output_file = args['output_file']
    if fullscreen_mode:
        screen_width, screen_height = get_screen_size()
    DB = []
    previous_DB = []
    while True:
        try:
            frame = stream.read()
            frame = frame[1] if input_file else frame
            image_for_result = frame.copy()
            if output_file and isinstance(writer, type(None)):
                fourcc = cv2.VideoWriter_fourcc(*"mp4v")
                writer = cv2.VideoWriter(output_file,
                                         fourcc,
                                         30,
                                         (frame.shape[1],
                                          frame.shape[0]),
                                         True)
            counters = predict(frame, net, confidence, DB)
            check_direction(previous_DB, DB)
            if show_mode and overlay_mode:
                draw_on_frame(image_for_result, DB)
                draw_counters(image_for_result, counters)
            previous_DB = copy.deepcopy(DB)
            if not isinstance(writer, type(None)):
                writer.write(image_for_result)
            if show_mode:
                if fullscreen_mode:
                    image_for_result = cv2.resize(image_for_result,
                                                  (screen_width, screen_height),
                                                  interpolation = cv2.INTER_AREA)
                cv2.imshow(WINDOW_NAME, image_for_result)
                key = cv2.waitKey(1) & 0xFF
                if key == ord("q"):
                    break
                if cv2.getWindowProperty(WINDOW_NAME, cv2.WND_PROP_ASPECT_RATIO) < 0:
                    break
            fps.update()
        except KeyboardInterrupt:
            break
        except AttributeError:
            break

def load_model():
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
    if not cv2.useOptimized():
        cv2.setUseOptimized(True)

def get_input(input_file):
    if not input_file:
        camera_index = 6
        log("WARNING", "starting video stream.")
        return VideoStream(src = camera_index).start()
    log("WARNING", "opening video file.")
    return cv2.VideoCapture(input_file)

def check_app_mode(fullscreen_mode):
    if not fullscreen_mode:
        cv2.namedWindow(WINDOW_NAME)
    else:
        cv2.namedWindow(WINDOW_NAME, cv2.WND_PROP_FULLSCREEN)
        cv2.setWindowProperty(WINDOW_NAME,cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)

def parse_arguments(cp):
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
    cp = configParser(log)
    args = parse_arguments(cp)
    show_mode = args['show_mode']
    input_file = args['input_file']
    fullscreen_mode = args['fullscreen_mode']
    check_optimization()
    check_app_mode(fullscreen_mode)
    net = load_model()
    stream = get_input(input_file)
    fps = FPS().start()
    start_process(args,
                  net,
                  stream,
                  fps,
                  show_mode,
                  input_file,
                  fullscreen_mode,
                  args['overlay_mode'])
    fps.stop()
    if show_mode:
        cv2.destroyAllWindows()
    if not input_file:
        stream.stop()
    else:
        stream.release()
    log("INFO", "Elapsed time: {:.2f}".format(fps.elapsed()))
    log("INFO", "Approximate FPS: {:.2f}".format(fps.fps()))

if __name__ == "__main__":
    sys.exit(main())
