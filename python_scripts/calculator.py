#! /usr/bin/python3
def sum(arg1,arg2):
    return arg1 + arg2

def subtract(arg1,arg2):
    return arg1 - arg2

def division(arg1,arg2):
    try:
        div=arg1/arg2
        return div
    except ZeroDivisionError:
        print("Cannot divide by zero!")

def mult(arg1,arg2):
    return arg1 * arg2

def factorial(n): 
   if n == 1:
    return n
   else:
    return n*factorial(n-1)

def check_int(number):
        return int(number) == float(number)
def arithmetic_operations(num1,num2,sign):
    if sign == '+':
       if check_int(sum(num1,num2))== True:
           print("The result of the action: {}".format(int(sum(num1,num2))))
       else:
           print("The result of the action: {}".format(sum(num1,num2)))

    elif sign == '-':
        if check_int(subtract(num1,num2)) == True:
            print("The result of the action: {}".format(int(subtract(num1,num2))))

        else:
            print("The result of the action: {}".format(sum(num1,num2)))

    elif sign == '*':
        if check_int(mult(num1,num2)) == True:
            print("The result of the action: {}".format(int(mult(num1,num2))))
        else:
            print("The result of the action: {}".format(mult(num1,num2)))
    else:
       if check_int(division(num1,num2)) == True:
           print("The result of the action: {}".format(int(divisin(num1,num2))))
       else:
           print("The result of the action: {}".format(division(num1,num2)))

def main():
    list=['+','-','/','!','*']
    try:
        num1 = float(input("Enter the first number: "))
        sign = input("Enter sign of action: ")
        while list.count(sign) == 0:
            print("Sorry,but there is no operation for this sign,choose from these('+','-','/','!','*')")
            sign=input("Enter sign of action:  ")
        if sign == '!' :
            if int(num1) == 0:
                print("The result of the action: 1")
                return
            elif int(num1) < 0:
                print("Sorry, factorial does not exist for negative numbers")
                return
            else:
                factorial(int(num1))
                print("The result of the action: {}".format(int(factorial(num1))))
                return

        num2 = float(input("Enter the second number: "))
        arithmetic_operations(num1,num2,sign)
    except:
        print("Invalid type") 
main()
