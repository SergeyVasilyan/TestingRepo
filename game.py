#!/usr/bin/python3
import random

def game(randNum,head,tail,helper):
	while True:
		ourNum=input("Please enter number from {}-{} \n" .format(head,tail))
		if ourNum=="exit":
			return
		elif ourNum=="help":
			print(helper)
			continue
		else:
			try:
				ourNum=int(ourNum)
				if ourNum<100 and ourNum>999:
					print("Please enter number from {}-{}" .format(head,tail))
					continue
				if ourNum==randNum:
					print("Congratulations You guess the magic number! The number is {}" .format(ourNum))
					break
				elif ourNum<head or ourNum>tail:
					print("Magic number is in {}-{} range!" .format(head,tail))
					continue
				elif ourNum<randNum:
					head=ourNum
					print("Magic number is in {}-{} range!" .format(head,tail))
					continue
				else:
					tail=ourNum
					print("Magic number is in {}-{} range!" .format(head,tail))
					continue
			except:
				print("Please enter integer from 100-999 range")

def main():
	randNum=random.randrange(100,1000)
	head=100
	tail=999
	helper="""
Hello dear friend!
For playing this game please enter number from 100 to 999.
Your aim is to guess the magic number which our program is keep in mind"""
	game(randNum,head,tail,helper)
main()
