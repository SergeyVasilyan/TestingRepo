#include<iostream>
#include"matrix.h"
#include<cassert>
#include<fstream>
#include <unistd.h>
static void check_double(const std::string& str, double& result)
{
	try {
		result = std::stod(str);
	} catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
}
static std::string rand_filename() {
	const int CHARS_PER_ABC = 26;
	std::string file_name  = "";
	for(int i = 0; i < 6; i++) {
		srand(static_cast<unsigned int>(time(NULL)));
		int char_num = rand() % CHARS_PER_ABC;
		file_name += 'a' + static_cast<char>(char_num);
	} 
	file_name = file_name + "_matrix.txt";
	return file_name;
}
Matrix::Matrix(int x,int y): rows(x),cols(y) {
	data = new double* [rows];
	for (int i = 0; i < rows; ++i){
		data[i] = new double [cols];
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			data[i][j] = 0;       
		}
	}
}
Matrix::Matrix(const Matrix& copy_matrix):rows(copy_matrix.rows),cols(copy_matrix.cols) {
	data = new double* [rows];
	for (int i=0; i<rows; i++) {
		data[i] = new double [cols];
	}
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			data[i][j] = copy_matrix.data[i][j];
		}
	}
}
Matrix& Matrix::operator = (const Matrix& mat) {
	if (this != &mat) {
		if (rows != mat.rows || cols != mat.cols) {
			delete data;
			rows = mat.rows;
			cols = mat.cols;
			data = new double*[rows];
			for (int i = 0; i < rows; ++i)
				data[i] = new double[cols];
		}
		for (int i=0; i<rows; i++) {
			for (int j = 0; j<cols; j++) {
				data[i][j] = mat.data[i][j];
			}
		}
	}
	return *this;
}
bool Matrix::operator == (const Matrix& mat) const {
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
Matrix  Matrix::operator + (const Matrix& other) {
	if (rows == other.rows && cols == other.cols) {
		Matrix temp(rows,cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				temp.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return temp;
	}
	std::cout << "The dimensions of the matrix do not match." << std::endl;
	exit(1);
}
Matrix& Matrix::operator += (const Matrix& other) {
	if (rows == other.rows || cols != other.cols) {
		for (int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				data[i][j] += other.data[i][j];
			}
		}
		return *this;
	}
	std::cout << "The dimensions of the matrix do not match." << std::endl;
        exit(1);  //no eto netochno
}
Matrix  Matrix::operator - (const Matrix& other) {
	if (rows == other.rows || cols != other.cols) {
		Matrix temp(rows,cols);
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				temp.data[i][j] = data[i][j] - other.data[i][j];
			}
		}
	return temp;
	}
	std::cout << "The dimensions of the matrix do not match." << std::endl;
    exit(1);
}
Matrix& Matrix::operator -= (const Matrix& other) {
	if (rows == other.rows || cols != other.cols) {
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				data[i][j] -= other.data[i][j];
			}
		}
		return *this;
	}
	std::cout << "The dimensions of the matrix do not match." << std::endl;
        exit(1);
}
Matrix Matrix::operator * (const Matrix& mat) {
    if (cols == mat.rows) {
        Matrix temp(rows,cols);
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < mat.cols; j++) {
                for(int k = 0; k < cols; k++) {
                    temp.data[i][j] += data[i][k] * mat.data[k][j];
                }
            }
        }
        return temp;
    }
    std::cout << "The dimensions of the matrix are incorrect." << std::endl;
    exit(1);
}

Matrix& Matrix::operator *= (const Matrix& mat) {
	if (cols == mat.rows) {
		Matrix temp(rows,cols);
		temp = *this;//no eto netochno
		for (int i = 0; i < rows; i++) {
			for(int j = 0; j < mat.cols; j++) {
				for(int k = 0; k < cols; k++) {
					data[i][j] += temp.data[i][k] * mat.data[k][j];
				}
			}
		}
		return *this;
	}
	std::cout << "The dimensions of the matrix are incorrect." << std::endl;
	exit(1);
}
Matrix& Matrix::operator * (const double& number) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = data[i][j] * number;
		}
	}
	return *this;
}
Matrix operator* (const double& number, const Matrix& mat) {
    Matrix temp(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            temp.data[i][j] = number * mat.data[i][j];
        }
    }
    return temp;
}
Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i){
		delete [] data[i];
	}
	delete [] data;
}
bool check_dimensions_of_matrix(std::string path, const int row, const int col) {
	std::string str1_row;
	int row_count = 0, column_count = 0, i=0;
	std::ifstream file_input(path);
	if ( ! file_input.is_open()) {
		std::cout << " file isn't open" << std::endl;
		return false;
	}
	while (getline(file_input, str1_row)) {
		if (str1_row[0] != '\0') {
			row_count++;
			column_count = 0;
			for ( i = 0; str1_row[i] != '\0'; i++) {
				if (i != 0 && str1_row[i] == ' ' ) {
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
			if ((column_count) % col != 0 || (column_count+1) / col != 1 ) {
				std::cout << "The number of columns is incorrect." << std::endl;
				return false;
			}
		}
	}
	if (row_count%row != 0 || row_count/row != 1) {
		std::cout << "The number of rows is incorrect." << std::endl;
		return false;
	}
	file_input.close();
}
std::istream& operator >> (std::istream& in, Matrix& matrix)
{
	std::string file_path;
	double result;
	int i = 0, j = 0;
	std::cout<<"Enter file name: ";
	in >> file_path;
	if (check_dimensions_of_matrix(file_path, matrix.rows, matrix.cols) == false) {
		std::cout << "The file does not exist for these name." << std::endl;
		exit(1);
	} else {
		std::string str = "";
		std::string data1 = "";
		std::ifstream file_input(file_path);
		if ( ! file_input.is_open()) {
			std::cout << "File isn't open" << std::endl;
			exit(1);
		}
		while (getline(file_input, str)) {
			assert(j == 0);
			for (int i = 0; str[i] != '\0'; i++) {
				if (! isspace(str[i])) {
					data1 += str[i];
				} else {
					if (data1 != "") {
						check_double(data1, result);
						matrix.data[i][j] = result;
						j++;
					}
				}
			}
			if (data1 != "") {
				check_double(data1, result);
				matrix.data[i][j] = result;
			}
			i++;
			j = 0;
		}
		assert( i == matrix.rows);
		file_input.close();
	}
}
std::ostream& operator << (std::ostream& out, Matrix& matrix) {
	std::string file_name;
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.cols; ++j) {
			out << matrix.data[i][j]<<"  ";
		}
	}
	out<<std::endl;
	while (true) {
		file_name = rand_filename();
		if (access (file_name, 0)) {  //File doesn't exist.
			std::ofstream myfile(file_name);
			for ( int i = 0; i < matrix.rows; i++ ) {
				for ( int j = 0; j < matrix.cols; j++ ) {
					myfile << matrix.data[i][j] << "  ";
				}
				myfile << std::endl;
			}
			myfile.close();
			break;
		}
	}
}
//https://ci-plus-plus-snachala.ru/?p=5993	
//http://www.c-cpp.ru/content/access
//
