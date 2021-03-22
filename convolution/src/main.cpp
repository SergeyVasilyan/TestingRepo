#include "convolution.hpp"

/*const std::string MATRIX_PATH = "../test/matrix/";
const std::string FILTER_PATH = "../test/filter/";
const std::string OUTPUT_PATH = "../outputs/feature_map";
const int BASE_LAYER_SIZE = 1;
const int BASE_ROW_SIZE = 32;
const int BASE_COLUMN_SIZE = 32;
const int FILTER_LAYER_SIZE = 1;
const int FILTER_ROW_SIZE = 5;
const int FILTER_COLUMN_SIZE = 5;
*/
int main(int argc, char* argv[]){
/*std::string input, change_input;
std::vector<std::string> matrix_names;
std::vector<std::string> filter_names;
std::cout<<"Please enter names of base matrix files! "<<std::endl;
while(true){
std::cin>>input;
if("0" == input){
	std::cout<<"End of matrix inputs! " << std::endl;
	break;
}
	matrix_names.push_back(input);
}
if(matrix_names.size()<=0)
{
	std::cout<<"Invalid matrix names input!" << std::endl;
	return 1;
}
Matrix base(BASE_LAYER_SIZE, BASE_ROW_SIZE, BASE_COLUMN_SIZE);
if(matrix_names.size() != 0){
	std::cout<<"Now please enter filter files names! "<< std::endl;
	while(true){
		std::cin>>input;
		if("0" == input){
			std::cout<<"End of filter file names input! "<< std::endl;
			break;
		}
		filter_names.push_back(input);
	}
}
if(filter_names.size()<=0){
	std::cout<<"Invalid filter input! "<<std::endl;
	return 1;
}
Filter filter(FILTER_LAYER_SIZE, FILTER_ROW_SIZE, FILTER_COLUMN_SIZE);
Matrix output(BASE_LAYER_SIZE - FILTER_LAYER_SIZE + 1,
			 BASE_ROW_SIZE - FILTER_ROW_SIZE + 1,
			 BASE_COLUMN_SIZE - FILTER_COLUMN_SIZE + 1);*/
/*for( int i = 0; i < matrix_names.size(); ++i){
	if(base.fill_matrix_from_file(MATRIX_PATH + matrix_names[i])){
		for ( int j = 0; j < filter_names.size(); ++j){
			if(filter.fill_matrix_from_file(FILTER_PATH + filter_names[j])){
				if(convolution(base, filter, output)){
					output.save_output_in_file(OUTPUT_PATH + std::to_string(i) + std::to_string(j));
				}else{
					std::cout<<"Overflow error!" << std::endl;
					return 1;
				}
			}else{
				std::cout<<"Error of reading from filter file!"<<std::endl;
				return 1;
			}
		std::cout<<"Do yo want change this filter? [y/n]"<<std::endl;
		while(true){
			std::cin>>change_input;
			if(change_input == "n"){
				break;
			}else if(change_input == "y"){
				std::cout<<"Please enter name of filter file. "<< std::endl;
				std::cin>>change_input;
				filter.change_filter(FILTER_PATH + change_input);
				break;
			}
			std::cout<<"Please enter only 'y' or 'n' ." << std::endl;
		}
		}
	}else{
		std::cout<<"Error of reading from matrix file! "<<std::endl;
		return 1;
	}
}
std::cout<<"Convolution is done!"<<std::endl;
return 0;*/
helper();
run_program();
}

