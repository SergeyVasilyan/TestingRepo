#! /usr/bin/python3

import random
import keyboard

print("Welcome to the Number Game!")
random_num=random.randrange(100, 1000)
guess_num=0
count=0
key = 'ctrl c'
HELP="""
This is a guessing game: you need to choose a number from 100 to 999. The game ends when you find a number or enter the word 'quit' or bang on the keys with  Ctrl C """
while guess_num != random_num:
    guess_num=input("Input number ")
    if guess_num == "quit" or keyboard.is_pressed(key):
        quit()
    elif guess_num == "help":
        print(HELP)
        continue
    else:
        while guess_num.isdigit() == False:
            print("Invalid number")
            guess_num=input("Input number ")
        count += 1
        guess_num=int(guess_num)
        if guess_num == random_num:
            print("Congratulations,you found the number.")
            print('You used', count, 'attempts.')
        elif guess_num > random_num:
            print ("Give a lower number ")
        else:
            print("Give a higher number")

