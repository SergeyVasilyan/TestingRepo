#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
/**************
   A class that creates an matrix object,
   which dimensions can not be changed during the object lifetime.
***************/
class Matrix
{
public:
	Matrix(const int, const int); // overloaded constructor that creates a matrix with  ROWxCOL dimensions and fills the matrix with zero.
	Matrix(const Matrix&); // overloaded copy constructor.
	double* operator[](const int); // changes and return the value of a specified element.
	void change_element(std::string&, double&, int, int); // converts data and assigns to the corresponding element of the matrix.
	void check_dimensions_of_matrix(std::string&); // check dimensions of matrix and matrix in file.
   	Matrix& operator = (const Matrix&); // overloaded assignment operator.
   	bool operator == (const Matrix&) const; // overloaded equality check operator.
	Matrix operator * (const Matrix&); // scalar product of two matrices.
	Matrix& operator *= (Matrix const&); // scalar product of two matrices via assignment to the first matrix.
	Matrix operator + (const Matrix&); // overloaded addiction operator.
	Matrix& operator += (Matrix const&); // overloaded addiction with assignment operator.
	Matrix operator - (const Matrix&); // overloaded substation operator.
	Matrix& operator -= (Matrix const&); // overloaded substation with assignment operator.
   	Matrix& operator * (const double&); // performs multiplication of the matrix with given number on the right.
	friend Matrix operator * (const double&, const Matrix&); // performs multiplication of the matrix with given number on the left.
	friend std::istream& operator>>(std::istream&, Matrix&); // reads the data from the file, performs validations and fills the matrix in case of correctness.
	friend std::ostream& operator<<(std::ostream&, Matrix&); // prints the content of the matrix.
    ~Matrix(); // overloaded matrix destructor.
private:
	static void convert_to_double(const std::string&, double&); // returns converted double type value if possible.
	static void check_dimension(int, int);
private:
	double** data;
	int rows;
	int cols;
};
#endif
