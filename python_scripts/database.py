#! /usr/bin/python3

# SPLIT FUNCTION NAMES WITH '_' CHARS
# WRONG CONCEPT OF DICT
# MAIN LOGIC IS RIGTH BUT WILL NOT WORK.

#import class -this class has not been written yet ։)(

users= {
    "user": class_object
       }

def register():
    list=["admin","employee","guest"]
    while True:
        username = input("New username: ")
        if not len(username) > 0:
            print("Username can't be blank")
            continue
        else:
            break
    while True:
        password = input("New password: ")
        if not len(password) > 0:
            print("Password can't be blank")
            continue
        else:
            break
    while True:
        email = input("Enter email: ")
        if not len(email) > 0:
            print("Email can't be blank")
            continue
        else:
            break
    while True:
        role = input("Enter role: ")
        if not len(role) > 0:
            print("Role can't be blank")
            continue
        elif role not in list:
            print("There is no such role")
            continue
        else:
            break
    if role == "admin":
        users[username] = Admin(username,password,email)
    elif role == "employee":
        users[username] = Employee(username,password,email)
    else:
        users[username] = Guest(username,password,emai)


    print("Account has been created")

def login_auth(username, password):
    if username in users:
        if password == users[username].getpassword:
            print("Login successful")
            return True
    return False

def login():
    while True:
        username = input("Username: ")
        if not len(username) > 0:
            print("Username can't be blank")
        else:
            break
    while True:
        password = input("Password: ")
        if not len(password) > 0:
            print("Password can't be blank")
        else:
            break

    if  login_auth(username,password):
        print("Welcome to your account " + username)
        return in_system(username) #this function has not been written yet
    else:
        print("Invalid username or password")

#def in_system(username):

   # bla bla bla


def main():
    count = 1
    while count != 0:
        register()
        count -= 1
    while count != 5:
        print("Sign in system")
        login()
        count += 1


main()
