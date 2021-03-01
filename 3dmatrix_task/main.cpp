#include <iostream>
#include <fstream>

int main()
{
  const int x = 2;
  const int y = 2;
  const int z = 1;

  char  myArray[x][y][z];
std::string str;
 int num=0;
  std::ifstream fin("matrix2");
 
  for ( int i = 0; i < x; i++ ) {
    for ( int j = 0; j < y; j++ ){
	for (int k = 0; k < z; ++k) {
        myArray[i][j][k]= '0';
    }
   }
  }
int j,i,t;
 for ( t = 0; t < x; t++) {
	  j = 0;
        while (getline(fin, str) )
        std::cout<<str<<std::endl;
	{
            for (i = 0; str[i] != '\0'; i++) {
		if(str[i] == ' ')
			continue;
                if ((str[i] >= '0') && (str[i] <= '9')){std::cout<<"llllllllllll"<<std::endl;
                  num= i * 10 + (str[i] - '0');
                }
		std::cout<<num<<std::endl;
		myArray[t][j][0]= (char)num;
		j++;
                }
            }
        }

  for ( int i = 0; i < x; i++ )
  {
    for ( int j = 0; j < y; j++ ){
	 for (int k = 0; k < z; ++k)
    {
	    std::cout << "myArray[" << i << "][" << j << "] = " << myArray[i][j][k]<<std::endl;
    }
  }
  }
  return 0;
}
