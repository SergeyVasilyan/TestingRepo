#! /usr/bin/python3
import sys

if len(sys.argv) == 5:
    try:
        number1=int(sys.argv[1])
        number2=int(sys.argv[2])
        string1=sys.argv[3]
        string2=sys.argv[4]

        if number1 > number2:
            print("number1 is greater than number2.")
        elif number1 < number2:
            print("number2 is greater than number1.")
        else:
            print("number1 and number2 are equal.")
        sum=number1 + number2
        sub=number1 - number2
        print("Addition of two number: ",sum)
        print("Difference of two number: ",sub)
        try:
            div=number1 / number2
            print("Division of two number: ",div)
        except ZeroDivisionError:
            print("Cannot divide by zero!")
        string1_len=len(string1)
        string2_len=len(string2)
        if string1_len > string2_len:
            print("string1 longer than string2.")
        elif string1_len < string2_len:
            print("string2 is longer than string1.")
        else:
            print("string1 and string2 are equal.")
        count1 = string1.count(string2)
        count2 = string2.count(string1)
        if count1 != 0:
            print("string1 is a substring of the string2")
        elif count2 !=0:
            print("string2 is a substring of the string1")
        else:
            print("Is not a substring of each other")
    except:
            print("Invalid Type.")
else:
    print("Invalid number of arguments.")
