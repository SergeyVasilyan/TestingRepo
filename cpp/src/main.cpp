#include <iostream>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
int sum_of_nums(int number){
	int result;
	for(int i=1;i<=number;++i){
		if(i%3==0 || i%5==0){
			result+=i;
		}
	}
	return result;
}
int main(){
	int number;
	std::string input;
	std::cout<<"Enter number from 1-1000 range"<<std::endl;
	std::cin>>input;
	if(check_number(input)){
		number=std::stoi(input);
		if(number>=1 && number<=1000){
			std::cout<<"Sum of multiplies of 3 and 5 is: "<<sum_of_nums(number)<<std::endl;
		}
		else
			std::cout<<"Incorrect input"<<std::endl;
	}else
		std::cout<<"Invalid input type"<<std::endl;
return 0;
}
