#include<iostream>
#include"matrix.h"
#include <cassert>

void check_double(const std::string& str, double& result)
{
    try {
        result = std::stod(str);
    } catch (std::exception& i) {
        throw ("Error.") ;//sa poxel
    }
}
std::string rand_filename() {
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
Matrix::Matrix(int x,int y): rows(x),cols(y)
{
	data = new double*[rows];
	for (int i = 0; i < rows; ++i)
    	data[i] = new double[cols];
}
Matrix::Matrix(const Matrix& copy_matrix): rows(copy_matrix.rows),cols(copy_matrix.cols)
{
	data = new int*[rows];
	for (int i=0; i<rows; i++) {
		array[i] = new int[cols];
	}
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			data[i][j] = copy_matrix.data[i][j];
		}
	}
}
Matrix& Matrix::operator = (const Matrix& mat) //sxal bAner ka
{
	if (this != &mat) {
		if(rows != mat.rows || cols != mat.cols) {
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
      // throw std::underflow_error {"Matrix is empty"};
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
Matrix& Matrix::operator + (const Matrix& other) const
{
    if (rows == other.rows && cols == other.cols) {
		 Matrix temp(rows,cols);
         for(int i = 0; i < rows; i++) {
             for(int j = 0; j < cols; j++) {
                 temp.data[i][j] += other.data[i][j] + data[i][j];
    	     }
	 }
    return temp;//else petqe avelacnem
	}
	else {}//anel
}
Matrix& Matrix::operator += (const Matrix& other) const
{
    if (rows == other.rows || cols != other.cols) {
         for(int i = 0; i < rows; i++)
             for(int j = 0; j < cols; j++)
                 data[i][j] = data[i][j] + other.data[i][j];
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
                 temp.data[i][j] += other.data[i][j] - data[i][j];
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
                 data[i][j] = data[i][j] - other.data[i][j];
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
                temp[i][j]+=data[i][k]*mat.data[k][j];
      return temp;
    }
}

Matrix& Matrix::operator * (const Matrix& mat)
{
    if (cols == mat.rows)
    {
      Matrix temp(rows,cols);
	  temp = this ;
      for(int i=0;i<rows;i++)
          for(int j=0;j<mat.cols;j++)
            for(int k =0;k<cols;k++)
                data[i][j]+=temp.data[i][k]*mat.data[k][j];
      return temp;
    }
}
Matrix& Matrix::operator * (const double& number)
{
	for (int i=0; i<row; i++) {
            for (int j = 0; j<cols; j++) {
                data[i][j] = data[i][j] * number;
            }
        }
    return *this;
}
Matrix& operator * (const double& number, const Matrix& mat)
{
    for (int i=0; i<row; i++) {
            for (int j = 0; j<cols; j++) {
                data[i][j] = number * mat.data[i][j];
            }
        }
    return *this;
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i)
	    delete [] data[i];
	    delete [] data;
}

bool Matrix:: check_file(std::string path, const int row, const int col)
{
	std::string str1_row;
    int row_count = 0, column_count = 0;
    std::ifstream file1_input(path);
    if ( ! file_input1.is_open()) {
        std::cout << " file isn't open" << std::endl;
        return false;
	} 
    while (getline(file_input1, str1_row)) {
        if (str1_row[0] != '\0') {
            row_count++;
            column_count = 0;
            for (i = 0; str1_row[i] != '\0'; i++) {
                if (i != 0 && str1_row[i] == ' ' ) {
                    if(i != 0 && str1_row[i-1] != ' ') {
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
    file_input1.close();
}
std::istream& operator >> (std::istream& in, Matrix& matrix)
{
	std::string file_path;
	double result;
	int i = 0, j = 0;
	in >> file_path;
	if (check_file(file_path, rows,  cols) == false) {
		//bla bla bla
	} else {
		std::string str = "";
		std::string data1 = "";
		std::ifstream file_input(path);
		if ( ! file_input.is_open()) {
			std::cout << "File isn't open" << std::endl;
			return -1;
		}
		while (getline(file_input, str)) {
			assert(j == 0)
				for (int i = 0; str[i] != '\0'; i++) {
					if (! isspace(str[i])) {
						data1 += str[i];
					} else {
						if (data1 != "") {
							check_double(data1, result);
							data[i][j] = result;
							j++;
						}
					}
				}
			if (data1 != "") {
				check_double(data1, result);
				data[i][j] = result;
			}
			i++;
			j=0;
		}
		assert( i == rows)
	}
std::ostream& operator<<(std::ostream& out, Matrix& matrix) 
{
	std::string file_name;
	for (int i = 0; i < matrix.rows; ++i){
		for (int j = 0; j < matrix.cols; ++j){
			out<<matrix.data[i][j]<<"  ";
		}
	}
	out<<std::endl;
	while (true) {
		file_name = rand_filename();
		if (access (file_name, F_OK)) {  //File doesn't exist.
			std::ofstream myfile(filename);
			for ( int i = 0; i < matrix.rows; i++ )
			{
				for ( int j = 0; j < matrix.cols; j++ ) {
					myfile << this->matrix.data[i][j] << "  ";
				}
				myfile << std::endl;
			}
			myfile.close();}
			break;
	}
}
