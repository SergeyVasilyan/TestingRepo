#include<iostream>
#include"matrix.h"

int main(){

	Matrix mat1(3, 2);
	Matrix mat3(2, 3);
	std::cin >> mat1 >> mat3;
	Matrix mat2(mat1);
	mat1 = mat1 * mat2;
	mat3 *= mat3;
	std::cout << mat3 << std::endl;
	std::cout << mat3 << std::endl;
	mat3 = mat1 + mat3;
	std::cout << mat3;
return 0;
}
