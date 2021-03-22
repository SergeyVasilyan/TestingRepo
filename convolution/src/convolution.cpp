#include "convolution.hpp"

const std::string MATRIX_PATH = "../test/matrix/";
const std::string FILTER_PATH = "../test/filter/";
const std::string OUTPUT_PATH = "../outputs/feature_map";
const int BASE_LAYER_SIZE = 1;
const int BASE_ROW_SIZE = 32;
const int BASE_COLUMN_SIZE = 32;
const int FILTER_LAYER_SIZE = 1;
const int FILTER_ROW_SIZE = 5;
const int FILTER_COLUMN_SIZE = 5;


Matrix::Matrix(int l_size, int r_size, int c_size):layer_size(l_size), row_size(r_size), column_size(c_size)
{
	this->array=new int**[l_size];
	for(int i = 0; i < l_size ; ++i){
		this->array[i] = new int*[r_size];
			for(int j = 0; j < c_size; ++j){
				this->array[i][j] = new int[c_size];
			}
	}
}

Matrix::Matrix(const Matrix& new_obj): layer_size(new_obj.layer_size), row_size(new_obj.row_size), column_size(new_obj.column_size)
{
	if(this != &new_obj){
		this->array=new int**[this->layer_size];
			for(int i = 0; i < this->layer_size ; ++i){
				this->array[i] = new int*[this->row_size];
					for(int j = 0; j < this->column_size; ++j){
						this->array[i][j] = new int[this->column_size];
					}
			}
		for( int i = 0; i < this->layer_size; ++i){
			for( int j = 0; j < this->row_size; ++j){
				for( int k = 0; k < this->column_size; ++k){
					this->array[i][j][k] = new_obj.array[i][j][k];
				}
			}
		}
	}
}

bool Matrix::cast_to_int_and_add_to_matrix(std::string& temp_string,
										   const int& layer_counter,
										   const int& row_counter,
										   int& column_counter,
										   int& sign,
										   bool& flag,
										   bool& digit_flag)
{
	if(layer_counter < this->layer_size){
		if(temp_string.length() < 10){
			this->array[layer_counter][row_counter][column_counter++] = sign * stoi(temp_string);
			temp_string = "";
			sign = 1;
			flag = true;
			digit_flag = false;
			return true;
		}else{
			std::cout<<"Invalid integer element " << std::endl;
			return false;
		}
	}else{
		std::cout << "Invalid layer count in file!" << std::endl;
		return false;
	}
}

bool Matrix::check_line_and_fill_matrix(const std::string& line,
										const int& layer_counter,
										const int& row_counter,
										const int& length,
										int& column_counter,
										bool& flag)
{
	int sign = 1;
	std::string temp_string = "";
	bool digit_flag = false;
	for( int i = 0; i < length; ++i){
		if(line[i] == '-' && temp_string == "" && 1 == sign){
			sign = -1;
			continue;
		}else if(line[i]<='9' && line[i] >= '0'){
			temp_string+=line[i];
			digit_flag = true;
			if(i == length-1){
				if(cast_to_int_and_add_to_matrix(temp_string, layer_counter,
												 row_counter, column_counter,
												 sign, flag, digit_flag))
					continue;
				else
					return false;
			}
		}else if(line[i] == ' ' && temp_string != "" && digit_flag){
			if(cast_to_int_and_add_to_matrix(temp_string, layer_counter,
											 row_counter, column_counter,
											 sign, flag, digit_flag))
				continue;
			else
				return false;
		}else{
			return false;
		}
	}
	return true;
}

bool Matrix::read_from_file_by_line(std::ifstream& fin)
{
	std::string line = "";
	int layer_counter = 0;
	int row_counter = 0;
	int length = 0;
	int column_counter = 0;
	bool flag = false;
	while(std::getline(fin, line)){
		length = line.length();
		if(!check_line_and_fill_matrix(line, layer_counter, row_counter,
									   length, column_counter, flag))
			return false;
		if(flag && column_counter == this->column_size){
			++row_counter;
			column_counter = 0;
			length = 0;
			flag = false;
			continue;
		}else if(false == flag && row_counter == this->row_size && this->layer_size > layer_counter){
			++layer_counter;
			row_counter = 0;
			column_counter = 0;
		}else if(this->column_size != column_counter){
			return false;
		}
		if( this->layer_size < layer_counter){
			std::cout << "Invalid input of matrix!" << std::endl;
			return false;
		}
		column_counter=0;
		flag = false;
	}
	return true;
}

bool Matrix::fill_matrix_from_file(std::string path){
	std::ifstream fin;
	fin.open(path);
	if(!fin){
		std::cout<<" File can not opened! " <<std::endl;
		return false;
	}
	if(!read_from_file_by_line(fin)){
		fin.close();
		return false;
	}
	fin.close();
	return true;
}

bool Matrix::save_output_in_file(std::string path){
	std::ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return false;
	}
	for (int i = 0; i < this->layer_size; ++i) {
		for (int j = 0; j < this->row_size; ++j) {
			for (int k = 0; k < this->column_size; ++k) {
				fout << this->array[i][j][k] << " ";
			}
			fout << std::endl;
		}
	}
	fout.close();
	return true;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if( this != &other || this->array != nullptr){
		this->layer_size = other.layer_size;
		this->row_size = other.row_size;
		this->column_size = other.column_size;
		for( int i = 0; i < this->layer_size; ++i){
			for( int j = 0; j < this->row_size; ++j){
				for( int k = 0; k < this->column_size; ++k){
					this->array[i][j][k] = other.array[i][j][k];
				}
			}
		}
	}
	return *(this);
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->layer_size; i++)
    {
        for (int j = 0; j < this->row_size; j++)
            delete[] this->array[i][j];
 
        delete[] this->array[i];
    }
 
    delete[] array;
}

Filter::Filter(int l_size, int r_size, int c_size):Matrix(l_size, r_size, c_size)
{}

bool Filter::change_filter(std::string path){
	return this->fill_matrix_from_file(path);
}

void input_filenames_in_vector(std::vector<std::string>& vector)
{
	std::string input = "";
	while(true){
		std::cin>>input;
		if("0" == input){
			std::cout<<"End of matrix inputs! " << std::endl;
			break;
		}
	vector.push_back(input);
	}
}

bool is_empty_vector(const std::vector<std::string>& vector)
{
	return vector.size() == 0;
}
bool filter_change_check(Filter& filter)
{
	std::string change_input = "";
	std::cout<<"Do yo want change this filter? [y/n]"<<std::endl;
	while(true){
		std::cin>>change_input;
		if(change_input == "n"){
			return true;
		}else if(change_input == "y"){
			std::cout<<"Please enter name of filter file. "<< std::endl;
			std::cin>>change_input;
			if(filter.change_filter(FILTER_PATH + change_input)){
				return true;
			}
			return false;
		}
		std::cout<<"Please enter only 'y' or 'n' ." << std::endl;
	}
}

void take_filters_do_work(const Matrix& matrix,
						  const int matrix_name_index,
						  const std::vector<std::string> filter_names_vector)
{
	Filter filter(FILTER_LAYER_SIZE,
				  FILTER_ROW_SIZE,
				  FILTER_COLUMN_SIZE);
	Matrix output_matrix(BASE_LAYER_SIZE - FILTER_LAYER_SIZE + 1,
						 BASE_ROW_SIZE - FILTER_ROW_SIZE + 1,
						 BASE_COLUMN_SIZE - FILTER_COLUMN_SIZE + 1);
	for ( int filter_name_index = 0; filter_name_index < filter_names_vector.size(); ++filter_name_index){
		if(filter.fill_matrix_from_file(FILTER_PATH + filter_names_vector[filter_name_index])){
			if(filter_change_check(filter)){
				if(convolution(matrix, filter, output_matrix)){
					output_matrix.save_output_in_file(OUTPUT_PATH
													  + std::to_string(matrix_name_index)
													  + std::to_string(filter_name_index));
				}else{
					std::cout<<"Overflow error!" << std::endl;
					return ;
				}
			}else{
				std::cout << "Error of changing filter file!" << std::endl;
				return;
			}
		}else{
			std::cout<<"Error of reading from filter file!"<<std::endl;
			return ;
		}
	
	}
}

bool create_objects_and_fill(const std::vector<std::string> matrix_names_vector,
							 const std::vector<std::string> filter_names_vector)
{
	Matrix base_matrix(BASE_LAYER_SIZE,
					   BASE_ROW_SIZE,
					   BASE_COLUMN_SIZE);
	for(int matrix_name_index = 0; matrix_name_index < matrix_names_vector.size(); ++matrix_name_index){
		if(base_matrix.fill_matrix_from_file(MATRIX_PATH + matrix_names_vector[matrix_name_index])){
			take_filters_do_work(base_matrix,
								 matrix_name_index,
								 filter_names_vector);
		}else{
			std::cout<<"Error of reading from matrix file! "<<std::endl;
			return false;
		}
	}
	return true;
}

void run_program()
{
	std::vector<std::string> matrix_names;
	std::vector<std::string> filter_names; 
	input_filenames_in_vector(matrix_names);
	if(is_empty_vector(matrix_names)){
		std::cout << "Not inputted names of matrices." <<std::endl;
		return;
	}
	input_filenames_in_vector(filter_names);
	if(is_empty_vector(filter_names)){
		std::cout << "Not inputted names of filters." <<std::endl;
		return;
	}
	if(!create_objects_and_fill(matrix_names, filter_names))
		std::cout << "Error of creation objects!" << std::endl;
}

bool check_overflow_of_mul(int base_element, int filter_element){
		if(base_element > 0 && filter_element > 0){
			if(INT_MAX/filter_element < base_element)
				return false;
		}else if(base_element < 0 && filter_element < 0){
			if(INT_MAX/filter_element > base_element)
				return false;
		}else if(base_element > 0 && filter_element < 0){
			if(INT_MIN/base_element > filter_element)
				return false;
		}else if(base_element < 0 && filter_element > 0){
			if(INT_MIN/filter_element > base_element)
				return false;
		}
	return true;
}


bool check_sum_overflow( int sum, int mul){
	if(sum>0){
		if(INT_MAX-sum<mul)
			return false;
	}else if(sum<0){
		if(INT_MIN - sum>mul)
			return false;
	}
	return true;

}

bool convolution(const Matrix& base, const Filter& filter, Matrix& future_map)
{
	int sum=0, mul;
	for( int i = 0; i < future_map.layer_size; ++i){
		for( int j = 0; j < future_map.row_size; ++j){
			for( int k = 0; k < future_map.column_size; ++k){
				for ( int l = 0; l < filter.layer_size; ++l){
					for( int m = 0; m < filter.row_size; ++m){
						for( int n = 0; n < filter.column_size; ++n)
							if(check_overflow_of_mul(base.array[i+l][j+m][k+n],filter.array[l][m][n])){ 
								mul=base.array[i+l][j+m][k+n]*filter.array[l][m][n];
								if(check_sum_overflow(sum, mul)){
									sum+=mul;
								}else{
									return false;
								}
							}else{
								return false;
							}
					}
				}
			future_map.array[i][j][k]=sum;
			sum=0;
			}
		}
	}
	return true;
}

void helper()
{
std::cout << "******************************************************************************" << std::endl;
std::cout << "*                                  HELPER                                    *" << std::endl;
std::cout << "*1.Enter names of matrices files that are in test/matrix directory!          *" << std::endl;
std::cout << "*For example 'matrix', 'matrix1', 'matrix2' etc. If you enter file name which*" << std::endl;
std::cout << "*doesn't exist application will show message and exits. After finishing names*" << std::endl;
std::cout << "*input enter '0' symbol for next step.                                       *" << std::endl;
std::cout << "*2.Like previous step enter filters names that are in test/filter directory. *" << std::endl;
std::cout << "*For example 'filter', 'filter1' etc. If you enter file name which doesn't   *" << std::endl;
std::cout << "*exist application will show message and ends its work. After finishing file *" << std::endl;
std::cout << "*names input enter '0' symbol for next step.                                 *" << std::endl;
std::cout << "*3. If names of matrices and filters are exist you can change every filter   *" << std::endl;
std::cout << "*before convolution will be done by entering new filter file name.           *" << std::endl;
std::cout << "*4. After convolution all output feature maps are saved in outputs/ directory!*" << std::endl;
std::cout << "******************************************************************************" << std::endl;
}
