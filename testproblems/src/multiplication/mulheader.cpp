#include "mulheader.hpp"
bool check_number(std::string str) {
//	bool sign_flag=false;
	for (int i = 0; i < str.length(); i++){
		if('-'==str[i] && 0==i){
//			sign_flag=true;
			continue;
		}
		if (isdigit(str[i]) == false)
			return false;
	}
//	if(sign_flag)
//		return -1;
	return true;
}

int add_mul( int x, int multiplier){
	int result=0;
	for(int i=0;i<multiplier;++i)
		result+=x;
	return result;
}
int shift_mul( int x, int multiplier){
	return (x << (multiplier / 2 )) - x;
}
 
int very_bad_method( int x, int multiplier){
	int result = 0;
	if(x >= 0){
		for(int i = 0;i < multiplier; ++i){
			for(int j = 0;j < x; ++j)
				++result;
		}
	}else{
		for(int i = 0;i < multiplier; ++i){
			for(int j = 0;j > x; --j)
			--result;
		}
	}
	return result;
}

