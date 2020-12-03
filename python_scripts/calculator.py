#! /usr/bin/python3

# I do not see the descriptions of any functions.
def add(number_one, number_two):
    return number_one + number_two

# Bla bla bla
def subtract(number_one, number_two):
    return number_one - number_two

# Bla bla bla
def divide(number_one, number_two):
    try:
        result = number_one / number_two
        return result
    except ZeroDivisionError:
        print("Cannot divide by zero!")

# Bla bla bla
def multiply(number_one, number_two):
    return number_one * number_two

# Bla bla bla
def factorial(number): 
   if number == 1: # What if number == 0 or number < 0?
    return number
   else:
    return number * factorial(number - 1)

# Bla bla bla
def check_number_is_integer(number):
        return int(number) == float(number)

# Bla bla bla 
def arithmetic_operations(number_one, number_two, operator):
    if operator == '+':
       if check_number_is_integer(add(number_one, number_two)) == True: # What is the purpose of checking the result is integer or not????
#                                 ^^^^^^^^^^^^^^^^^^^^^^^^^^ 
           print("The result of the action: {}".format(int(add(number_one, number_two))))
       else:                                          #^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
           print("The result of the action: {}".format(add(number_one, number_two)))
#                                                      ^^^^^^^^^^^^^^^^^^^^^^^^^^
    elif operator == '-':
        if check_number_is_integer(subtract(number_one, number_two)) == True:
#                                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            print("The result of the action: {}".format(int(subtract(number_one, number_two))))
#                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        else:
            print("The result of the action: {}".format(add(number_one, number_two))) # Why we summing number instead of subtracting????
#                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^
    elif operator == '*':
        if check_number_is_integer(multiply(number_one, number_two)) == True:
#                                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            print("The result of the action: {}".format(int(multiply(number_one, number_two))))
#                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        else:
            print("The result of the action: {}".format(multiply(number_one, number_two)))
#                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    else:
       if check_number_is_integer(divide(number_one, number_two)) == True:
#                                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
           print("The result of the action: {}".format(int(divide(number_one, number_two))))
#                                                      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
       else:
           print("The result of the action: {}".format(divide(number_one, number_two)))
#                                                      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

# Bla bla bla
def main():
    list=['+','-','/','!','*']
    try:
        number_one = float(input("Enter the first number: "))
        operator = input("Enter the operator: ")
        while list.count(operator) == 0: # Actually it works, but i don't like the logic. RE-IMPLEMENT!!!
            print("Invalid operator is given\nChoose from ('+','-','/','!','*')")
            operator = input("Enter the operator: ")
        if operator == '!' :
            if int(number_one) == 0:
                print("The result of the action: 1") # ????????????  Is not this be the result of the function ???????????
                return # <----- Change to 'break' statement.
            elif int(number_one) < 0:
                print("Error: negative number is given for factorial calculation.")
                return # <----- This too.
            else:
                factorial(int(number_one)) # What is the purpose of this call??????
                print("Result: {}".format(int(factorial(number_one))))
                return # <----- aaaaand this too. :)
        number_two = float(input("Enter the second number: "))
        arithmetic_operations(number_one, number_two, operator)
    except:
        print("Invalid operator.") 
main()
