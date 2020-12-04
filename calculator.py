#!/usr/bin/python3

# This function add two numbers and print result.
def add(number_one, number_two):
    result=number_one+number_two
    print("{} + {} = {}" .format(number_one, number_two, result))

# This function subtract two numbers and print result.
def substract(number_one, number_two):
    result=number_one-number_two
    print("{} - {} = {}" .format(number_one, number_two, result))

# This function multiply two numbers and print result.
def multiply(number_one, number_two):
    result=number_one*number_two
    print("{} * {} = {}" .format(number_one, number_two, result))

# This function divide two numbers and print result.
def divide(number_one, number_two):
    try:
        result=number_one/number_two
        print("{} / {} = {}" .format(number_one , number_two, result))
    except ZeroDivisionError:
        print("Can not divide by zero.")

# This function is calculate first number in second number degree and print result.
def power(number_one, number_two):
    result=number_one**number_two
    print("{} ** {} = {}" .format(number_one, number_two, result))

# This function is calculate residue of division numbers and print result.
def mod(number_one, number_two):
    result=number_one%number_two
    print("{} % {} = {}" .format(number_one, number_two, result))

# This function is calculate factorial of given number and print result.
def factorial(number):
    if number==0 or number==1:
        return 1
    result = number*factorial(number-1)
    print("{}! = {}" .format(number,result))
    return result

# This function is choose which operation function is call
def operation(number_one, number_two, operator):
    if operator=="+":
        add(number_one, number_two)
    elif operator=="-":
        substract(number_one, number_two)
    elif operator=="*":
        multiply(number_one, number_two)
    elif operator=="**":
        power(number_one, number_two)
    elif operator=="/":
        divide(number_one, number_two)
    else:
        mod(number_one,number_two)

#This function is print how to use this program.
def helper():
    print("""
            *******************************************************
            *  Welcome to calculator master v 0.00.0000.000.001!  *
            *  This program calculate some actions with numbers.  *
            *  Enter float or integer numbers only.               *
            *  For closing this program please enter Ctrl+c or    *
            *  exit!                                              *
            *******************************************************
           """)


# This is main function which organize steps of program.
def main():
        while True:
            operators=["+", "-", "*", "/", "**", "%"]
            try:
                number_one=input("Enter first number: ")
                if number_one=="exit":
                    return
                number_one=float(number_one)
                operator=input("Input operation: ")
                if operator=="exit":
                    return
                if operator=="!" and number_one==int(number_one) and number_one>=0:
                    number_one=int(number_one)
                    factorial(number_one)
                    continue
                elif operator=="!":
                    print("Invalid type input for factorial!")
                    continue
                number_two=input("Enter second number: ")
                if number_two=="exit":
                    return
                number_two=float(number_two)
                if number_one==int(number_one) and number_two==int(number_two):
                    number_one=int(number_one)
                    number_two=int(number_two)
                if operator in operators:
                    operation(number_one,number_two,operator)
                else:
                    print("Invalid action")
                    continue
            except KeyboardInterrupt:
                print("\nClosing calculator")
                return
            except:
                print("Enter integer or float numbers")
                continue
  
main()
