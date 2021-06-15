#include <iostream>

int main()
{
    int number,sum=0;
    std::cout<<"Enter number in range of [1-1000]."<<std::endl;
    //std::cin>>number;
    while(true){
    std::cin>>number;
    if(number>=1 && number<= 1000){
        for(int i=0; i<=number; i++){
            if (i%3==0 || i%5==0)
                sum+=i;
        }
        std::cout<<"The sum of these multiples is "<<sum<<std::endl;
        break;
    }
    else{
        std::cout<<"Please, enter a number between 1-1000.";
        continue;
    }
    }

    return 0;
}
