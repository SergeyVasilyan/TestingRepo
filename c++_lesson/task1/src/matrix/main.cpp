#include"matrix.h"
#include<iostream>
#include<csignal>
#include<cstring>
#include<cassert>

void signal_handel(int signum)
{
	std::cout << "Interrupt signal (" << signum <<") received." << std::endl;
	exit(signum);
}

void test_assignment_operator()
{
	Matrix mat1(3, 2);
	Matrix mat2(3, 2);
	mat2[2][1] = 10;
	mat1 = mat2;
	assert(mat1 == mat2);
}

void test_equality_operator()
{
	Matrix mat1(3, 2);
	Matrix mat2(3, 2);
	assert(mat1 == mat2);
}

void test_subscription_operator()
{
	double value = 2;
	Matrix mat1(3, 2);
	mat1[1][1] = value;
	assert(mat1[1][1] == value);
}//stugel erb int,char,string depqery;

void test_sum_operator()
{
	Matrix mat1(3, 2);
        mat1[2][1] = 9;
	Matrix mat2(3, 2);
	mat2[2][1] = 10;
	Matrix mat3(3, 2);
        mat3[2][1] = 19;
	assert(mat3 == mat1 + mat2);
}

void  test_sub_operator()
{
	Matrix mat1(3, 2);
	Matrix mat2(3, 2);
	mat1[0][0] = 3;
        mat1[2][1] = 5;
	mat2[0][0] = 3;
	mat2[2][1] = 5.222;
	Matrix mat3(3, 2);
       	mat3[0][0] = 0;
        mat3[2][1] = -0.222;
 	assert(mat3 == mat1 - mat2);
}

void test_scalar_with_assignment_operator()
{
	Matrix mat1(2,2);
	mat1[0][0] = 5;
	mat1[0][1] = 1;
	mat1[1][0] = 2;
	mat1[1][1] = 7;
	mat1 *= mat1;
	Matrix mat2(2,2);
        mat2[0][0] = 27;
        mat2[0][1] = 12;
        mat2[1][0] = 24;
        mat2[1][1] = 51;
	assert(mat2 == mat1);
}
/* aha tvabanutyun
//log generacnel u stugel assertov trela te che 
void test_scalar_with_assignment_operator_failure()
{
	Matrix mat1(3,2);
	mat1[2][0] = 8;
        mat1[1][1] = 10;
        mat1[1][0] = 4;
	mat1 *= mat1;
}
*/

void test_multiplication_number()
{
	int matrix_size = 2;
	int init_value = 1;
	double multiplicator = 6;
	Matrix mat1(matrix_size, matrix_size);
	Matrix mat2(matrix_size, matrix_size);
	for (int i = 0; i < matrix_size; i++){
		for (int j = 0; j < matrix_size; j++){
			mat1[i][j] = init_value;
			mat2[i][j] = mat1[i][j] * multiplicator;
		}
	}
	assert(mat2 == multiplicator * mat1);
}

//stugel en depqy erb matrixy bazmapatlaca int, char ,string(voch double)
/*
void check_cin_operator_failure()
{
	Matrix mat1(3,3); 
	std::cout << "object created." << std::endl;
	std::cin >> mat1;
}
*/


void test()
{
	 test_assignment_operator();
         test_equality_operator();
         test_sum_operator();
         test_sub_operator();
        // test_scalar_with_assignment_operator_failure();
         test_scalar_with_assignment_operator();
         test_multiplication_number();
        // check_cin_operator_failure();
         test_subscription_operator();


}
int main()
{
	signal(SIGABRT, signal_handel);
	test();
	return 0;
}
