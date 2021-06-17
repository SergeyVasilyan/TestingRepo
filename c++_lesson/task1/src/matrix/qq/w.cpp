#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
/*
using namespace std;

int main()
{
	int countwords=0;
	string line;
	string  path = "aaa.txt";
	string  word = "asa";
	ifstream File(path.c_str());
	if(File.is_open())
	{
		cout<<"File found."<<endl;
		cout << "1" << std::endl;
		cout << "2" << std::endl;
		while(!File.eof())
		{
		line = File.get();
                std::cout << line << std::endl;
			cout << "3" << std::endl;
			if(word.compare(line)==0)
				countwords++;
		}
		cout<<"The word has been found "<<countwords<<" times."<<endl;
		File.close();
		cout << "4" << std::endl;
	}
	else
	{
		cout<<"Error! File not found!";
		exit(1);
	}
return 0;
}
*/
int main ()
{
std::ifstream file_input("aaa.txt");
        if ( ! file_input.is_open()) {
                throw std::ifstream::failure {"File isn't open."};
        }
	std::string str = "";
        while (getline(file_input, str)) {

        }
        file_input.close();
}
