#! /usr/bin/python3

# SPLIT FUNCTION NAMES WITH '_' CHARS
# WRONG CONCEPT OF DICT
# MAIN LOGIC IS RIGTH BUT WILL NOT WORK.

import re
import role_class
users=[[],[],[]]
def register():
    regex = '^[a-z0-9]+[\._]?[a-z0-9]+[@]\w+[.]\w{2,3}$'
    list=["admin","employee","guest"]
    dict= {}
    while True:
        username = input("New username: ")
        if not len(username) == 0:  # if len(username) == 0:+
            print("Username can't be blank")
            continue
        else:
            break
    while True:
        password = input("New password: ")
        if not len(password) == 0:  # Same here.
            print("Password can't be blank")
            continue
        else:
            break
    while True:
        email = input("Enter email: ") 
        if not(re.search(regax,email)): #???
            print("Invalid email")
        else:
            break
    while True:
        role = input("Enter role: ")
        if role not in list: # You can only use this as blank role is not in the list.+
            print("There is no such role")
            continue
        else:
            break
    if role == "admin":
        user = role_class.Admin(username, password, email)
        users[0].append(user)
    elif role == "employee":
        user = role_class.Employee(username, password, email) }
        users[1].append(user)
    else:
        user = role_class.Guest(username, password, email) }
        users[2].append(user)

    print("Account has been created")

def chenge_name_or_passwd(data_str, char):

    found = False
    if char == 'name'
        for user in users:
            if user.get_name() == data_str:
                found = True
                return False
        if not found:
            print("User with name {} not found".format(username))
            print("Please,enter valid username ")
            return True
    else:
        for user in users:
            if user.get_password() == data_str:
                found = True
                return False
        if not found:
            print("Please,enter valid password ")
            return True
def login():
    while True:
        username = input("Username: ")
        if not len(username) == 0:
            if chenge_name_or_passwd(username,'name') == False
    while True:
        password = input("Password: ")
        if not len(password) ==  0:
            if chenge_name_or_passwd(password,'psw') == False

    print("Welcom in system")
    return in_system(username) #this function has not been written yet


def in_system(username):



def main():
    count = 5
    while count != 0: # You can only check for count, as when count equals to 0, it will automatically break the loop.
        register()
        count -= 1
    while True 
        print("Sign in system")
        if login() == False
            break

main()
