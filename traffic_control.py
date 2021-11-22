#!/usr/bin/env python3

import os
import sys
import cv2
import time
import argparse
from imutils.video import FPS
from imutils.video import VideoStream

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

RUNNING_ON_RPI = False
os_info = os.uname()
if os_info[4][:3] == 'arm':
    RUNNING_ON_RPI = True

W = None
H = None
log_level = None

log_levels = {
                'CRITICAL' : 4,
                'ERROR' : 3,
                'WARNING' : 2,
                'INFO' : 1,
                'DEBUG' : 0
             }

def predict(frame, net, confidence):
    '''
    Prepare input blob and perform an inference
    '''
    w = h = 512
    blob = cv2.dnn.blobFromImage(frame,
                                 size = (w, h),
                                 ddepth=cv2.CV_8U)
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

def print_label(label, image_for_result, x_min, x_max, y_min, y_max, pred_conf):
        x_min = int(x_min * W)
        y_min = int(y_min * H)
        x_max = int(x_max * W)
        y_max = int(y_max * H)
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

def load_model():
    MODEL_NAME = "person-vehicle-bike-detection-crossroad-1016"
    MODEL_PATH = "/opt/intel/openvino_2021/deployment_tools/open_model_zoo/tools/downloader/intel"
    MODEL_PATH = "./models"
    GRAPH_FILENAME = MODEL_PATH + "/" + MODEL_NAME + "/FP32/"
    GRAPH_XML = GRAPH_FILENAME + MODEL_NAME + ".xml"
    GRAPH_BIN = GRAPH_FILENAME + MODEL_NAME + ".bin"
    net = cv2.dnn.readNet(GRAPH_XML, GRAPH_BIN)
    return net

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
                    help = "Path to optional input video file.")
    ap.add_argument("-o", "--output",
                    type = str,
                    help = "Path to optional output video file.")
    args = vars(ap.parse_args())
    return args

def main():
    global W, H, log_level
    args = parse_arguments()
    log_level = args['debug']
    if not cv2.useOptimized():
        cv2.setUseOptimized(True)
    writer = None
    net = load_model()
    net.setPreferableTarget(cv2.dnn.DNN_TARGET_CPU)
    if not args.get("input", False):
        log("WARNING", "starting video stream.")
        vs = VideoStream(src = 0).start()
    else:
        log("WARNING", "opening video file.")
        vs = cv2.VideoCapture(args["input"])
    fps = FPS().start()
    while True:
        try:
            frame = vs.read()
            frame = frame[1] if args.get("input", False) else frame
            H, W, _ = frame.shape
            image_for_result = frame.copy()
            if args["output"] is not None and writer is None:
                    fourcc = cv2.VideoWriter_fourcc(*"MJPG")
                    writer = cv2.VideoWriter(args["output"], fourcc, 30,
                            (frame.shape[1], frame.shape[0]), True)
            predictions = predict(frame, net, args['confidence'])
            for (i, pred) in enumerate(predictions):
                label, pred_conf, pred_boxpts = pred
                ((x_min, y_min), (x_max, y_max)) = pred_boxpts
                log("DEBUG", "Prediction #%s: confidence: %s, boxpoints: %s" %\
                             (i, pred_conf, pred_boxpts))
                if pred_conf > args["confidence"]:
                    log("DEBUG", "Prediction #%s: confidence: %s, boxpoint: %s" %\
                                (i, pred_conf, pred_boxpts))
                    if args["show"] > 0:
                        print_label(label,
                                    image_for_result,
                                    x_min,
                                    x_max,
                                    y_min,
                                    y_max,
                                    pred_conf)
            if writer is not None:
                    writer.write(image_for_result)
            if args["show"] > 0:
                cv2.imshow("Output", image_for_result)
                key = cv2.waitKey(1) & 0xFF
                if key == ord("q"):
                    break
            fps.update()
        except KeyboardInterrupt:
            break
        except AttributeError:
            break
    fps.stop()
    if args["show"] > 0:
        cv2.destroyAllWindows()
    if not args.get("input", False):
        vs.stop()
    else:
        vs.release()
    log("INFO", "Elapsed time: {:.2f}".format(fps.elapsed()))
    log("INFO", "Approximate FPS: {:.2f}".format(fps.fps()))

if __name__ == "__main__":
    sys.exit(main())
