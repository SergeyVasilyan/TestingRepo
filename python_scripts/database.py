#! /usr/bin/python3

#import class -this class has not been written yet ։)(
users= {
        "user": {
            "password": "password",
            "mail": "email",
            "role": "role"
        }
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

    users[username] = {
    "password": password,
    "email": email,
    "role": role
}

    print("Account has been created")

def loginauth(username, password):
    if username in users:
        if password == users[username]["password"]:
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

    if  loginauth(username,password):
        print("Welcome to your account " + username)
        return insystem(username) #this function has not been written yet
    else:
        print("Invalid username or password")

def insystem(username):

   # bla bla bla

def main():

    count = 1
    while count != 0:
        register()
        count -= 1
    while count != 5
    print("Sign in system")
    login()
    count += 1

main()
