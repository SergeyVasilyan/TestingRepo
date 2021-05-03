#include"matrix.h"
#include<iostream>
#include<csignal>
#include <pthread.h>
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12
#define SUCCESS 0

void signal_handel(int signum)
{
	std::cout << "Interrupt signal (" << signum <<") received." << std::endl;
	exit(signum);
}

void check_assignment_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	mat1 = mat1;
	std::cout << mat1 << std::endl;
}

void check_equality_operator()
{
	Matrix mat1(3,2);
	Matrix mat2(5,9);
	if (mat1 == mat2) {
		std::cout << " Matrices are equal. " <<std::endl;
	}
	std::cout << " Matrices aren't equal. " <<std::endl;
}

void bad_check_sum_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	Matrix mat2(5,9);
	Matrix mat3 = mat1 + mat2;
	std::cout << mat3 << std::endl;
}

void check_sub_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	Matrix mat2(3,2);
	mat2[0][0] = 3;
	mat2[2][1] = 5.222;
	Matrix mat3 = mat1 - mat2;
	std::cout << mat3 << std::endl;
}

void bad_check_scalar_with_assignment_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	mat1 *= mat1;
	std::cout << mat1 << std::endl;
}

void check_scalar_with_assignment_operator()
{
	Matrix mat1(2,2);
	mat1[0][0] = 5;
	mat1[0][1] = 1;
	mat1[1][0] = 2;
	mat1[1][1] = 7;
	mat1 *= mat1;
	std::cout << mat1 << std::endl;
}
void check_multiplication_number()
{
	/*	
		Matrix mat1(2,2);
		mat1[0][0] = 1;
		mat1[0][1] = 1;
		mat1[1][0] = 1;
		mat1[1][1] = 1;
		mat1 = 3 * mat1;
		mat1 = mat1 * 6;
		std::cout << mat1 << std::endl;
	/*
	 */
	Matrix mat1(2,2);
	mat1[0][0] = 1;
	mat1[0][1] = 1;
	mat1[1][0] = 1;
	mat1[1][1] = 1;
	double a;
	std::cin >> a;
	mat1 = a * mat1;
	std::cout << mat1 << std::endl;

}
void check_cin_operator()
{
	Matrix mat1(3,3); // stugel chaperi anpatasxanutyuny ev convert chlinely 
	std::cout << "object created." << std::endl;
	std::cin >> mat1;
}
void* server(void *args)
{
    return SUCCESS;
}
int main()
{
	signal(SIGABRT, signal_handel);
	pthread_t thread;
    int status;
    int status_addr;
    status = pthread_create(&thread, NULL, server, NULL);
    if (status != 0) {
        printf("main error: can't create thread, status = %d\n", status);
        exit(ERROR_CREATE_THREAD);
    }
    status = pthread_join(thread, (void**)&status_addr);
    if (status != SUCCESS) {
        printf("main error: can't join thread, status = %d\n", status);
        exit(ERROR_JOIN_THREAD);
    }
	//  check_assignment_operator();
	//  check_equality_operator();
	//  bad_check_sum_operator();
	    check_sub_operator();
	//  bad_check_scalar_with_assignment_operator();
	//  check_scalar_with_assignment_operator();
	//  check_multiplication_number();
	//  check_cin_operator();
	return 0;
}
