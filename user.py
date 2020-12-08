#!/usr/bin/python3
from abc import ABC, abstractmethod
#User class
class User(ABC):
    name=""
    email=""
    password=""
    #This is constructor of user class.
    def __init__(self,name,email,password):
        self.name=name
        self.email=email
        self.password=password
    #This method get name.
    def get_name(self):
        return self.name
    #This method set new name.
    def set_name(self,new_name):
        self.name=new_name
    #This method get available email.
    def get_email(self):
        return self.email
    #This method set new email address.
    def set_email(self,new_email):
        self.email=new_email
    #this method get password.
    def __get_password(self):
        return self.password
    #This method set new password.
    def __set_password(self, new_password):
        self.password=new_password
    #This method check password.
    def check_password(self,password):
        if password==self.__get_password():
            return True
        return False
    #This function is change user password after checking available password!
    #Function has 3 local variables(password,new_passw and rep_passw) for checking.
    def change_password(self):
        for i in range(1,4):
            password=input("Please input your password: ")
            if password==self.__get_password():
                while True:
                    try:
                        new_passw=input("Enter new password: ")
                        rep_passw=input("Repeat your new password: ")
                        if new_passw==rep_passw:
                            self.__set_password(new_passw)
                            return
                        else:
                            print("Invalid repeat of new password please try again!")
                    except KeyboardInterrupt:
                        print("\n Invalid password changing!")
                        return
            else:
                print("You enter wrong password! You have {} chance to enter your password!" .format(3-i))
    #This method change name of user.
    def change_name(self):
        while True:
            try:
                answer=input("Do you want change your name?[y/n] ")
                if answer=="n":
                    print("You didn't change your name.")
                    return
                elif answer=="y":
                    new_name=input("Please enter new name: ")
                    self.set_name(new_name)
                    return
                else:
                    print("Invalid answer. Please try again.")
                    continue
            except KeyboardInterrupt:
                print("\n Closing changing window.")
                break
    #This method change email of user.
    def change_email(self):
        while True:
            try:
                answer=input("Do you want change your email?[y/n] ")
                if answer=="n":
                    print("You didn't change your email.")
                    return
                elif answer=="y":
                    new_email=input("Please enter new email: ")
                    self.set_email(new_email)
                    return
                else:
                    print("Invalid answer. Please try again.")
                    continue
            except KeyboardInterrupt:
                print("\n Closing changing window.")
                break


#Guest class which inherits User class.        
class Guest(User):
   
    #This function get password.
    def __get_password(self):
        return self.password
    #This function set new password.
    def __set_password(self, new_pass):
        self.password=new_pass
    def get_type(self):
        return "Guest"
#Employers class which inherits User class.
class Employers(User):
    salary=0
     #This is constructor of user class.
    def __init__(self,name,email,password,salary):
        self.name=name
        self.email=email
        self.password=password
        self.salary=salary
    #This function get password.
    def __get_password(self):
        return self.password
    #This function set new password.
    def __set_password(self, new_pass):
        self.password=new_pass
    def get_salary(self):
        return self.salary
    def set_salary(self,new_salary):
        self.salary=new_salary
    def get_type(self):
        return "Employers"
    #This method change name of employers or another user if it to get parameter.
    def change_guest_name(self,guest=None):
        if guest.type()==Guest.__name__:
            while True:
                try:
                    new_name=input("Input new name of guest: ")
                    guest.set_name(new_name)
                    return
                except KeyboardInterrupt:
                    print("\n Closing this task")
        elif guest.type()=="Guest":
            new_name=input("Input new guest name: ")
            guest.set_name(new_name)
            print("Name was changed.")
    #This method change password of employers or another user if it to get parameter.
    def change_password(self,guest=None):
        if guest==None:
            for i in range(1,4):
                password=input("Please input your password: ")
                if password==self.__get_password():
                    while True:
                        try:
                            new_passw=input("Enter new password: ")
                            rep_passw=input("Repeat your new password: ")
                            if new_passw==rep_passw:
                                self.__set_password(new_passw)
                                return
                            else:
                                print("Invalid repeat of new password please try again!")
                        except KeyboardInterrupt:
                            print("\n Invalid password changing!")
                            return
                else:
                    print("You enter wrong password! You have {} chance to enter your password!" .format(3-i))
        elif guest.type()=="Guest":
            new_password=input("Input new password for guest: ")
            guest.password=new_password
            print("Guest password is changed")
    #This method change email of employers or another user if it to get parameter.
    def change_email(self,guest=None):
        if guest==None:
            while True:
                try:
                    answer=input("Do you want change your email?[y/n] ")
                    if answer=="n":
                        print("You didn't change your email.")
                        return
                    elif answer=="y":
                        new_email=input("Please enter new email: ")
                        self.set_email(new_email)
                        return
                    else:
                        print("Invalid answer. Please try again.")
                        continue
                except KeyboardInterrupt:
                    print("\n Closing changing window.")
                    break
        elif guest.type()=="Guest":
            new_email=input("Enter new email: ")
            guest.set_email(new_email)


#Admin class which inherits User class. 
class Admin(User):
    def __init__(self,name,email,password,salary):
        self.name=name
        self.email=email
        self.password=password
        self.salary=salary
    def __get_password(self):
        return self.password
    def __set_password(self,new_password):
        self.password=new_password
    def get_type(self):
        return "Admin"
    def get_salary(self):
        return salary
    def get_salary(self, new_salary):
        self.salary=salary
    #This method change password of admin or another user if it to get parameter.
    def change_password(self,guest=None):
        if guest==None:
            for i in range(1,4):
                password=input("Please input your password: ")
                if password==self.__get_password():
                    while True:
                        try:
                            new_passw=input("Enter new password: ")
                            rep_passw=input("Repeat your new password: ")
                            if new_passw==rep_passw:
                                self.__set_password(new_passw)
                                return
                            else:
                                print("Invalid repeat of new password please try again!")
                        except KeyboardInterrupt:
                            print("\n Invalid password changing!")
                            return
                else:
                    print("You enter wrong password! You have {} chance to enter your password!" .format(3-i))
        elif guest.type()=="Guest" or guest.type()=="Employers":
            new_password=input("Input new password for guest: ")
            guest.password=new_password
            print("Guest password is changed")
    
    #This method change name of admin and another user if it to get parameter.
    def change_guest_name(self,guest=None):
        if guest.type()==Guest.__name__:
            while True:
                try:
                    new_name=input("Input new name of guest: ")
                    guest.set_name(new_name)
                    return
                except KeyboardInterrupt:
                    print("\n Closing this task")
        elif guest.type()=="Guest" or guest.type()=="Employers":
            new_name=input("Input new guest name: ")
            guest.set_name(new_name)
            print("Name was changed.")
    #This method change email of admin and another user if it to get parameter.
    def change_email(self,guest=None):
        if guest==None:
            while True:
                try:
                    answer=input("Do you want change your email?[y/n] ")
                    if answer=="n":
                        print("You didn't change your email.")
                        return
                    elif answer=="y":
                        new_email=input("Please enter new email: ")
                        self.set_email(new_email)
                        return
                    else:
                        print("Invalid answer. Please try again.")
                        continue
                except KeyboardInterrupt:
                    print("\n Closing changing window.")
                    break
        elif guest.type()=="Guest" or guest.type()=="Employers":
            new_email=input("Enter new email: ")
            guest.set_email(new_email)
#This function inputs 5 users.
def user_input(users_list):
    print("Please input 5 users.")
    count_of_steps=0     
    while count_of_steps<5:
        try:
            user_role=input("Input user role")
            if user_role=="guest" or user_role=="Guest":
                user_name=input("Input user name: ")
                user_email=input("Input user email: ")
                user_password=input("Input user password: ")
                user=Guest(user_name,user_email,user_password)
                users_list["Guest"].append(user)
            elif user_role=="Employers" or user_role=="employers":
                employer_name=input("Input user name: ")
                employer_email=input("Input user email: ")
                employer_password=input("Input user password: ")
                employer_salary=input("Input employer salary: ")
                employer=Employers(employer_name,employer_email,employer_password,employer_salary)
                users_list["Employers"].append(employer)
            elif user_role=="Admin" or user_role=="admin":
                admin_name=input("Input user name: ")
                admin_email=input("Input user email: ")
                admin_password=input("Input user password: ")
                admin_salary=input("Input user salary: ")
                admin=Admin(admin_name,admin_email,admin_password,admin_salary)
                users_list["Admin"].append(admin)
            else:
                print("Invalid role input")
                continue
            count_of_steps+=1
        except KeyboardInterrupt:
            print("\n Closing user input!")
            return
#This function calls corresponding method of object. 
def action(users_list,user):
    while True:
        try:
            print("Welcome {}! Your role is {}" .format(user.get_name(),user.get_type()))
            answer=input("Do you want do some action? [y/n] ")
            if answer=="y":
                if user.get_type()=="Guest":
                    action=input("Input action: ")
                    if action=="change email":
                        user.change_email()
                    elif action=="change name":
                        user.change_name()
                    elif action=="change password":
                        user.change_password()
                    else:
                        print("Invalid action")
                elif user.get_type()=="Employers":
                    action=input("Input action: ")
                    if action=="change email":
                        user.change_email()
                    elif action=="change name":
                        user.change_name()
                    elif action=="change password":
                        user.change_password()
                    elif action=="change guest name":
                        guest_name=input("Input guest name: ")
                        if guest_name in users_list["Guest"]:
                            user.change_name(guest_name)
                    elif action=="change guest email":
                        guest_name=input("Input guest name: ")
                        if guest_name in users_list["Guest"]:
                            user.change_email(guest_name)
                    elif action=="change guest password":
                        guest_name=input("Input guest name: ")
                        if guest_name in users_list["Guest"]:
                            user.change_passwored(guest_name)
                    else:
                        print("Invalid action")
                elif user.get_type()=="Admin":
                    action=input("Input action: ")
                    if action=="change email":
                        user.change_email()
                    elif action=="change name":
                        user.change_name()
                    elif action=="change password":
                        user.change_password()
                    elif action=="change guest name":
                        guest_name=input("Input guest name: ")
                        if guest_name in users_list["Guest"] or guest_name in users_list["Employers"]:
                            user.change_name(guest_name)
                    elif action=="change guest email":
                        guest_name=input("Input guest name: ")
                        if guest_name in users_list["Guest"] or guest_name in users_list["Employers"]:
                            user.change_email(guest_name)
                    elif action=="change guest password":
                        guest_name=input("Input guest name: ")
                        if guest_name in users_list["Guest"] or guest_name in users_list["Employers"]:
                            user.change_passwored(guest_name)
                    else:
                        print("Invalid action")
            else:
                return
        except KeyboardInterrupt:
            print("Exiting from action mode")
            break
        
#This function signs in user.
def sign_in(users_list):
    for count in range(1,4):
        try:
            email=input("Input your email: ")
            for role in users_list:
                for name in users_list[role]:
                    if email==name.get_email():
                        password=input("Input your password: ")
                        if name.check_password(password):
                            action(users_list,name)
                            return            
        except KeyboardInterrupt:
            print("Closing sign in window")
            return

#This is a main function which organize our program!
def main():
    users_list={
    "Guest": [],
    "Employers" :[],
    "Admin":[]
    }
    while True:
        try:
            user_input(users_list)
            if len(users_list["Guest"])==0 and len(users_list["Admin"])==0 and len(users_list["Employers"])==0:
                continue
            sign_in(users_list)
            input()
        except KeyboardInterrupt:
            print("\n Closing program!")
            break 
            
main()
