#include <iostream>

int main()
{
    int number, SumOfDigits=0;
    std::cin>>number;
    while(number){
    SumOfDigits +=number%10;
    number/=10;
    }
    std::cout<<"The sum of the digits of the number is "<<SumOfDigits<<std::endl;
    return 0;
}
