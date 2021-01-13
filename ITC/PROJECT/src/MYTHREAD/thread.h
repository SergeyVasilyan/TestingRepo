#ifndef THREAD_H
#define THREAD_H
#include <iostream>
#include <pthread.h>

class Thread {
  public:
          Thread(pthread_t , void *(*)(void*), const pthread_attr_t* ,void*);
	      void my_pthread_join();
  private:
          pthread_t thrd;
          void* (*func)(void*);
          const pthread_attr_t* attr;
          void* arg;
};
#endif


