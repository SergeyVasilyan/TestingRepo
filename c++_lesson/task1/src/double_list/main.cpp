#include <iostream>
#include"d_list.h"

int main() {
        List<int> l;
        for(int i = 0; i < 5; i++) {
                l.insert(2 * i, i);
        }
	std::cout << l.Size() << std::endl;
        return 0;
}
