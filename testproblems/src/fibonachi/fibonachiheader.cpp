#include "fibonachiheader.hpp"
#include <iostream>

bool check_number(std::string str){
	for(int i = 0; i < str.length(); ++i){
		if(isdigit(str[i]) == false)
			return false;
	}
	return true;
}

void fibonachi(std::vector<unsigned long long> &vec, int n){
	unsigned long long first_el = 0, second_el = 1, tmp;
	if(0 == n){
		vec.push_back(first_el);
		return;
	}
	if(1 == n){
		vec.push_back(second_el);
		return;
	}
	vec.push_back(first_el);
	vec.push_back(second_el);
	for( int i = 2; i < n; ++i){
		vec.push_back(first_el+second_el);
		tmp = second_el;
		second_el += first_el;
		first_el = tmp;
	}
}

