#include <iostream>
#include "d_list.h"
int main() {

	List<int> l;
	List<int> l1;

	for (int i = 0; i < 5; i++) {
		l.insert(2 * i, i);
	}

	for (int i = 0; i < l.size(); i++) {
		std::cout<<l[i]<<"    ";
	}

	for (int i = 0; i < 5; i++) {
		l1.insert(3 * i, i);
	}

	l1 = l;
	List<int> l2(l);
	std::cout<<std::endl;
	std::cout<<"L1 "<<std::endl ;

	for (int i = 0; i < l1.size(); i++) {
		std::cout<<l1[i]<<"    ";
	}
  	std::cout<<std::endl;
		std::cout<<"L2 "<<std::endl ;
		for (int i = 0; i < l2.size(); i++) {
			std::cout<<l2[i]<<"    ";
	}

	std::cout<<std::endl;
	return 0;
}
