#include <iostream>
bool check_number(std::string str) {
for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
int gcd(int m, int n)
{
    if(n == 0) return m;
    return gcd(n, m % n);
}
int main(){
int num1, num2;
std::string input;
std::cout<<"Enter first number"<<std::endl;
std::cin>>input;
if(check_number(input)){
	num1=std::stoi(input);
}else{
	std::cout<<"Invalid type input"<<std::endl;
	return 0;
}
std::cin>>input;
if(check_number(input)){
	num2=std::stoi(input);
}else{
	std::cout<<"Invalid type input"<<std::endl;
	return 0;
}
std::cout<<gcd(num1,num2)<<std::endl;
return 0;
}
