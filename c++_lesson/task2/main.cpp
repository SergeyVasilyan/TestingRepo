#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

enum data_index {Times, Base_line, Odor, Temp, Date, Time};

struct data
{
	double times;
	double base_line;
	double odor;
	double temp;
	std::string date;
	std::string time;
};

void check_double(const std::string& str, double& result)
{
	try {
		result = std::stod(str);
	} catch (std::exception& i) {
		//throw(i.what());
		throw("Error");
	}
}

void check_date(const std::string& date)
{
	struct tm tm;
	if (0 == strptime(date.c_str(), "%Y/%m/%d", &tm)) {
	throw(" Date is invalid. ");
	}
}

void check_time(const std::string& time)
{
	struct tm tm;
	if (0 == strptime(time.c_str(), "%H:%M:%S", &tm)) {
	throw(" Time is invalid." );
	}
}

void print(const std::vector<data>& log)
{
	for (auto i = 0; i < log.size(); i++) { 
		std::cout << "Times - " << log[i].times
			<< " Base line - " << log[i].base_line
			<< " Odor - " << log[i].odor
			<< " Temp - " << log[i].temp
			<< " Date - " << log[i].date
			<< " Time - " << log[i].time << std::endl;
	}
}

void set_data(data& item, std::string& dt, data_index& data_count) {
	double result = 0;
	switch (data_count) {
	case Times:
			check_double(dt, result);
			item.times = result;
			data_count = Base_line;
			dt = "";
			break;
	case Base_line:
			check_double(dt, result);
			item.base_line = result;
			data_count = Odor;
			dt = "";
			break;
	case Odor:
			check_double(dt, result);
			item.odor = result;
			data_count = Temp;
			dt = "";
			break;
	case Temp:
			check_double(dt, result);
			item.temp = result;
			data_count = Date;
			dt = "";
			break;
	case Date:
			check_date(dt);
			item.date = dt;
			data_count = Time;
			dt = "";
			break;
	case Time:
			check_time(dt);
			item.time = dt;
			data_count = Times;
			dt = "";
			break;
	}
}
int main()
{
	data_index data_count = Times;
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
					set_data(item, data1, data_count);
				}
			}
		}
		if (data1 != "") {
			set_data(item, data1, data_count);
		}
		log.push_back(item);
	}
	print(log);
	return 0;
}
