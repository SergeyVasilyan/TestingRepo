#include <iostream>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
void draw_rect(int length, int height){
	for(int i=0;i<length;++i){
		for(int j=0;j<height;++j){
			if(i==0 || i==length-1 || j==0 || j==height-1){
				std::cout<<"*";
			}
			else{
				std::cout<<" ";
			}
		}
		std::cout<<std::endl;
	}
}
int main(){
	std::string input;
	int length, height;
	std::cout<<"Enter length and height of rectangle: "<<std::endl;
	std::cin>>input;
	if(check_number(input))
		length=std::stoi(input);
	else
		std::cout<<"Invalid input type"<<std::endl;
	std::cin>>input;
	if(check_number(input))
		height=std::stoi(input);
	else
		std::cout<<"Invalid input type"<<std::endl;
	draw_rect(length,height);
return 0;
}
