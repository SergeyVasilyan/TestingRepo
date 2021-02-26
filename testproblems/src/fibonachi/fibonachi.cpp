#include "fibonachiheader.hpp"

int main(){
std::string input;
std::vector<unsigned long long> vec;
int number;
std::cout << "Enter positive number of elements of fibonachi: " << std::endl;
while(true){
	std::cin >> input;
	if(check_number(input)){
		number = stoi(input);
		if (number > 94){
			std::cout << " Number is too big! Please enter number in range 0-94! " << std::endl;
			continue;
		}
		break;
	}
	std::cout << "Invalid input! Please enter only positive integer! " << std::endl;
}
fibonachi(vec,number);
for(int i = 0; i < vec.size(); ++i)
	std::cout << vec[i] << std::endl;
return 0;
}


