#! /usr/bin/python3
import sys

if len(sys.argv) != 5:
    print("Error in arguments")
else:
    if not (sys.argv[1].isnumeric()  and  sys.argv[2].isnumeric()):
        print("Error in arguments")
    else:
        number1=int(sys.argv[1])
        number2=int(sys.argv[2])
        string1=sys.argv[3]
        string2=sys.argv[4]

        if number1 > number2:
            print("number1 is greater than number2")
        elif number1 < number2:
            print("number2 is greater than number1")
        else:
            print("number1 and number2 are equal")
        summ=number1 + number2
        div=number1 / number2
        print("Addition of two number",summ)
        print("Division of two number",div)
        string1_len=len(string1)
        string2_len=len(string2)
        if string1_len > string2_len:
            print("string1 longer than string2")
        elif string1_len < string2_len:
            print("string2 is longer than string1")
        else:
                print("string1 and string2 are equal")
