#include<iostream>


void fib()
{
int N=101;
unsigned long long fib[N];
fib[0] = 1;
fib[1] = 1;
for (int i = 2; i < N; i++)
{
fib[i] = fib[i - 1] + fib[i - 2]; 
}
for (int i = 0; i < N; i++){
     std::cout<<fib[i]<<" " ;
}
}
int main(){

	fib();
	return 0;

}
