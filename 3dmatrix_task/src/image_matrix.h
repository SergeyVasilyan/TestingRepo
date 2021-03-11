#ifndef IMAGE_MATRIX_H
#define IMAGE_MATRIX_H
#include <iostream>
#include <stdio.h>

class IMatrix
{
public:
	IMatrix(std::string);
	bool read_file(std::string );
	int ***data;
private:
	std::string filename;
};
#endif
