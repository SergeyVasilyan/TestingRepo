#! /usr/bin/python3
import random 
random_num=random.randrange(100, 999)
guess_num=0
while guess_num != random_num:
    guess_num=input("Input number ")
    while guess_num.isdigit() == False:
        print("Invalid number")
        guess_num=input("Input number ")
    
    guess_num=int(guess_num)   
    if guess_num == random_num:
        print("You found the number.")
    elif guess_num > random_num:
        print ("Give a lower number ")
    else:
        print("Give a higher number")
