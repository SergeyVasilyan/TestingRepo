#include <iostream>
#include <stdio.h>
#include <string>
#include <pthread.h>
#include "thread.h"

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define SUCCESS        0

Thread::Thread(void* (*f)(void*),void* arg1){
	arg = arg1;

	int  status;
        if(status = pthread_create(&thrd, NULL, f, arg1)) {
         std::cerr << "Thread returns error" <<status<< std::endl;
         }
	}
void Thread::my_pthread_join(){
    int status;
    if (status = pthread_join(this->thrd, NULL)) {
        printf("main error: can't join thread, status = %d\n", status);
    }
}
