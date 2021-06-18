#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using std::filesystem::directory_iterator;

std::string get_current_datetime()
{
	time_t now = time(0);
	struct tm  tstruct;
	char  buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
	return std::string(buf);
}

bool find_word (char* filename)
{
	std::ifstream file_input(filename);//karoxa stringi beres
	if ( ! file_input.is_open()) {
		throw std::ifstream::failure {"File isn't open."};
	}
	std::string str = "";
	while (getline(file_input, str)) {
		size_t found = str.find("FAIL");
		if (found != std::string::npos){
			file_input.close();
			return true;
		}
	}
	file_input.close();
	return false;
}
void log_add(char* filename) 
{
	std::cout << "DATE: " << std::endl;
	std::cout << get_current_datetime() << std::endl;
	std::cout << "Started test" << std::endl;
	std::cout << filename << " - ";
	if (find_word(filename)) {
		std::cout << " FAIL. " << std::endl;
	} else {
		std::cout << " PASS. " << std::endl;
	}
}

void execute_cpp(char* filename)
{
	std::string str = "g++ ";
	str = str + filename + " -o a.out ";
	const char *command = str.c_str();
	system(command);
	system("./a.out");
}

int main (int argc,char** argv)
{
	freopen( "log_runtests.txt", "a", stdout );
	if (argc == 1) {
		std::string path = "/test_results";
		for (const auto & file : directory_iterator(path)) {
			execute_cpp(file.path());
			log_add(file.path());
		}
	} else {
		for (int i = 1; i < argc; i++) {
			execute_cpp(argv[i]);
			log_add(argv[i]);
		}
	}
	return 0;
}
