#include <iostream>
#include "add.h"

int main()
{
    int a, b,sum;
	int *temp;
    std::cin >> a >> b;
    sum = add(a, b);
    std::cout << sum << std::endl;
	std::cout<<temp;
    return 0;
}
