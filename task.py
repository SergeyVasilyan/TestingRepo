#!/usr/bin/python3
import sys
if len(sys.argv)==5:
	try:
		number1=int(sys.argv[1])
		number2=int(sys.argv[2])
		if number1==number2 :
			print("1-st and 2-d arguments are equal \n")
		elif number1<number2 :
			print("1-st argument lesser than 2-d \n")
		else :
			print("1-st greater than 2-d \n")
		summ=number1+number2
		mul=number1*number2
		power=number1**number2
		dif=number1-number2
		print("Sum of 2 arguments is "+str(summ)+"\n"+"Multiplication is "+str(mul)+"\n"+"Power is "+str(power)+"\n"+"Difference is "+str(dif)+"\n")
		try:
			div=float(number1)/float(number2)
		except:
			print("Division on 0,NO NO NO!")
		print("Division is "+str(div))	
	except:
		print("Can't cast to int") 
#else :
#	print("Invalid type input")
else :
	print("Invalid argument count")
