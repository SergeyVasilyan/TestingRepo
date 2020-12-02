#!/usr/bin/python3
import sys

def compare_strings(string1, string2):
	if string1 == string2:
		print("Strings are equal")
	else:
		print("The strings are different")

def actions_with_numbers(num1,num2):
	try:
		number1=int(num1)
		number2=int(num2)
		if number1==number2 :
			print("1-st and 2-nd arguments are equal")
		elif number1<number2 :
			print("1-st argument lesser than 2-nd")
		else:
			print("1-st greater than 2-nd")
		summ=number1+number2
		mul=number1*number2
		power=number1**number2
		dif=number1-number2
		print("Sum of 2 arguments is "+str(summ)+"\n"+"Multiplication is "+str(mul)+"\n"+"Power is "+str(power)+"\n"+"Difference is "+str(dif)+"")
		try:
			div=float(number1)/float(number2)
			print("Division is "+str(div))	
		except:
			print("Division on 0,NO NO NO!")
	except:
			print("Can't cast to int") 

def actions_with_strings(string1,string2):
	if len(string1) == len(string2):
		print("The length of strings are equal")
	elif len(string1) > len(string2):
		print("First string is longer then second")
	else:
		print("Second string is longer than first")
	print("First string in uppercase are: "+string1.upper())
	print("Second string in lowercase are: "+string2.lower())
	
def main(args):
	if len(args)==5:
		actions_with_numbers(args[1],args[2])
		string1=args[3]
		string2=args[4]
		compare_strings(string1,string2)
		actions_with_strings(string1,string2)
	else:
		print("Invalid argument count")

main(sys.argv)
