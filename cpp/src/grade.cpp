#include <iostream>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false){
			return false;
		}
	}
	return true;
}
void grade_checker(int number){
	if(number>=0 && number <=59){
		std::cout<<"Your grade is F"<<std::endl;
		return;
	}
	else if(number>=60 && number <=69){
		std::cout<<"Your grade is D"<<std::endl;
		return;
	}
	else if(number>=70 && number <=79){
		std::cout<<"Your grade is C"<<std::endl;
		return;
	}
	else if(number>=80 && number <=89){
		std::cout<<"Your grade is B"<<std::endl;
		return;
	}
	else{
		std::cout<<"Your grade is A"<<std::endl;
		return;
	}
}
int main(){
	std::string input;
	int number;
	std::cout<<"Enter number from 0-100 range."<<std::endl;
	std::cin>>input;
	if(check_number(input)){
		number=std::stoi(input);
		if(number>=0 && number<=100){
			grade_checker(number);
		}
		else{
			std::cout<<"Incorrect input"<<std::endl;
		}
	}else
		std::cout<<"Invalid input"<<std::endl;
return 0;
}
