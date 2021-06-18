#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<cassert>
#include <iostream>

int redirectOutputs();
void p(){
 redirectOutputs();
}
int main()
{
    p();
    printf("OUT : test\n");
    perror("ERR : test");
    printf("OUT : test 2\n");
	std::cout << "AAAAAA" << std::endl;
assert(1 + 1 == 5);
    int t = 23;
    printf("OUT : again\n");
    perror("ERR : again");

	return 0;
}

int redirectOutputs()
{
    int log = open("ERR.log", O_RDWR|O_CREAT|O_APPEND, 0600);
    if (log == -1)
    {
        perror("opening err.log");
        return -1;
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    dup2(log, STDOUT_FILENO);
    dup2(log, STDERR_FILENO);
    close(log);
	return 0;
}
