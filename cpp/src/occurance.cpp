#include <iostream>
bool check_number(std::string str) {
for (int i = 0; i < str.length(); i++){
	if (isdigit(str[i]) == false)
		return false;
	}
	return true;
}
int main(){
	int number;
	int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
	std::string input;
	while(true){
		std::cout<<"Enter integer from 1-10 "<<std::endl;
		std::cin>>input;
		if(input=="-1")
			break;
		if(check_number(input)){
			number=std::stoi(input);
			if(number<1 && number>10)
				continue;
			switch(number){
				case 1:
					count1++;
					break;
				case 2:
					count2++;
					break;
				case 3:
					count3++;
					break;
				case 4:
					count4++;
					break;
				case 5:
					count5++;
					break;
				case 6:
					count6++;
					break;
				case 7:
					count7++;
					break;
				case 8:
					count8++;
					break;
				casec9:
					count9++;
					break;
		}
	}
	}	
	std::cout<<"count of 1: "<<count1<<std::endl;
	std::cout<<"count of 2: "<<count2<<std::endl;
	std::cout<<"count of 3: "<<count3<<std::endl;
	std::cout<<"count of 4: "<<count4<<std::endl;
	std::cout<<"count of 5: "<<count5<<std::endl;
	std::cout<<"count of 6: "<<count6<<std::endl;
	std::cout<<"count of 7: "<<count7<<std::endl;
	std::cout<<"count of 8: "<<count8<<std::endl;
	std::cout<<"count of 9: "<<count9<<std::endl;
return 0;
}
