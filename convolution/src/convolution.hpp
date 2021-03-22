#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
class Matrix
{
public:
	int layer_size;
	int row_size;
	int column_size;
	int ***array;
	Matrix()=default;
	Matrix(int, int, int);
	Matrix(const Matrix&);//	
	~Matrix();
	Matrix& operator=(const Matrix&);
	bool fill_matrix_from_file(std::string);
	bool save_output_in_file(std::string);
protected:
	bool cast_to_int_and_add_to_matrix(std::string&,
									   const int&,
									   const int&,
									   int&, int&,
									   bool&, bool&);
	bool check_line_and_fill_matrix(const std::string&,
									const int&,
									const int&,
									const int&,
									int&, bool&);
	bool read_from_file_by_line(std::ifstream&);
};

class Filter: public Matrix
{
public:
	Filter(int,int,int);
	bool change_filter(std::string);
};

void helper();
void input_filenames_in_vector(std::vector<std::string>&);
bool is_empty_vector(const std::vector<std::string>&);
bool filter_change_check(Filter&);
void take_filters_do_work(const Matrix&,
						  const int,
						  const std::vector<std::string>);
bool create_objects_and_fill(const std::vector<std::string>,
							 const std::vector<std::string>);
void run_program();
bool check_overflow_of_mul(int, int);
bool check_sum_overflow(int, int);
bool convolution(const Matrix&,
				 const Filter&,
				 Matrix&);
