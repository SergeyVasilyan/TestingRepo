#include <iostream>
#include "add1.h"

int main()
{   
    int a,b,sum;
    std::cin>>a>>b;
    sum = add(a,b);
    std::cout<<sum<<std::endl;
    return 0;
}

