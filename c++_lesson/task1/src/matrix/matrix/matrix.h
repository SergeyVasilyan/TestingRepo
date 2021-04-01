#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

/*
   A class that creates an matrix object,
   which dimensions can not be changed during the object lifetime.
*/
class Matrix
{
public:
	Matrix(const int, const int);	//overloaded constructor that creates a matrix with  ROWxCOL dimensions,
	Matrix(const Matrix&);
	void set_value(int, int, double);	//changes the value of a specified element,
	double operator[](const int&)[] const;
	const double operator[](const int)[];
        Matrix& operator = (const Matrix&);
        bool operator == (const Matrix&) const;
	Matrix& operator - ();		        //converts the elements of the matrix to the opposite sign,
	Matrix& operator * (const Matrix&);     //scalar product of two matrices,
	Matrix& operator *= (Matrix const&);	//scalar product of two matrices via assignment to the first matrix,
	Matrix& operator + (const Matrix&);
	Matrix& operator += (Matrix const&);
	Matrix& operator - (const Matrix&);
	Matrix& operator -= (Matrix const&);
    	Matrix& operator * (const double&);	//performs multiplication of the matrix with given  number on the right,
	friend Matrix& operator * (const double&, const Matrix&);    //performs multiplication of the matrix with given  number on the left,
	friend std::istream& operator>>(std::istream&, Matrix&);     //reads the data from the file, performs validations and fills the matrix in case of correctness
	friend std::ostream& operator<<(std::ostream&, Matrix&);     //print the content of the matrix and saves it to the file.
        ~Matrix();
private:
	double **data;
	int rows;
	int cols;
};
#endif
