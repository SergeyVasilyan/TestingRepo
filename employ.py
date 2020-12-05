#!/usr/bin/python3
#Employ class
class Employ:
    name=""
    password=""
    email=""
    salary=0     
#User class which inherits Employ class.        
class User(Employ):
    #This is constructor of user class.
    def __init__(self,name,password,email):
        self.name=name
        self.password=password
        self.email=email
    #This function get name of user.
    def get_name(self):
        return self.name
    #This function set new name.
    def set_name(self,new_name):
        self.name=new_name
    #This function get available email.
    def get_email(self):
        return self.email
    #This function set new email address.
    def set_email(self,new_email):
        self.email=new_email
    #This function get password.
    def __get_password(self):
        return self.password
    #This function set new password.
    def __set_password(self, new_pass):
        self.password=new_pass
    #This function is change user password after checking available password!
    #Function has 3 local variables(password,new_passw and rep_passw) for checking.
    def change_acsses_info(self):
        for i in range(1,4):
            password=input("Please input your password: ")
            if password==__get_password():
                while True:
                    try:
                        new_passw=input("Enter new password: ")
                        rep_passw=input("Repeat your new password: ")
                        if new_passw==rep_passw:
                            __set_password(new_passw)
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
    pass

#This is a main function which organize our program!
def main():
    user=User("vazgen", "khkfj", "jhdh@asd.com")
    print(user.get_email())

main()
