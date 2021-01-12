#include <iostream>
#include <string>
#include <pthread.h>
#include "thread.h"
void* func(void* ptr)
{

	char* m = (char*) ptr;
	for(int i=0;i<1000;++i){
		std::cout << m << std::endl;
	}
}

int main()
{
	pthread_t thrd1,thrd2;
	char* str1 = "Hi";
	char* str2 = "World";

	Thread thrd1(thrd1,NULL,func,(void*)str1);
        Thread thrd2(thrd2,NULL,func,(void*)str2);
	thrd1.my_pthread_join();
	thrd2.my_pthread_join();
	return 0;
}
