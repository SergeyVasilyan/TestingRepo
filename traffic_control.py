#!/usr/bin/env python3

import os
import sys
import cv2
import time
import argparse
from imutils.video import FPS
from imutils.video import VideoStream

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

log_level = None
log_levels = {
                'CRITICAL' : 4,
                'ERROR' : 3,
                'WARNING' : 2,
                'INFO' : 1,
                'DEBUG' : 0
             }

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

def predict(frame, net, confidence):
    '''
    Prepare input blob and perform an inference
    '''
    input_width = 512
    input_height = 512
    blob = cv2.dnn.blobFromImage(frame,
                                 size = (input_width,
                                         input_height),
                                 ddepth = cv2.CV_8U)
    net.setInput(blob)
    out = net.forward()
    predictions = []
    # The net outputs a blob with the shape: [1, 1, N, 7], where N is the number of detected bounding boxes.
    # For each detection, the description has the format: [image_id, label, conf, x_min, y_min, x_max, y_max]
    for detection in out.reshape(-1, 7):
        image_id, label, conf, x_min, y_min, x_max, y_max = detection
        if conf > confidence:
            pred_boxpts = ((x_min, y_min), (x_max, y_max))
            prediction = (label, conf, pred_boxpts)
            predictions.append(prediction)
    return predictions

def print_label(label, image_for_result, x, y, frame_shape, pred_conf):
        height = frame_shape[0]
        width = frame_shape[1]
        x_min = int(x[0] * width)
        y_min = int(y[0] * height)
        x_max = int(x[1] * width)
        y_max = int(y[1] * height)
        offset = 15
        y = y_min - offset if y_min - offset > offset else y_min + offset
        if label == 0:
            label = "Bike"
            color = (255, 0, 0)
        elif label == 1.0:
            label = "Car"
            color = (0, 0, 255)
        elif label == 2.0:
            label = "Person"
            color = (0, 255, 0)
        else:
            label = "Other"
            color = (0, 255, 0)
        label += ": {:.2f}%".format(pred_conf * 100)
        cv2.rectangle(image_for_result,
                      (x_min, y_min),
                      (x_max, y_max),
                      color,
                      2)
        cv2.putText(image_for_result,
                    label,
                    (x_min, y),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    1,
                    color,
                    2)

def start_process(args, net, vs, show_flag, input_file, fps):
    writer = None
    confidence = args['confidence']
    output_flag = args['output']
    while True:
        try:
            frame = vs.read()
            frame = frame[1] if input_file else frame
            frame_height, frame_width, _ = frame.shape
            image_for_result = frame.copy()
            if output_flag and isinstance(writer, type(None)):
                fourcc = cv2.VideoWriter_fourcc(*"mp4v")
                writer = cv2.VideoWriter("Output.mp4",
                                         fourcc,
                                         30,
                                         (frame.shape[1],
                                          frame.shape[0]),
                                         True)
            predictions = predict(frame, net, confidence)
            for i, pred in enumerate(predictions):
                label, pred_conf, pred_boxpts = pred
                ((x_min, y_min), (x_max, y_max)) = pred_boxpts
                log("DEBUG", "Prediction #%s: confidence: %s, boxpoints: %s" %\
                             (i, pred_conf, pred_boxpts))
                if pred_conf > confidence:
                    log("DEBUG", "Prediction #%s: confidence: %s, boxpoint: %s" %\
                                 (i, pred_conf, pred_boxpts))
                    if show_flag:
                        print_label(label,
                                    image_for_result,
                                    (x_min, x_max),
                                    (y_min, y_max),
                                    (frame_height, frame_width),
                                    pred_conf)
            if not isinstance(writer, type(None)):
                writer.write(image_for_result)
            if show_flag:
                cv2.imshow("Output", image_for_result)
                key = cv2.waitKey(1) & 0xFF
                if key == ord("q"):
                    break
            fps.update()
        except KeyboardInterrupt:
            break
        except AttributeError:
            break

def load_model():
    MODEL_NAME = "person-vehicle-bike-detection-crossroad-1016"
    MODEL_PATH = "/opt/intel/openvino_2021/deployment_tools/open_model_zoo/tools/downloader/intel"
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
        log("WARNING", "starting video stream.")
        return VideoStream(src = 6).start()
    log("WARNING", "opening video file.")
    return cv2.VideoCapture(input_file)

def parse_arguments():
    ap = argparse.ArgumentParser()
    ap.add_argument("-c", "--confidence",
                    default = .5,
                    help = "Confidence threshold value. Default is '0.5'.")
    ap.add_argument("-s", "--show",
                    type = int,
                    default = 0,
                    help = "Switch to display image on screen. Default is set 0 aka no-display mode.")
    ap.add_argument("-d", "--debug",
                    type = int,
                    default = 1,
                    help = "Log message level. Default is set to 1, i.e. no 'DEBUG' level.")
    ap.add_argument("-i", "--input",
                    type = str,
                    default = "",
                    help = "Path to optional input video file.")
    ap.add_argument("-o", "--output",
                    type = str,
                    default = 0,
                    help = "Path to optional output video file.")
    args = vars(ap.parse_args())
    return args

def main():
    global log_level
    args = parse_arguments()
    show_flag = args['show']
    log_level = args['debug']
    input_file = args['input']
    check_optimization()
    net = load_model()
    vs = get_input(input_file)
    fps = FPS().start()
    start_process(args, net, vs, show_flag, input_file, fps)
    fps.stop()
    if show_flag:
        cv2.destroyAllWindows()
    if not input_file:
        vs.stop()
    else:
        vs.release()
    log("INFO", "Elapsed time: {:.2f}".format(fps.elapsed()))
    log("INFO", "Approximate FPS: {:.2f}".format(fps.fps()))

if __name__ == "__main__":
    sys.exit(main())
