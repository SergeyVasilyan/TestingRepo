#! /usr/bin/python3
 
class data_user:
    def __init__(self, name, password, email, role):
        self.__name = name
        self.__password = password
        self.__email = email
        self.__role = role

    def set_name(self, name):
        self.__name = name

    def get_name(self):
        return self.__name

    def set_password(self, password):
        self.__password = password

    def get_password(self):
        return self.__password

    def set_email(self, email):
        self.__email = email

    def get_email(self):
        return self.__email
 
    def set_role(self, role):
        self.__role = role

    def get_role(self):
        return self.__role

    def change_password(self, user):
        pass

class Admin(data_user):

    def change_password(self, user = None):
        if user == None:
            while True:
                new_pass = input("Enter new password: ")
                if len(new_pasis) >= 8:
                    self.set_password(new_pass)
                    return
                else:
                    print("Password must contain at least 8 characters,\nPlease try again.")
                    continue
        role = user.get_role()
        while role == "guest" or role == "employee" :
            new_password = input("Enter new password: ")
            if len(new_password) >= 8:
                user.set_password(new_password)
                return
            else:
                print("Password must contain at least 8 characters,\nPlease try again.")
                continue
        print("You can not change a password for a {} as it role is {}.".format(user.get_name(), user.get_role()))

class Employee(data_user):

    def change_password(self, user = None):
        if user == None:
            while True:
                new_pass = input("Enter new password: ")
                if len(new_pasis) >= 8:
                    self.set_password(new_pass)
                    return
                else:
                    print("Password must contain at least 8 characters,\nPlease try again.")
                    continue
        role = user.get_role()
        while role == "guest":
            new_password = input("Enter new password: ")
            if len(new_password) >= 8:
                user.set_password(new_password)
                return
            else:
                print("Password must contain at least 8 characters,\nPlease try again.")
                continue
        print("You can not change a password for a {} as it role is {}.".format(user.get_name(), user.get_role()))

class Guest(data_user):
    def change_password(self, user = None):
        if user == None:
            while True:
                new_pass = input("Enter new password: ")
                if len(new_pasis) >= 8:
                    user.set_password(new_pass)
                    return
                else:
                    print("Password must contain at least 8 characters,\nPlease try again.")
                    continue 
        print("You can not change a password for a {} as it role is {}.".format(user.get_name(), user.get_role()))

