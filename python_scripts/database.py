#! /usr/bin/python3

# SPLIT FUNCTION NAMES WITH '_' CHARS
# WRONG CONCEPT OF DICT
# MAIN LOGIC IS RIGTH BUT WILL NOT WORK.

import role_class

users= {
    "user": "class_object"
       }

def register():
    list=["admin","employee","guest"]
    while True:
        username = input("New username: ")
        if not len(username) > 0:  # if len(username) == 0:
            print("Username can't be blank")
            continue
        else:
            break
    while True:
        password = input("New password: ")
        if not len(password) > 0:  # Same here.
            print("Password can't be blank")
            continue
        else:
            break
    while True:
        email = input("Enter email: ")
        if not len(email) > 0:  # Same here + check for '@' symbol existence, as it is a mail  -\_(O_O)_/-
            print("Email can't be blank")
            continue
        else:
            break
    while True:
        role = input("Enter role: ")
        if not len(role) > 0: # bla bla bla
            print("Role can't be blank")
            continue
        elif role not in list: # You can only use this as blank role is not in the list.
            print("There is no such role")
            continue
        else:
            break
    if role == "admin":
        users[username] = role_class.Admin(username, password, email) # Is this work properly?
    elif role == "employee":
        users[username] = role_class.Employee(username, password, email)
    else:
        users[username] = role_class.Guest(username, password, emai)

    print("Account has been created")

def login_auth(username, password):
    if username in users: #Is this work?
        if password == users[username].get_password: # Dict is not a List.
            print("Login successful")
            return True
    return False

def login():
    while True:
        username = input("Username: ")
        if not len(username) > 0: #bla bla bla + check for exitence imediately.
            print("Username can't be blank")
        else:
            break
    while True:
        password = input("Password: ")
        if not len(password) > 0: #bla bla bla
            print("Password can't be blank")
        else:
            break

    if login_auth(username, password):
        print("Welcome to your account " + username) # use 'format'.
        return in_system(username) #this function has not been written yet
    else:
        print("Invalid username or password")

def in_system(username):

# blaaaaaaaaaa

def main():
    count = 5
    while count != 0: # You can only check for count, as when count equals to 0, it will automatically break the loop.
        register()
        count -= 1
    while count != 5:
        print("Sign in system")
        login()
        count += 1

main()
