#! /usr/bin/python3
import random

def help_message():
    print("This is a guessing game: you need to choose a number from 100 to 999.")
    print("The game ends when you find a number.")
    print("To exit the game enter the word 'quit' or press 'Ctrl+C'\n")

def game_func(random_num):
    guess_num=0
    attempts_count=0
    try:
        while guess_num != random_num:
            guess_num=input("Input number: ")
            if guess_num == "quit":
                quit()
            elif guess_num == "help":
                help_message()
                continue
            elif guess_num.isdigit() == False:
                attempts_count += 1
                print("Invalid number.\n")
                continue
            else:
                attempts_count += 1
                guess_num=int(guess_num)
                if guess_num == random_num:
                    print("Congratulations,you found the number.")
                    print("You used {} attempts.".format(attempts_count))
                    answer=input("Do you wish to replay the game?(yes)")
                    return answer == "yes"
                elif guess_num > random_num:
                    print ("Give a lower number.\n")
                else:
                    print("Give a higher number.\n")
    except KeyboardInterrupt:
        print("\nGame is interrupted")
        return False
def main():
    while True:
        print("\nWelcome to the Number Game!\n")
        random_number=random.randint(100, 999)
        if game_func(random_number) == False:
           break

main()
