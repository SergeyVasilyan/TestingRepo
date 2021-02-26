#include "mulheader.hpp"

int main(){
	int first_num, multiplier = 7;
	std::string input;
	std::cout << "Enter multiplying  number: ";
	while(true){
		std::cin >> input;
		if(check_number(input)){
			first_num = stoi(input);
			break;
		}
		std::cout << "Invalid input! Please enter only integer!" << std::endl;
	}
	std::cout << "Multiplication with shifting :" << shift_mul(first_num,multiplier) << std::endl;
	std::cout << "Multiplication with value adding :" << add_mul(first_num,multiplier) << std::endl;
	std::cout << "Multiplication with increment :" << very_bad_method(first_num,multiplier) << std::endl;
	return 0;
}
