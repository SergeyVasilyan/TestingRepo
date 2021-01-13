#ifndef THREAD_H
#define THREAD_H
#include <iostream>
#include <pthread.h>

class Thread {
  public:
          Thread(void *(*)(void*),void* );
	      void my_pthread_join();
  private:
          pthread_t thrd;
          void* arg;
};
#endif


