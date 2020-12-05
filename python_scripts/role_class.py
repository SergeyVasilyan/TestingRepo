#! /usr/bin/python3

class data_user:
    def __init__(self, name, password,email):
        self.__name = name
        self.__password = password
        self.__email = email

    def set_name(self,name):
        self.__name=name

    def get_name(self):
        return self.__name

    def __set_password(self,password):
        self.__password=password

    def __get_password(self):
        return self.__password

    def set_email(self,email):
        self.__email=email

    def get_email(self):
        return self.__email

    def change_password(self): #function is defective
        password = input ("Please, input your password ")
        if password == self.__get_password():
            new_password = input("Enter new password ")
            self.__set_password(new_password)
        else:
            print ("You input wrong password.")

class Admin(data_user):
    pass

class Employee(Admin):
    # def __init__(self):
    # super().__init__()
    pass
class Guest(Employee):
    pass
