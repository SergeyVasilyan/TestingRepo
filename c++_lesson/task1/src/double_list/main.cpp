#include <iostream>
#include "d_list.h"

int main() {
        DList<int> fl;
        for(int i = 0; i < 5; i++) {
                fl.insert(2 * i, i);
        }
	std::cout << fl.Size() <<std::endl;
        return 0;
}

