#include <iostream>
#include "d_list.h"
int main() {
        List<int> l;
        for (int i = 0; i < 5; i++) {
                l.insert(2 * i, i);
        }
	for (int i = 0; i < l.size(); i++) {
		std::cout<<l[i]<<"    ";
        }
	std::cout<<std::endl;
        return 0;
}
