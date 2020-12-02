#! /usr/bin/python3

def compare(arg1, arg2):
    if type(arg1) == type(str()):
        number1 = len(arg1)
        number2 = len(arg2)
    else:
        number1 = arg1
        number2 = arg2
    if number1 > number2:
        print("{} is greater than {}.".format(arg1, arg2))
    elif number1 < number2:
        print("{} is less than {}.".format(arg1, arg2))
    else:
        print("{} and {} are equal.".format(arg1, arg2))

number1=input("first number ")
while number1.isdigit() == False:
        print("Invalid number")
        number1=input("first number ")
number1=int(number1)
number2=input("second number ")
while number2.isdigit() == False:
        print("Invalid number")
        number1=input("second number ")
number2=int(number2)
string1=str(input("str1 number "))
string2=str(input("str2 number "))

compare(number1, number2)
sum=number1 + number2
sub=number1 - number2
print("Addition of two number: ",sum)
print("Difference of two number: ",sub)
try:
    div=number1 / number2
    print("Division of two number: ",div)
except ZeroDivisionError:
    print("Cannot divide by zero!")
compare(string1, string2)
count1 = string1.count(string2)
count2 = string2.count(string1)
if count1 != 0:
    print("string1 is a substring of the string2")
elif count2 !=0:
    print("string2 is a substring of the string1")
else:
    print("Is not a substring of each other")



