#include <iostream>

int gcd(int num_one,int num_two){

    if (num_two != 0)
       return gcd(num_two, num_one % num_two);
    else 
       return num_one;
}
int main()
{	
	int number_one,number_two;
	 std::cout<<"Input one number: \n";
	 std::cin>>number_one;
	 std::cout<<"Input two number: "<<std::endl;
	 std::cin>>number_two;
	 std::cout<<" Gcd of "<<number_one<<" and "<<number_two<<": "<<gcd(number_one,number_two)<<std::endl;
	 return 0;
}
