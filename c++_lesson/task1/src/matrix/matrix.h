#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
/**************
   A class that creates an matrix object,
   which dimensions can not be changed during the object lifetime.
***************/
class Matrix
{
public:
	Matrix(const int, const int);
	Matrix(const Matrix&);
	double* operator[](const int);
	//const double* operator[](const int&);
	friend bool check_dimensions_of_matrix(std::string, const int, const int);
   	Matrix& operator = (const Matrix&);
   	bool operator == (const Matrix&) const;
	Matrix& operator - ();
	Matrix operator * (const Matrix&);
	Matrix& operator *= (Matrix const&);
	Matrix operator + (const Matrix&);
	Matrix& operator += (Matrix const&);
	Matrix operator - (const Matrix&);
	Matrix& operator -= (Matrix const&);
    Matrix& operator * (const double&);	
	friend Matrix operator* (const double&, const Matrix&); 
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, Matrix&);
    ~Matrix();
private:
	static void check_double(const std::string&, double&);
	static std::string rand_filename();
private:
	double** data;
	int rows;
	int cols;

};
#endif
