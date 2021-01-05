#include <iostream>
#include <array>
bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
void removenum(int *array,int size){
	std::string input;
	int rem_num=0;
	bool flag=false;
	while(true){
		std::cout<<"Enter number which you want remove!"<<std::endl;
		std::cin>>input;
		if(check_number(input)){
			rem_num=std::stoi(input);
			for(int i=0;i<size;++i){
				if(rem_num==array[i]){
					for(int j=i;j<size-1;++j)
						array[j]=array[j+1];
					array[size-1]=0;
					flag=true;
					break;
				} 
			}
			if(!flag)
				std::cout<<"There is not such number in array!"<<std::endl;
		}
		else if("exit"==input)
			break;
		else
			std::cout<<"Invalid input."<<std::endl;
	}
}
int main(){
	std::string input;
	const int SIZE=10;
	int array[10]={0},count=0;
	while(count<10){
		std::cout<<"Enter number: ";
		std::cin>>input;
		if(check_number(input))
			array[count++]=std::stoi(input);
		else
			std::cout<<"Invalid input type. Please enter only integers!"<<std::endl;
	}
	removenum(array,SIZE);
	for(int i=0;i<SIZE;++i)
		std::cout<<array[i]<<" ";
return 0;
}
