#include<iostream>
#include"matrix.h"
void check_constructor()
{
	Matrix mat1(3,-3);
}

void check_assignment_operator()
{
    Matrix mat1(3,2);
	std::cin >> mat1;
	mat1 = mat1;
	std::cout << mat1;
} 

void check_subscript_operator()
{
    Matrix mat1(3,3);
	mat1[2][-1] = 55;
	mat1[5][1] = 50;
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

void check_sum_operator()
{
    Matrix mat1(3,2);
	std::cin >> mat1;
    Matrix mat2(5,9);
    Matrix mat3 = mat1 + mat2;
}
void check_scalar_with_assignment_operator()
{
    Matrix mat1(3,2);
	std::cin >> mat1;
	mat1 *= mat1;
}

void check_cin_operator()
{
    Matrix mat1(3,3); // stugel chaperi anpatasxanutyuny ev convert chlinely 
    std::cout << "object created." << std::endl;
    std::cin >> mat1;
}
int main()
{
//  check_constructor();
//  check_assignment_operator();
//  check_subscript_operator();
//  check_equality_operator();
//  check_sum_operator();
//  check_scalar_with_assignment_operator();
//  check_cin_operator();
	return 0;
}
