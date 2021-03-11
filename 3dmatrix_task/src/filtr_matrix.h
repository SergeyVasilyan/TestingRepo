#ifndef FILTR_MATRIX_H
#define FILTR_MATRIX_H
#include <iostream>
#include <stdio.h>

class FMatrix
{
public:
	FMatrix(std::string);
	bool read_file(std::string);
	void change();
	int ***data;
private:
	std::string filename;
};
#endif
