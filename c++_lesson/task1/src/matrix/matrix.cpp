#include"matrix.h"
#include<iostream>
#include<cassert>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<cstring>

// returns converted double type value if possible.
void Matrix::convert_to_double(const std::string& str, double& result)
{
	try {
		result = std::stod(str);
	} catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
}

// overloaded constructor that creates a matrix with  ROW x COL dimensions.
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
	for (int i = 0; i < rows; i++) { // fills the matrix with zero.
		for (int j = 0; j < cols; j++) {
			data[i][j] = 0;
		}
	}
}
// overloaded copy constructor.
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

// overloaded assignment operator.
Matrix& Matrix::operator = (const Matrix& mat) {
	if (this != &mat) { // checks if the same matrix weren't assigned, if not and if they don't match in size then deletes *this of matrix
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

// changes and return the value of a specified element.
double* Matrix::operator[](const int index)
{
	assert (index >= 0);
	assert (index < rows);
	return data[index];
}

// overloaded equality check operator.
bool Matrix::operator == (const Matrix& mat) const
{
	if (rows != mat.rows || cols != mat.cols) { // if the dimensions don't match or at least one element doesn't match then false
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if ( data[i][j] != mat.data[i][j]) {
				return false;
			}
		}
	}
	return true ;
}

bool Matrix::square_matrix()
{
	return rows == cols;
}

// overloaded addiction operator.
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

// overloaded addiction with assignment operator.
Matrix& Matrix::operator += (const Matrix& other)
{
	*this = *this + other;
	return *this;
}

// overloaded substation operator.
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

// overloaded substation with assignment operator.
Matrix& Matrix::operator -= (const Matrix& other)
{
	*this = *this - other;
	return *this;
}

// scalar product of two matrices.
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

// scalar product of two matrices via assignment to the first matrix.
Matrix& Matrix::operator *= (const Matrix& mat)
{
	if (rows == cols && mat.rows == mat.cols && rows == mat.rows) { // if it is a square matrix, then calculate the dot product.
		*this = *this * mat;
		return *this;
	}
	throw std::logic_error {"The dimensions of the matrix are incorrect."};
}

// performs multiplication of the matrix with given number on the right.
Matrix& Matrix::operator * (const double& number)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = data[i][j] * number;
		}
	}
	return *this;
}

// performs multiplication of the matrix with given number on the right.
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

void Matrix::check_dimension(int dim_count, int dim)
{
	if ((dim_count) % dim != 0 || dim_count / dim != 1) {
		throw std::logic_error {"The dimensions of the matrix and matrix in the file do not match."};
	}
}

// check dimensions of matrix and matrix in file.
void Matrix::check_dimensions_of_matrix(std::string& path)
{
	std::string str1_row; // the next line of the file is hold.
	int row_count = 0; // counts the number of rows in a file.
        int column_count = 0; // counts the number of columns in a file.
        int i = 0;
	std::ifstream file_input(path);
	if ( ! file_input.is_open()) {
		throw std::ifstream::failure {"File isn't open."};
	}
	while (getline(file_input, str1_row)) {
		if (str1_row[0] != '\0') {
			row_count++;
			assert(column_count == 0);
			for ( i = 0; str1_row[i] != '\0'; i++) {
				if (isspace(str1_row[i])) {
					if (i != 0 && str1_row[i-1] != ' ') {
						column_count++; // each time encounter a space , adds the value of the counter if there was no space before.
					}
				}
			}
			if (str1_row[i] == '\0') { // checks if last data was viewed, as there might not have been a space after the last data.
				if (i != 0 && str1_row[i-1] != ' ') {
					column_count++;
				}
			}
			check_dimension(column_count, cols); // Checks the number of columns in the file corresponds to the number of columns in the matrix.
			column_count = 0; // zero the counter by going to the next line of the file.
		}
	}
	check_dimension(row_count, rows); // Checks the number of rows in the file corresponds to the number of rows in the matrix.
	file_input.close();
}

// converts data and assigns to the corresponding element of the matrix.
void Matrix::change_element(std::string& data1, double& result, int i, int j)
{
	assert(i >= 0);
	assert(j >= 0);	
	if (data1 != "") {
		convert_to_double(data1, result);
		data[i][j] = result;
		data1 = "";
	}
}

// reads the data from the file, performs validations and fills the matrix in case of correctness.
std::istream& operator >> (std::istream& in, Matrix& matrix)
{
	std::string file_path;
	double result = 0;
	int i = 0;
	int j = 0;
	std::cout << "Enter file name: ";
	in >> file_path;
	matrix.check_dimensions_of_matrix(file_path);
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
				matrix.change_element(data1, result, i, j);
				j++;
			}
		}
		matrix.change_element(data1, result, i, j);
		i++;
		j = 0;
	}
	assert(i == matrix.rows);
	file_input.close();
	return in;
}

// prints the content of the matrix.
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

// overloaded matrix destructor.
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
