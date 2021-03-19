#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

double result = 0;

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

bool check_time(std::string& time){
	struct tm tm;
	if (strptime(time.c_str(), "%H:%M:%S", &tm)) {
		return true;
        } else {
		std::cout << "Time is invalid." << std::endl;
		exit(0);
	}
}

int main()
{
	std::vector<data> log;
	std::string str = " ";
        std::string data1 = "";
	data item;
        int i = 0;
	int data_count = 1;
        std::string path = "data.txt";
	std::ifstream file_input(path);
	if (! file_input.is_open()) {
		std::cout << "File isn't open" << std::endl;
		return -1;
	}
	while (getline(file_input, str)) {
		data_count = 1;
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] != ' ') {
				data1 += str[i];
			} else {
				if (i != 0 && str[i - 1] != ' ') {
					switch (data_count) {
					case 1:
						if (check_double(data1) == true)
							item.times = result;
							break;
					case 2:
						if (check_double(data1) == true)
							item.base_line = result;
							break;
					case 3:
						if (check_double(data1) == true)
							item.odor = result;
							break;
					case 4:
						if (check_double(data1) == true)
							item.temp = result;
							break;
					case 5:
						if (check_date(data1) == true)
							item.date = data1;
							break;
					case 6:
						if (check_time(data1) == true)
							item.time = data1;
							break;
					}
					data1 = "";
					data_count++;
				}
			}
		}
		if (str[i - 1] != ' ' && str[i] == '\0') {
			if (check_time(data1) == true)
				item.time = data1;
		}
		log.push_back(item);
	}

	for (int i = 0; i< 30; i++) {
                std::cout << "Times - " << log[i].times
                        << " Base line - " << log[i].base_line
                        << " Odor - " << log[i].odor
                        << " Temp - " << log[i].temp
                        << " Date - " << log[i].date
                        << " Time - " << log[i].time << std::endl;
	}
        return 0;
}
