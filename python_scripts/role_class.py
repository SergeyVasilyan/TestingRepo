#! /usr/bin/python3

class data_user:
    def __init__(self, name, password, email):
        self.__name = name
        self.__password = password
        self.__email = email

    def set_name(self,name):
        self.__name=name

    def get_name(self):
        return self.__name

    def __set_password(self,password):
        self.__password=password

    def get_password(self):
        return self.__password

    def set_email(self,email):
        self.__email=email

    def get_email(self):
        return self.__email

    def change_password(self):
        pass

class Admin(data_user):
    def change_password(self,type): 
        while True:
            if type == Admin:
                password = input ("Please, input your password ")
                if password == self.get_password():
                     new_password = input("Enter new password ")
                    if len(new_password) >= 8
                         self.__set_password(new_password)
                         break
                    else:
                        print("Password must contain at least 8 characters ,please try again.")
                         continue
                else:
                    print ("You input wrong password.")
                    continue
             else:
                 print ("Employee eb Guest cannot change the Admin password")       



class Employee(data_user):

    def change_password(self,type):
        while True:
            if type == "employee" and type ==  "admin":
                password = input ("Please, input your password ")
                if password == self.get_password():
                    new_password = input("Enter new password ")
                    if len(new_password) >= 8
                         self.__set_password(new_password)
                         break
                    else:
                        print("Password must contain at least 8 characters ,please try again.")
                        continue
                else:
                    print ("You input wrong password.")
                    continue
            else:
                print("Guest cannot change the  Employee password!")
                break       



class Guest(data_user):
 
    def change_password(self,type):
        while True:
            password = input ("Please, input your password ")
            if password == self.get_password():
                new_password = input("Enter new password ")
                if len(new_password) >= 8
                     self.__set_password(new_password)
                     break
                else:
                    print("Password must contain at least 8 characters ,please try again.")
                    continue
            else:
                print ("You input wrong password.")
                continue

