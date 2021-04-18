#include"matrix.h" 
#include<iostream>
#include<cassert>
#include<fstream>
#include<unistd.h>
#include<stdlib.h> 
#include<time.h>
#include<cstring>

void convert_to_double(const std::string& str, double& result)
{
	try {
		result = std::stod(str);
	} catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
}

Matrix::Matrix(int x, int y)
	: data(0)
	, rows(x)
	, cols(y)
{
	assert(rows > 0);
	assert(cols > 0);
	data = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		data[i] = new double [cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& copy_matrix)
	: rows(copy_matrix.rows)
	  , cols(copy_matrix.cols)
{
	assert(rows > 0);
	assert(cols > 0);
	data = new double* [rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new double [cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = copy_matrix.data[i][j];
		}
	}
}

Matrix& Matrix::operator = (const Matrix& mat) {
	if (this != &mat) {
		if (rows != mat.rows || cols != mat.cols) {
			delete data;
			assert(data == 0);
			rows = mat.rows;
			cols = mat.cols;
			data = new double*[rows];
			for (int i = 0; i < rows; ++i)
				data[i] = new double[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = mat.data[i][j];
			}
		}
	}
	return *this;
}
 /*
double* Matrix::operator[](const int index)
{
	assert (index >= 0);
	try
	{
		return data[index];
	}
	catch (...)
	{
		std::cout << "Out-of-bounds exception captured!\n";
	}
}
*/
double* Matrix::operator[](const int index)
{
	std::cout<<data[rows *cols*sizeof(double)];
	std::cout<<data[index];
        assert (index >= 0);
        assert (data[index] <= data[rows *cols*sizeof(double)] && data[index] >= data[0]);
        return data[index];
}

bool Matrix::operator == (const Matrix& mat) const
{
	if (rows != mat.rows || cols != mat.cols) {
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j=0; j<cols; j++) {
			if ( data[i][j] != mat.data[i][j]) {
				return false;
			}
		}
	}
	return true ;
}

Matrix Matrix::operator + (const Matrix& other)
{
	if (rows == other.rows && cols == other.cols) {
		Matrix temp(rows,cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				temp .data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return temp;
	}
	throw std::logic_error {"The dimensions of the matrix do not match."};
}

Matrix& Matrix::operator += (const Matrix& other)
{
	*this = *this + other;
	return *this;
}

Matrix  Matrix::operator - (const Matrix& other)
{
	if (rows == other.rows && cols == other.cols) {
		Matrix temp(rows,cols);
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				temp.data[i][j] = data[i][j] - other.data[i][j];
			}
		}
		return temp;
	}
	throw std::logic_error {"The dimensions of the matrix do not match."};
}

Matrix& Matrix::operator -= (const Matrix& other)
{
	*this = *this - other;
	return *this;
}

Matrix Matrix::operator * (const Matrix& mat)
{
	if (cols == mat.rows) {
		Matrix temp(rows,mat.cols);
		for (int i = 0; i < rows; i++) {
			for(int j = 0; j < mat.cols; j++) {
				for(int k = 0; k < cols; k++) {
					temp.data[i][j] += data[i][k] * mat.data[k][j];
				}
			}
		}
		return temp;
	}
	throw std::logic_error {"The dimensions of the matrix are incorrect."};
}

Matrix& Matrix::operator *= (const Matrix& mat)
{
	if (rows == cols && mat.rows == mat.cols && rows == mat.rows) { //ete qarakusayin matrixner en nor tuyl enq talis
		*this = *this * mat;
		return *this;
	}
	throw std::logic_error {"The dimensions of the matrix are incorrect."};
}

Matrix& Matrix::operator * (const double& number)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = data[i][j] * number;
		}
	}
	return *this;
}
/*
Matrix& operator * (const double& number, Matrix& mat)
{
        Matrix temp(mat.rows, mat.cols);
	temp = mat * number;
	return temp;
}
*/
/*
Matrix operator * (const double& number, const Matrix& mat)
{
	Matrix temp(mat.rows, mat.cols);
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			temp.data[i][j] = number * mat.data[i][j];
		}
	}
	return temp;
}
*/
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete [] data[i];
	}
	delete [] data;
	data = 0;
	cols = 0;
	rows = 0;
}

bool Matrix::check_dimensions_of_matrix(const std::string& path)
{
	std::string str1_row;
	int row_count = 0, column_count = 0, i = 0;
	std::ifstream file_input(path);
	if ( ! file_input.is_open()) {
		std::cout << " File isn't open." << std::endl;
		return false;
	}
	while (getline(file_input, str1_row)) {
		if (str1_row[0] != '\0') {
			row_count++;
			column_count = 0;
			for ( i = 0; str1_row[i] != '\0'; i++) {
				if (str1_row[i] == ' ') {
					if (i != 0 && str1_row[i-1] != ' ') {
						column_count++;
					}
				}
			}
			if (str1_row[i] == '\0') {
				if (i != 0 && str1_row[i-1] != ' ') {
					column_count++;
				}
			}
			if ((column_count) % cols != 0 || column_count / cols != 1) {
				std::cout << "The number of columns is incorrect." << std::endl;
				return false;
			}
		}
	}
	if (row_count % rows != 0 || row_count / rows != 1) {
		std::cout << "The number of rows is incorrect." << std::endl;
		return false;
	}
	file_input.close();
	return true ;
}

std::istream& operator >> (std::istream& in, Matrix& matrix)
{
	std::string file_path;
	double result = 0;
	int i = 0;
	int j = 0;
	std::cout << "Enter file name: ";
	in >> file_path;
	if (matrix.check_dimensions_of_matrix(file_path) == false) {
		throw std::logic_error {"The dimensions of the matrix and matrix int the file do not math."};
	} else {
		std::string str = "";
		std::string data1 = "";
		std::ifstream file_input(file_path);
		if ( ! file_input.is_open()) {
			throw std::ifstream::failure {"File isn't open."};
		}
		while (getline(file_input, str)) {
			assert(j == 0);
			for (int k = 0; str[k] != '\0'; k++) {
				if (! isspace(str[k])) {
					data1 += str[k];
				} else {
					if (data1 != "") {
						convert_to_double(data1, result);
						matrix.data[i][j] = result;
						data1 = "";
						j++;
					}
				}
			}
			if (data1 != "") {
				convert_to_double(data1, result);
				matrix.data[i][j] = result;
				data1 = "";
			}
			i++;
			j = 0;
		}
		assert(i == matrix.rows);
		file_input.close();
	}
	return in;
}

std::ostream& operator << (std::ostream& out, Matrix& matrix)
{
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.cols; ++j) {
			out << matrix.data[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}
