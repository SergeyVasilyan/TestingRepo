'''
Custom module that contains entity related information.
'''

class centerPoint:
    '''
    Custom center point class.
    '''

    def __init__(self, x = None, y = None):
        self.__x = x
        self.__y = y

    def x(self):
        '''
        Functionality that returns x coordinate of the center point.
        '''
        return self.__x

    def y(self):
        '''
        Functionality that returns y coordinate of the center point.
        '''
        return self.__y

    def set_x(self, new_x):
        '''
        Functionality that sets x coordinate of the center point.
        '''
        if self.__x != new_x:
            self.__x = new_x

    def set_y(self, new_y):
        '''
        Functionality that sets y coordinate of the center point.
        '''
        if self.__y != new_y:
            self.__y = new_y

class entity:
    '''
    Custom entity class which will hold detection object related information.
    '''

    def __init__(self):
        self.__id = None
        self.__center_point = centerPoint()
        self.__type = ""
        self.__confidence = 100
        self.__bounding_box = None
        self.__direction = ""

    def get_id(self):
        '''
        Functionality that returns entity id member.
        '''
        return self.__id

    def get_center_point(self):
        '''
        Functionality that returns entity center point member.
        '''
        return self.__center_point

    def get_type(self):
        '''
        Functionality that returns entity type member.
        '''
        return self.__type

    def get_confidence(self):
        '''
        Functionality that returns entity confidence member.
        '''
        return self.__confidence

    def get_bounding_box(self):
        '''
        Functionality that returns entity bounding box member.
        '''
        return self.__bounding_box

    def get_direction(self):
        '''
        Functionality that returns entity direction member.
        '''
        return self.__direction

    def set_id(self, new_id):
        '''
        Functionality that sets entity id member.
        First argument - new value.
        '''
        if self.__id != new_id:
            self.__id = new_id

    def set_center_point(self, new_x, new_y):
        '''
        Functionality that sets entity center point member.
        First argument - new value.
        '''
        if self.__center_point.x() != new_x and self.__center_point.y() != new_y:
            self.__center_point = centerPoint(new_x, new_y)

    def set_type(self, new_type):
        '''
        Functionality that sets entity type member.
        First argument - new value.
        '''
        if self.__type != new_type:
            self.__type = new_type

    def set_confidence(self, new_confidence):
        '''
        Functionality that sets entity confidence member.
        First argument - new value.
        '''
        if self.__confidence != new_confidence:
            self.__confidence = new_confidence

    def set_bounding_box(self, new_bounding_box):
        '''
        Functionality that sets entity bounding box member.
        First argument - new value.
        '''
        if self.__bounding_box != new_bounding_box:
            self.__bounding_box = new_bounding_box

    def set_direction(self, new_direction):
        '''
        Functionality that sets entity direction member.
        First argument - new value.
        '''
        if self.__direction != new_direction:
            self.__direction = new_direction

    def reset(self):
        '''
        Functionality that resets entity all member.
        First argument - new value.
        '''
        self.__id = None
        self.__center_point = centerPoint()
        self.__type = ""
        self.__confidence = 100
        self.__bounding_box = None
        self.__direction = ""
