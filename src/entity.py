#!/usr/bin/env python3

class centerPoint:

    def __init__(self, x = None, y = None):
        self.__x = x
        self.__y = y

    def x(self):
        return self.__x

    def y(self):
        return self.__y

    def set_x(self, new_x):
        if self.__x != new_x:
            self.__x = new_x

    def set_y(self, new_y):
        if self.__y != new_y:
            self.__y = new_y

class entity:

    def __init__(self):
        self.__id = None
        self.__center_point = centerPoint()
        self.__type = ""
        self.__confidence = 100
        self.__bounding_box = None
        self.__direction = ""

    def get_id(self):
        return self.__id

    def get_center_point(self):
        return self.__center_point

    def get_type(self):
        return self.__type

    def get_confidence(self):
        return self.__confidence

    def get_bounding_box(self):
        return self.__bounding_box

    def get_direction(self):
        return self.__direction

    def set_id(self, new_id):
        if self.__id != new_id:
            self.__id = new_id

    def set_center_point(self, new_x, new_y):
        if self.__center_point.x() != new_x and self.__center_point.y() != new_y:
            self.__center_point = centerPoint(new_x, new_y)

    def set_type(self, new_type):
        if self.__type != new_type:
            self.__type = new_type

    def set_confidence(self, new_confidence):
        if self.__confidence != new_confidence:
            self.__confidence = new_confidence

    def set_bounding_box(self, new_bounding_box):
        if self.__bounding_box != new_bounding_box:
            self.__bounding_box = new_bounding_box

    def set_direction(self, new_direction):
        if self.__direction != new_direction:
            self.__direction = new_direction

    def reset(self):
        self.__id = None
        self.__center_point = centerPoint()
        self.__type = ""
        self.__confidence = 100
        self.__bounding_box = None
        self.__direction = ""
