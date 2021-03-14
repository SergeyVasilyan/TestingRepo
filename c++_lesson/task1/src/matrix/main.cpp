#include<iostream>
#include"matrix.h"

bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}
int main(){
	std::string rows, cols;
	std::cout<<"Input rows: ";
	std::cin>>rows;
	if(check_number(rows) == true){
		std::cout<<"Input cols: ";
		std::cin>>cols;
		if(check_number(cols) == true){
			Matrix mat(std::stoi(rows), std::stoi(cols));
	std::cin>>mat;
	std::cout<<mat;
		}
	}
	return 0;
}
