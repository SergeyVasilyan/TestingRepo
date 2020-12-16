#include <iostream>

int main()
{
	int N,M;
	std::cin>>N>>M;
	for (int i = 0; i < N; ++i)
	  for (int j = 0; j < M; ++j)
		  if (i==0 || j==0 || i==N-1 || j==M-1){
			  std::cout<<"*";
			  if(j==M-1)
				  std::cout<<std::endl;
			}
		  else
			  std::cout<<" ";

	return 0;
}
