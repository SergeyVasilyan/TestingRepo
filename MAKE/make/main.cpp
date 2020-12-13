#include <iostream>
#include "add.h"

int main()
{   
    int a,b,sum;
    std::cin>>a>>b;
    sum = add(a,b);
    std::cout<<sum<<std::endl;
    return 0;
}
