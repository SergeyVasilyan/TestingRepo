#!/usr/bin/python3

def adding(arg1,arg2):
    summ=arg1+arg2
    print("{} + {} = {}" .format(arg1,arg2,summ))

def difference(arg1,arg2):
    diff=arg1-arg2
    print("{} - {} = {}" .format(arg1,arg2,dif))

def mul(arg1,arg2):
    mul=arg1*arg2
    print("{} * {} = {}" .format(arg1,arg2,mul))

def division(arg1,arg2):
    try:
        arg1=float(arg1)
        arg2=float(arg2)
        div=arg1/arg2
        print("{} / {} = {}" .format(arg1,arg2,div))
    except ZeroDivisionError:
        print("Invalid action! Division on ZERO!")

def power(arg1,arg2):
    power=arg1**arg2
    print("{} ** {} = {}" .format(arg1,arg2,power))

def modd(arg1,arg2):
    mod=arg1%arg2
    print("{} % {} = {}" .format(arg1,arg2,mod))

def factor(arg1):
    if arg1==0 or arg1==1:
        return 1
    fact=arg1*factor(arg1-1)
    return fact

def factorial(arg1):
    fact=factor(arg1)
    print("{}!" .format(fact))

def choose_func(arg1,arg2,action):
    if action=="+":
        adding(arg1,arg2)
    elif action=="-":
        difference(arg1,arg2)
    elif action=="*":
        mul(arg1,arg2)
    elif action=="**":
        power(arg1,arg2)
    elif action=="/":
        division(arg1,arg2)
    else:
        modd(arg1,arg2)

def main():
    while True:
        actions=["+", "-", "*", "/", "**", "%"]
        try:
            num1=input("Enter first number: ")
            num1=float(num1)
            action=input("Input action: ")
            if action=="!" and num1==int(num1):
                factorial(num1)
                continue
            else:
                print("Invalid type error")
                continue
            num2=input("Enter second number: ")
            num2=float(num2)
            if num1==int(num1) and num2==int(num2) :
                num1=int(num1)
                num2=int(num2)
            if action in actions:
                choose_func(num1,num2,action)
            else:
               print("Invalid action")
               continue
        except:
            print("Enter integer or float numbers")
            continue
main()
