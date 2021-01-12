#ifndef THREAD_H
#define THREAD_H
#include <iostream>
#include <string>
#include <pthread.h>

class Thread {
  public:
          Thread(pthread_t , void*(*)(void*), const pthread_attr_t* ,void*);
                                                                        //Thread(pthread_t , void* f,const pthread_attr_t*,void*);
	  void my_pthread_join( Thread& );
  private:
          pthread_t thrd;
          void* func;
          const pthread_attr_t* attr;
          void* arg;
};
#endif


