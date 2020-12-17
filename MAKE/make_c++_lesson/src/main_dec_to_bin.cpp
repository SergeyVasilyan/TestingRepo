#include <iostream>
#include <list>

bool check_number(std::string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

void dec_to_bin(int dec_number){
	std::list<int> bin;
	while(dec_number){
	bin.push_front(dec_number%2);
	dec_number /=2;
	}
	int add_0_count=bin.size()%4;
	for(int i=0;i<add_0_count; i++){
		bin.push_front(0);	
	}
	for(auto i : bin){
	
	std::cout<<i;
	}
		

}
int main()
{
	std::string dec_number_s;
	int dec_number;
	while(true){
		std::cout << "Enter the number: ";
		std::cin >>dec_number_s;
		if ( check_number(dec_number_s) == false) {
			std::cout << "Invalid type entered.\n" << std::endl;
			continue;
		} else {
		   dec_number = std::stoi(dec_number_s);
		   break;
		}
	}
	dec_to_bin(dec_number);
	return 0;

}
