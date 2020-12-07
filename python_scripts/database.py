#! /usr/bin/python3

import re
import role_class

users=[[],[],[]]

def register():
    regax = '^[a-z0-9]+[\._]?[a-z0-9]+[@]\w+[.]\w{2,3}$'
    role_list = ["admin", "employee", "guest"]
    while True:
        username = input("New username: ")
        if  len(username) != 0:
            break
        else:
            print("Username can't be blank.")
            continue
    while True:
        password = input("New password: ")
        if len(password) != 0:
            break
        else:
            print("Password can't be blank.")
            continue
    while True:
        email = input("Enter email: ")
        if re.search(regax, email):
            break
        else:
            print("Invalid email.")
    while True:
        role = input("Enter role: ")
        if role in role_list:
            break
        else:
            print("There is no such role")
            continue
    if role == "admin":
        user = role_class.Admin(username, password, email, role)
        users[0].append(user)
    elif role == "employee":
        user = role_class.Employee(username, password, email, role)
        users[1].append(user)
    else:
        user = role_class.Guest(username, password, email, role)
        users[2].append(user)
    print("Account has been created.\n")

def change_name_or_passwd(data, flag):
    found = False
    for group in users:
        for user in group:
            if flag == 'name' and user.get_name() == data:
                found = True
                return found
            else:
                if user.get_password() == data:
                    found = True
                    return found
    if not found:
        if flag == 'name':
            print("User with name {} does not found.".format(username))
            print("Please, re-enter valid username.")
        else:
            print("Wrong password.")
            print("Please, re-enter.")
    return found

def login():
    while True:
        username = input("Username: ")
        if (not len(username) == 0) and change_name_or_passwd(username, 'name'):
            break
    while True:
        password = input("Password: ")
        if (not len(password) == 0) and change_name_or_passwd(password, 'passwd'):
            break
    return username

def output_object_of_class(username):
    for group in users:
        for user in group:
           if user.get_name() == username:
               return user
    return None

def in_system():
    username = login()
    print("Welcome to the system")
    while True:
        print("Options: change password | logout.")
        option = str(input("Enter option: "))
        if option == "change password":
            user = output_object_of_class(username)
            if user != None:
                slave = input("Enter the username of a user whose password you want to change: ")
                slave = output_object_of_class(slave)
                if slave != None:
                    if slave.get_name() == user.get_name():
                        user.change_password()
                    else:
                        user.change_password(slave)
                    continue
                else:
                    print("User not found.\nTry again.\n")
                    continue
        elif option == "logout":
            print("Logging out.")
            break
        else:
            print ("Invalid option.")
            continue

def main():
    count = 2
    while count != 0:
        register()
        count -= 1
    while True:
        print("Sign in into system.")
        in_system()
        answer = input("Sign in into another user? (Yes/no):")
        yes_answers = ["y", "Y", "yes", "Yes", ""]
        if answer not in yes_answers:
            break

main()
print(users)
