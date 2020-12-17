#include <iostream>
bool check_number(std::string str){
	for (int i = 0; i <str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
void sum_of_digits(int number, int& result){
	while(number){
		result+=number%10;
	number/=10;
	}
}
int main(){
	int number,result=0;
	std::string input;
	std::cout<<"Enter integer: "<<std::endl;
	std::cin>>input;
	if(check_number(input)){
		number = std::stoi(input);
		sum_of_digits(number,result);
		std::cout<<"The sum of digits of your number is: "<<result<<std::endl;
	}else
		std::cout<<"Invalid type"<<std::endl;
return 0;
}
