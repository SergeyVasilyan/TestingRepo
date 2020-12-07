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
            new_pass = input("Enter new password: ")
            self.set_password(new_pass)
            return
        while True:
            new_password = input("Enter new password: ")
            if len(new_password) >= 8:
                 user.set_password(new_password)
                 return
            else:
                print("Password must contain at least 8 characters,\nPlease try again.")
                continue

class Employee(data_user):

    def change_password(self, user = None):
        if user == None:
            new_pass = input("Enter new password: ")
            self.set_password(new_pass)
            return
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

    def change_password(self,object_of_class=None,type=None):
        pass
#       while True:
#           if not  object_of_class == None:
#               self=object_of_class
#               if type == 'guest':
#                   password = input ("Please, input your password ")
#               if password == object_of_class.get_password():
#                   new_password = input("Enter new password ")
#                   if len(new_password) >= 8:
#                        object_of_class.set_password(new_password)
#                        break
#                   else:
#                       print("Password must contain at least 8 characters ,please try again.")
#                       continue
#               else:
#                   print ("You input wrong password.")
#                   continue
#           else:
#               print("Guest cannot change admin and employee password ")
#               break 

