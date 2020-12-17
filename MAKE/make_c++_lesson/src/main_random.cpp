#include <iostream>
#include <stdlib.h>
#include <time.h>

bool check_number(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

void game(){
	int tries = 0;
	std::string input;
	int entered_number = 0;
	int start_range = 1;
	int end_range = 100;
	srand(time(NULL));
	int random_number = rand() % end_range + start_range;
	while (1) {
		std::cout << "Enter the number: ";
		std::cin >> input;
		tries++;
		if ( check_number(input) == false) {
			std::cout << "Invalid type entered.\n" << std::endl;
			continue;
		} else {
			entered_number = std::stoi(input);
		}
		if (entered_number < 1 || entered_number > 100) {
			std::cout << "Invalid number.\nEnter number between " << start_range << " and " << end_range << ".\n" << std::endl;
		} else {
			if (random_number == entered_number) {
				std::cout << "Congratulations, you win the game with "<< tries << " tries."<< std::endl;
				break;
			} else if (random_number < entered_number) {
				std::cout << "Your entered number is greater than guessing number.\n" << std::endl;
			} else {
				std::cout << "Your entered number is less than guessing number.\n" << std::endl;
			}
		}
	}
}

int main() {
	std::cout << "Starting the game.\n" << std::endl;
	game();
	return 0;
}
