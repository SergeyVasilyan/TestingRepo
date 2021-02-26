#include<iostream>
#include<math.h>
//#1
int f1(int x){
	int mult=0;
	for(int i=0; i<7; i++){
		mult+= x;
	}
	return mult;
}

int f2(int x){
	int mult;
	int y = (long long)x ;
	mult= y<<3;
	mult -= x;
	return mult ;
}

int f3(int x){
	static int count=6;
	if(!count){
		return x;
	}
	--count;
	return x+f3(x);

}

int f4(int x){
	int mult=0, num=7;
	x = (long long)x;
	while(num)
	{
		if(num % 2 == 1)
		{
			mult = mult + x;
		}
		num >>= 1;
		x <<= 1;
	}
	return mult;
}
int main(){

	std::cout<<f3(3)<<std::endl;
	return 0;

}

