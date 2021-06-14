#include <iostream>
#include <fstream>

inline std::string get_current_datetime(){
    time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return std::string(buf);
}

void print() 
{
	std::string now = get_current_datetime();
	log_file << "DATE: " << std::endl;
	log_file << now << std::endl;
	log_file << "Started test" << std::endl;
	log_file << "Program output: " << std::endl;
	log_file << "If fail print reason- " << std::endl;
	//inchvor stugumner vor jongnvi error exela te xhe 
	log_file << "Test result - " << std::endl;
}
int main()
{
	std::ofstream log_file("test_log.txt", std::ios_base::out);
	std::ofstream log_file1("result_log.txt", std::ios_base::out);
	print();
	return 0;
}
