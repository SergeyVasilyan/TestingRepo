#!/usr/bin/python3
import random

def helper():
    print("****************************************************************************")
    print("*  Hello dear friend!                                                      *")
    print("*  For playing this game please enter number from 100 to 999.              *")
    print("*  Your aim is to guess the magic number which our program is keep in mind.*")
    print("*  For closing game enter exit or Ctrl+C.                                  *")
    print("****************************************************************************")

def game(randNum,head,tail):
    try:
        while True:
            ourNum=input("Please enter number from {}-{} \n" .format(head,tail))
            if ourNum=="exit":
                return "Exit"
            elif ourNum=="help":
                helper()
                continue
            else:
                try:
                    ourNum=int(ourNum)
                    if ourNum<100 and ourNum>999:
                        print("Please enter number from {}-{}" .format(head,tail))
                        continue
                    if ourNum==randNum:
                        print("Congratulations You guess the magic number! The number is {}" .format(ourNum))
                        return "End"
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
                    print("Invalid type error!Make your choice from 100-999 range")
    except KeyboardInterrupt:
        print("\n Game was closed")
        return "Exit"

def main():
    flag=True
    while flag:
        try:
            randNum=random.randint(100,999)
            head=100
            tail=999
            answer=game(randNum,head,tail)
            if answer=="Exit":
                flag=False
                break
            else:
                while True:
                    choose=input("Do you want play new game? [y/n] ")
                    if choose=="y":
                        break
                    elif choose=="n":
                        flag=False
                        break
                    else:
                        continue
        except KeyboardInterrupt:
            print()
            break
main()
