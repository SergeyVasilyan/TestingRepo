#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
enum data_index {Times, Base_line, Odor, Temp, Date, Time};
data_index data_count;

struct data
{
	double times;
	double base_line;
	double odor;
	double temp;
	std::string date;
	std::string time;
};

bool check_double(std::string& str, double& result)
{
	try {
		result = std::stod(str);
		return true;
	} catch(std::exception& invalid_argument) {
		std::cout << "Could not convert string to double." << std::endl;
		return false;
	}
}

bool check_date(std::string& date)
{
	struct tm tm;
	if (strptime(date.c_str(), "%Y/%m/%d", &tm)) {
		return true;
        } else {
		std::cout << "Date is invalid." << std::endl;
		return false;
	}
}

bool check_time(std::string& time)
{
	struct tm tm;
	if (strptime(time.c_str(), "%H:%M:%S", &tm)) {
		return true;
        } else {
		std::cout << "Time is invalid." << std::endl;
		return false;
	}
}
void print(std::vector<data>& log) 
{
	for (int i = 0; i< 30; i++) {
		std::cout << "Times - " << log[i].times
			<< " Base line - " << log[i].base_line
			<< " Odor - " << log[i].odor
			<< " Temp - " << log[i].temp
			<< " Date - " << log[i].date
			<< " Time - " << log[i].time << std::endl;
	}
}
void set_data(data& item, std::string& dt)
{	
	double result = 0;
	if (dt != "") {
	switch (data_count) {
	case Times:
		if (check_double(dt, result) == true)
			item.times = result;
			data_count = Base_line;
			dt = "";
			break;
	case Base_line:
		if (check_double(dt, result) == true)
			item.base_line = result;
   		    data_count = Odor;
			dt = "";
			break;
	case Odor:
		if (check_double(dt, result) == true)
			item.odor = result;
	    	data_count = Temp;
			dt = "";
			break;
	case Temp:
		if (check_double(dt, result) == true)
			item.temp = result;
			data_count = Date;
			dt = "";
			break;
	case Date:
		if (check_date(dt) == true)
			item.date = dt;
			data_count = Time;
			dt = "";
			break;
	case Time:
		if (check_time(dt) == true)
			item.time = dt;
			data_count = Times;
			dt = "";
			break;
	}
	}
}
int main()
{
	std::vector<data> log;
	std::string str = "";
    std::string data1 = "";
	data item;
    std::string path = "data.txt";
	std::ifstream file_input(path);
	if (! file_input.is_open()) {
		std::cout << "File isn't open" << std::endl;
		return -1;
	}
	while (getline(file_input, str)) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (! isspace(str[i])) {
				data1 += str[i];
			} else {
					set_data(item, data1);
			}
		}
		set_data(item, data1);
		log.push_back(item);
	}
    	print(log);
        return 0;
}
