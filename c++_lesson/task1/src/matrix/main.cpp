#include<iostream>
#include"matrix.h"

int main() {
	Matrix mat1(3, 2);
	Matrix mat3(2, 3);
	std::cin >> mat3;
        std::cin >> mat1;
	Matrix mat2(3,3);
	//mat2 = mat1 * mat3;
	mat1 += mat1;
	std::cout << mat1 << std::endl;
	return 0;
}
