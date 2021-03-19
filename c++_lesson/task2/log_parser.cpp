#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

double result = 0;
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

bool check_double(std::string& str)
{
	try {
		result = std::stod(str);
		return true;
	} catch(std::exception& invalid_argument) {
		std::cout << "Could not convert string to double." << std::endl;
		exit(0);
	}
}

bool check_date(std::string& date)
{
	struct tm tm;
	if (strptime(date.c_str(), "%Y/%m/%d", &tm)) {
		return true;
        } else {
		std::cout << "Date is invalid." << std::endl;
		exit(0);
	}
}

bool check_time(std::string& time)
{
	struct tm tm;
	if (strptime(time.c_str(), "%H:%M:%S", &tm)) {
		return true;
        } else {
		std::cout << "Time is invalid." << std::endl;
		exit(0);
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
	switch (data_count) {
	case Times:
		if (check_double(dt) == true)
			item.times = result;
			data_count = Base_line;
			break;
	case Base_line:
		if (check_double(dt) == true)
			item.base_line = result;
   		    data_count = Odor;
			break;
	case Odor:
		if (check_double(dt) == true)
			item.odor = result;
	    	data_count = Temp;
			break;
	case Temp:
		if (check_double(dt) == true)
			item.temp = result;
			data_count = Date;
			break;
	case Date:
		if (check_date(dt) == true)
			item.date = dt;
			data_count = Time;
			break;
	case Time:
		if (check_time(dt) == true)
			item.time = dt;
			data_count = Times;
			break;
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
				if (data1 != "") {
					set_data(item, data1);
					data1 = "";
				}
			}
		}
		if (data1 != "") {
			set_data(item, data1);
			data1 = "";
		}
		log.push_back(item);
	}
    	print(log);
        return 0;
}
