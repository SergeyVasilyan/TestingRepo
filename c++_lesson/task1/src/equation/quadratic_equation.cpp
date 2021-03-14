#include<iostream>
#include"math.h"

bool check_double( std::string str, double &result){
	try
	{
		result = std::stod(str);
		return true;
	}
	catch(std::exception& invalid_argument)
	{
		std::cout << "Could not convert string to double." << std::endl;
		return false;
	}
}
double a,b,c;
int main(){
	while(true){
		std::string temp, answer;
		double D, x1, x2;
		std::cout<<"Calculates the roots of the quadratic equation (ax^2 + bx +c = 0). "<<std::endl;
		std::cout<<"Enter the quadratic coefficient(a): ";
		std::cin>>temp;
		if(check_double(temp,a) == true){
			std::cout<<"Enter the linear coefficient(b): ";
			std::cin>>temp;
			if(check_double(temp, b) == true){
				std::cout<<"Enter the free coefficient(c): ";
				std::cin>>temp;
				if(check_double(temp,c) == true){
					if(a !=  0){
					D = pow(b,2) - 4*a*c;
					if(D > 0){
						x1 = ((-b) - sqrt(D)) / (2*a);
						x2 = ((-b) + sqrt(D)) / (2*a);
						std::cout<<"x1 =  "<<x1<<std::endl;
						std::cout<<"x2 = "<<x2<<std::endl;
					}
					else if (D == 0){
						x1 = (-b) / (2*a);
						std::cout<<"x1 = x2 = "<<x1<<std::endl;
					}
					else{
						std::cout<<"Don't root."<<std::endl;
					}
				}
					else{					
					x1 = (-c)/b;
                                        std::cout<<"x1 =  "<<x1<<std::endl;
					}
				}
			}
		}
		while(true){
			std::cout << "Do you want to calculate the roots of the equation again?(yes/no)" << std::endl;
			std::cin>>answer;
			if (answer == "no"){ return -1; }
			else if (answer == "yes"){ break;}
			else {
				std::cout<<"Incorrect answer."<<std::endl;
				continue;
			}
		}
	}
	return 0;
}
