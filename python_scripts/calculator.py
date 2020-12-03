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

def func(number):
        return int(number) == float (number)

def main():
    list=['+','-','/','!','*']
    try:
        num1 = float(input("Enter the first number: "))
        sign = input("Enter sign of action: ")
        while list.count(sign) == 0:
            print("Invalid number")
            number1=input("Enter the first number:  ")
        if sign == '!' :
            factorial(int(num1))
            print("The result of the action: {}".format(factorial(num1)))
            return

        num2 = float(input("Enter the second number: "))
        if sign == '+':
           if func(sum(num1,num2))== True:
               print("The result of the action: {}".format(int(sum(num1,num2))))
           else:
               print("The result of the action: {}".format(sum(num1,num2)))

        elif sign == '-':
            if func(subtract(num1,num2)) == True:
                print("The result of the action: {}".format(int(subtract(num1,num2))))

            else:
                print("The result of the action: {}".format(sum(num1,num2)))

        elif sign == '*':
            if func(mult(num1,num2)) == True:
                print("The result of the action: {}".format(int(mult(num1,num2))))
            else:
                print("The result of the action: {}".format(mult(num1,num2)))
        else:
           if func(division(num1,num2)) == True:
               print("The result of the action: {}".format(int(divisin(num1,num2))))
           else:
               print("The result of the action: {}".format(division(num1,num2)))

    except:
        print("Invalid type") 
main()
