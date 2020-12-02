#!/usr/bin/python3
import random

def main():
	randNum=random.randrange(100,1000)
	head=100
	tail=999
	helper="""
Hello dear friend!
For playing this game please enter number from 100 to 999.
Your aim is to guess the magic number which our program is keep in mind"""
	while true:
		ourNum=input("Please enter number from 100-999")
		if ourNum=="exit":
			return
		elif ourNum=="help":
			print(helper)
			continue
		else
			try:
				ourNum=int(ourNum)
				if ourNum==randNum:
					print("Congratulations You guess the magic number! The number is {}" .formate(ourNum))
					break
				elif ourNum<randNum:
					head=ourNum
					print("Magic number is in {}-{} range!" .format(head,tail))
					continue 
main()
