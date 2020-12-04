#! /usr/bin/python3

def help_messenge():
    print("This Calculator program allow you to execute simple calculations such as")
    print("addition,subtract,multiplication,division and factorial.")

# This function calculates the sum of two numbers.
def add(number_one, number_two):
    return number_one + number_two

# This function calculates the subtract of two numbers.
def subtract(number_one, number_two):
    return number_one - number_two

# This function calculates the division of two numbers,
# if a division occurs at zero, ZeroDivisionError exception is generated.
def divide(number_one, number_two):
    try:
        result = number_one / number_two
        return result
    except ZeroDivisionError:
        print("Cannot divide by zero!")

# This function calculates the multiplication of two numbers.
def multiply(number_one, number_two):
    return number_one * number_two

# This function calculates the factorial of number.
def factorial(number):
   if number == 0:
       return 1
   elif number < 0:
       print("Error: negative number is given for factorial calculation.")
       return
   else:
       if number == 1:
        return number
       else:
        return number * factorial(number - 1)

def check_number_is_integer(number):
        return int(number) == float(number)

# This function execute arithmetic operations.
def arithmetic_operations(number_one, number_two, operator):
    if operator == '+':
       temp=add(number_one, number_two)
       if check_number_is_integer(temp) == True:
           print("The result of the action: {}".format(int(add(temp))))
       else:
           print("The result of the action: {}".format(add(temp)))
    elif operator == '-':
        temp=subtract(number_one, number_two)
        print(type(temp))
        if check_number_is_integer(temp) == True:
            print("The result of the action: {}".format(int(temp)))
        else:
            print("The result of the action: {}".format(temp))
    elif operator == '*':
        temp=multiply(number_one, number_two)
        if check_number_is_integer(temp) == True:
            print("The result of the action: {}".format(int(temp)))
        else:
            print("The result of the action: {}".format(temp))
    else:
       temp=divide(number_one, number_two)
       if check_number_is_integer(temp) == True:
           temp=divide(number_one, number_two)
           print("The result of the action: {}".format(int(temp)))
       else:
           print("The result of the action: {}".format(temp))

def check_number_is_float():
    while True:
        try:
            number = input("Enter the number: ")
            number = float(number)
            return number
        except:
            if number == "exit":
                quit()
            elif number == "help":
                help_messenge()
            else:
                print("Invalid number")

# The main function into which the other functions are called.
def main():
    list=['+','-','/','!','*']
    try:
        number_one = check_number_is_float()
        operator = input("Enter the operator: ")
        while operator not in list:
          print("Invalid operator is given\nChoose from ('+','-','/','!','*')")
          operator = input("Enter the operator: ")
        if operator == '!' :
            print("Result: {}".format(factorial(int(number_one))))
            return
        number_two = check_number_is_float()
        arithmetic_operations(number_one, number_two, operator)
    except Exception:
        print("Invalid operator.")
    except KeyboardInterrupt: 
        print("\nProgram is interrupted.")

main()
