#include <iostream>
#include <string>
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
	char* str1 = "Hi";
	char* str2 = "World";

	Thread thrd1(func,(void*)str1);
    Thread thrd2(func,(void*)str2);
	thrd1.my_pthread_join();
	thrd2.my_pthread_join();
	return 0;
}
