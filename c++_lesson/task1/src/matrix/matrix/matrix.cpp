#include<iostream>
#include"matrix.h"

Matrix::Matrix(int x,int y): rows(x),cols(y)
{
	data = new double*[rows];
	for (int i = 0; i < rows; ++i)
    	data[i] = new double[cols];

}

Matrix::Matrix(Matrix$ copy_matrix): rows(copy_matrix.rows),cols(copy_matrix.cols){
	matrix = new int*[rows];
	for (int i=0; i<rows; i++) {
		array[i] = new int[cols];
		}
	for (int i=0; i<row; i++) {
		for (int j=0; j<cols; j++) {
			matrix[i][j] = copy_matrix.matrix[i][j];
		}
	}
}
Matrix& Matrix::operator = (const Matrix& mat) {

	if (this != &mat) {
		if(rows != mat.rows || cols != mat.cols) {
			rows = mat.rows;
			cols = mat.cols;
			data = new double*[rows];
			for (int i = 0; i < rows; ++i)
				data[i] = new double[cols];
		}
		for (int i=0; i<row; i++) {
			for (int j = 0; j<cols; j++) {
				matrix[i][j] = mat.matrix[i][j];
			}
		}
		return *this;
       }
       throw std::underflow_error {"Matrix is empty"};
}

bool Matrix::operator == (const Matrix& mat) const
{
	if (rows != mat.rows || cols != mat.col) {
		return false;
	}
	for (int i = 0; i < row; i++) {
                for (int j=0; j<cols; j++) {
                       if ( matrix[i][j] != mat.matrix[i][j]) {
		       	return false;
		       }
                }
        }
	return true ;
}
Matrix& Matrix::operator + (const Matrix& other) const 
{
    if (rows == other.rows || cols != other.cols)
    {
	 Matrix temp(rows,cols);
         for(int i = 0; i < rows; i++) {
             for(int j = 0; j < cols; j++) {
                 temp.Mat[i][j] += other.Mat[i][j] + Mat[i][j];
    	     }
	 }
    }
    return temp;//else petqe avelacnem
}
Matrix& Matrix::operator += (const Matrix& other) const
{
    if (rows == other.rows || cols != other.cols) {
         for(int i = 0; i < rows; i++)
             for(int j = 0; j < cols; j++)
                 Mat[i][j] = Mat[i][j] + other.Mat[i][j];
    }
    return *this;//else petqe avelacnem
}
Matrix& Matrix::operator - (const Matrix& other) const
{
    if (rows == other.rows || cols != other.cols)
    {
         Matrix temp(rows,cols);
         for(int i = 0; i < rows; i++) {
             for(int j = 0; j < cols; j++) {
                 temp.Mat[i][j] += other.Mat[i][j] - Mat[i][j];
             }
         }
    }
    return temp;//else petqe avelacnem
}
Matrix& Matrix::operator -= (const Matrix& other) const
{
    if (rows == other.rows || cols != other.cols) {
         for(int i = 0; i < rows; i++)
             for(int j = 0; j < cols; j++)
                 Mat[i][j] = Mat[i][j] - other.Mat[i][j];
    }
    return *this;//else petqe avelacnem
}

Matrix& operator * (const Matrix& mat)
{
    if (cols == mat.rows)
    {
      Matrix temp(rows, mat.cols); 
      for(int i=0;i<rows;i++)
          for(int j=0;j<mat.cols;j++)
            for(int k =0;k<cols;k++)
                temp[i][j]+=Mat[i][k]*other.Mat[i][j];
      return temp;          
    }
}
Matrix::~Matrix(){
	for (int i = 0; i < rows; ++i)
	    delete [] data[i];
	    delete [] data;
}


std::istream& operator>>(std::istream& in, Matrix& matrix){
}
std::ostream& operator<<(std::ostream& out, Matrix& matrix){
}
