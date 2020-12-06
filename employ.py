#!/usr/bin/python3
from abc import ABC, abstractmethod
#Employ class
class Employ(ABC):
    name=""
    email=""
    salary=0
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
    #This method is abstract. It is get salary.
    @abstractmethod
    def get_salary(self):
        pass
    #This is abstract method. It is set new salary.
    @abstractmethod
    def set_salary(self,new_salary):
        pass

#User class which inherits Employ class.        
class User(Employ):
    password=""
    #This is constructor of user class.
    def __init__(self,name,email,password):
        self.name=name
        self.email=email
        self.password=password
    #This function get password.
    def __get_password(self):
        return self.password
    #This function set new password.
    def __set_password(self, new_pass):
        self.password=new_pass
    def get_salary(self):
        pass
    def set_salary(self):
        pass
    #This function is change user password after checking available password!
    #Function has 3 local variables(password,new_passw and rep_passw) for checking.
    def change_acsses_info(self):
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
                        print("Invalid password changing!")
                        return
            else:
                print("You enter wrong password! You have {} chance to enter your password!" .format(3-i))

#Admin class which inherits User class. 
class Admin(User):
    def __init__(self,name,email,password,salary):
        self.name=name
        self.email=email
        self.password=password
        self.salary=salary
    def get_salary(self):
        return self.salary
    def set_salary(self,new_salary):
        self.salary=new_salary
    def __get_password(self):
        return self.password
    def __set_password(self,new_password):
        self.password=new_password

    def add_user(self,list_of_users):
        name=input("Name: ")
        email=input("email")
        password=input("password")
        new_user=User(name,email,password)
        list_of_users[name]=email
#This is a main function which organize our program!
def main():
    luser=User("popk","pnduk@yahoo.kyanq","1010botas")
    user=Admin("vazgen", "khkf@jam.com", "1234",45000)
    print(user.get_name())
    user.change_acsses_info() 
    users_list={}
    user.add_user(users_list)
    for i in users_list:
        print("User name: {} and email: {}" .format(i,users_list[i]))
main()
