#include <iostream>
#include <fstream>

int main()
{
  const int x = 2;
  const int y = 2;
  const int z = 1;

  char  myArray[x][y][z];

//  std::ifstream fin("matrix2");
  FILE *fp = fopen("matrix", "r");
  for ( int i = 0; i < x; i++ )
  {
    for ( int j = 0; j < y; j++ )
    {
	for (int k = 0; k < z; ++k)
    {
	//fin >> myArray[i][j][k];

	int num;
	fscanf(fp, " %d", &num);
        myArray[i][j][k]= num;
	std::cout<<"toxe-"<<num<<std::endl;
	std::cout<<"file-"<<fp<<std::endl;

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
