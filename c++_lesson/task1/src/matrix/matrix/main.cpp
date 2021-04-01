#include<iostream>
#include"matrix.h"

int main(){

	Matrix mat1(3, 4);
	Matrix mat3(3, 4);
	std::cin >> mat1 >> mat3;
	Matrix mat2(mat1);
	mat1 += mat1 * mat2;
	mat2 *= mat2;
	mat3 = mat1 + (-mat2 * mat2 * 2) - mat1;
	std::cout<<mat3;
return 0;
}
