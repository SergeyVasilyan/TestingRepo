#include<iostream>
#include"matrix.h"

Matrix::Matrix(int x,int y): rows(x),cols(y){
	data = new double*[rows];
	for (int i = 0; i < rows; ++i)
    	data[i] = new double[cols];

}
Matrix::~Matrix(){
	for (int i = 0; i < rows; ++i)
	    delete [] data[i];
	    delete [] data;

}
std::istream& operator>>(std::istream& in, Matrix& matrix){
for (int i = 0; i < matrix.rows; ++i){
	for (int j = 0; j< matrix.cols; ++j){
	in>>matrix.data[i][j];
	}
}
return in;
}
std::ostream& operator<<(std::ostream& out, Matrix& matrix){
	for (int i = 0; i < matrix.rows; ++i){
        for (int j = 0; j < matrix.cols; ++j){
        out<<matrix.data[i][j]<<"  ";
        }
	out<<std::endl;
}
return out;

}
