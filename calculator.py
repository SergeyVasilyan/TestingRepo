#!/usr/bin/python3

# Where is the comments, descriptions???
def add(number_one, number_two):
    result = number_one + number_two
    print("{} + {} = {}" .format(number_one, number_two, result))

# la bla bla
def substract(number_one, number_two):
    result = number_one - number_two
    print("{} - {} = {}" .format(number_one, number_two, result))

# la bla bla
def multiply(number_one, number_two):
    result = number_one * number_two
    print("{} * {} = {}" .format(number_one, number_two, result))

# la bla bla
def divide(number_one, number_two):
    try:
        number_one = float(number_one)  # <------ does not get it why
        number_two = float(number_two)  # <------ this one too
        result = number_one / number_two
        print("{} / {} = {}" .format(number_one , number_two, result))
    except ZeroDivisionError:
        print("Can not dive by zero.")

# la bla bla
def power(number_one, number_two):
    result = number_one ** number_two
    print("{} ** {} = {}" .format(number_one, number_two, result))

# la bla bla
def mod(number_one, number_two):
    result = number_one % number_two
    print("{} % {} = {}" .format(number_one, number_two, result))

# la bla bla
def factorial(number):
    if number == 0 or number == 1: # If i pass negative number, what should be the behavior of the application?
        return 1
    result = number * factorial(number - 1)
    print("{}!" .format(result))
    return result

# WTH IS THIS FOR??????
#def factorial(arg1):
#    fact=factor(arg1)
#    print("{}!" .format(fact))

# la bla bla
def operation(numebr_one, number_two, operator):
    if operator == "+":
        add(number_one, number_two)
    elif operator == "-":
        substract(number_one, number_two)
    elif operator == "*":
        multiply(number_one, number_two)
    elif operator == "**":
        power(number_one, number_two)
    elif operator == "/":
        divide(number_one, number_two)
    else:
        mod(number_one, number_two)

# Bla bla bla
def main():
    while True: # When application should exit this gorgeous while loop?
        operators=["+", "-", "*", "/", "**", "%"]
        try:
            number_one = float(input("Enter first number: "))
            operator = input("Input action: ")
            if action == "!" and number_one == int(number_two): 
                factorial(number_one)
                continue
            else:
                print("Error: float is given.") 
                continue
            number_two = float(input("Enter second number: "))
            if number_one == int(number_two) and number_two == int(number_two) :
                number_one = int(number_one)
                number_two = int(number_two)
            if operator in operators:
                operation(number_one, number_two, operator)
            else:
               print("Invalid operator entered.")
               continue
        except:
            print("Enter: Non number is given.")
            continue
main()
