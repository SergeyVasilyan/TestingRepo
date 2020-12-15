#!/usr/bin/env python3
from threading import Thread
import time
def proc():
    i=0
    while True:
        print(i)
        i+=1
if __name__=='__main__':
    my_thread=Thread(target=proc)
    my_thread.start()
    my_thread.join(1)

