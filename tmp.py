#!/usr/bin/python3

class Human:
    def __init__(self,name,weight,hight,age):
        self.name=name
        self.weight=weight
        self.hight=hight
        self.age=age
    def get_name(self):
        print("Name is: {}." .format(self.name))
    def get_weight(self):
        print("Weight is: {}." .format(self.weight))
    def get_hight(self):
        print("Hight is: {}." .format(self.hight))
    def get_age(self):
        print("Age is: {}." .format(self.age))
class Men(Human):
    pass
class Woman(Human):
    def __init__(self,name,weight,hight,age):
        self.name=name
        self.height=weight
        self.hight=hight
        self.__age=age
    def get_age(self):
        print("You are gentleman or what?") 
    
man=Men("Vazgen",56,170,24)
man.get_age()
woman=Woman("Ani",48,168,23)
woman.get_name()
