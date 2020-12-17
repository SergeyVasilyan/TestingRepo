#include <iostream>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
void inverse_num(int &number){
	int temp=0;
	while(number){
		temp=temp*10+number%10;
		number/=10;
	}
	number=temp;
}
int main(){
	int number;
	std::string input;
	std::cout<<"Input integer: "<<std::endl;
	std::cin>>input;
	if(check_number(input)){
		number=std::stoi(input);
		inverse_num(number);
		std::cout<<"Inverse of your number is: "<<number<<std::endl;
	}else
		std::cout<<"Invalid input type"<<std::endl;
return 0;
}
