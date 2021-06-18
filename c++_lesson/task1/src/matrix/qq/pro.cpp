#include<iostream>
#include<fstream>
#include <sstream>
#include <cassert>
int main()
{
	freopen( "loog.txt", "w", stdout );
    std::stringstream oss;
	std::cerr.copyfmt(std::cout);
std::cerr.rdbuf(std::cout.rdbuf());
    std::cerr << "this goes to cerr";
    std::cout << "[" << oss.str() << "]";
	assert(1 + 1 == 5);
	return 0;
}
