#include <iostream>
#include <string>
#include <pthread.h>
#include "thread.h"

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define SUCCESS        0

Thread::Thread(pthread_t thrd1, void*(*f)(void*),const pthread_attr_t* attr1,void* arg1){
	thrd = thrd1;
	func = f ;
	attr = attr1;
	arg = arg1;

	int  status;
        if(status = pthread_create(&thrd1, attr1, f, arg1)) {
         std::cerr << "Thread 1 returns error" <<status<< std::endl;
         }
	}
void Thread::my_pthread_join(Thread& thread){
    int status;
    if (status = pthread_join(thread.thrd, NULL)) {
        printf("main error: can't join thread, status = %d\n", status);
        exit(ERROR_JOIN_THREAD);
    }
}
