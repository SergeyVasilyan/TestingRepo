#include <iostream>

int main()
{
	int number,number1=0,i=10;
	std::cin>>number;
	while(number)
	{
	 number1=(number1*i) + number%i ;
	 number/=i;
	}
	std::cout<<number1<<std::endl;
	return 0;

}
