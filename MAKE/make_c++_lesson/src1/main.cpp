#include <iostream>

int main()
{
    int score;
    std::cout<<"Enter the grade scored in a class."<<std::endl;
    std::cin>>score;
if (score >= 0 && score <60){
    std::cout<<"You grade is F.";
	}
	else if (score >= 60 && score <70){
        std::cout<<"You grade is D.";
	}	
	else if (score >=70 && score <80){
        std::cout<<"You grade is C.";
	}	 
	else if (score >=80 && score <90){
        std::cout<<"You grade is B.";
	}
	else if (score >= 90 && score <=100){
        std::cout<<"You grade is A.";
	}	 	
	else {
        std::cout<<"Please, enter a number between 0-100.";
	}
    return 0;
}
