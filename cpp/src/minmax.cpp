#include <iostream>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
void minmax(int* nums){
	int min=32000;
	int max=-32000;
	for(int i=0;i<10;++i){
		if(nums[i]<min){
			min=nums[i];
		}else if(nums[i]>max){
			max=nums[i];
		}
	}
	std::cout<<"Minimum is: "<<min<<" "<<"Maximum is: "<<max<<std::endl;
}
int main(){
	std::string input;
	int nums[10];
	std::cout<<"Enter 10 numbers: "<<std::endl;
	for(int i=0;i<10;++i){
		std::cin>>input;
		if(check_number(input))
			nums[i]=std::stoi(input);
	}
	minmax(nums);
return 0;
}
