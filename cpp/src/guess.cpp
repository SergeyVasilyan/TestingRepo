#include <iostream>
#include <ctime>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
void guess_num(){
	srand(time(NULL));
	int head=0;
	int tail=100;
	int rand_num= head+rand()%tail;
	std::string input;
	int number;
	while(true){
		std::cout<<"Please enter number from range ("<<head<<"-"<<tail<<")"<<std::endl;
		std::cin>>input;
		if(check_number(input)){
			number=std::stoi(input);
			if(number>=0 && number<=100){
				if(number==rand_num){
					std::cout<<"Congratulation you guess magic number!"<<std::endl;
					break;
				}else if(number<rand_num){
					head=number;
					std::cout<<"Magic number is in ("<<head<<"-"<<tail<<") range!"<<std::endl;
				}else if(number>rand_num){
					tail=number;
					std::cout<<"Magic number is in ("<<head<<"-"<<tail<<") range!"<<std::endl;
				}
				else{
					std::cout<<"Invalid input type, PLEASE enter only integers"<<std::endl;
					continue;
				}
			}
		}
	}
}
int main(){
	guess_num();	
return 0;
}
