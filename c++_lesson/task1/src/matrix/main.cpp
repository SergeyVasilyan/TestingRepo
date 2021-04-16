#include<iostream>
#include"matrix.h"

int main()
{
	Matrix mat1(3, 2);
	std::cin >> mat1;
	Matrix mat3(2, 3);
    std::cin >> mat3;
	mat1 += mat1;
//	Matrix mat2(3, 3);
//	mat2 = mat1 * mat3;
//	mat1[1][1] = 55;
//	std::cout << mat1[1][1] << std::endl;
	std::cout << mat1 << std::endl;
	return 0;
}
