#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix
{
public:
	Matrix(int= 5 ,int= 5);
	~Matrix();
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, Matrix&);

private:
	double **data;
	int rows, cols;
};
#endif
