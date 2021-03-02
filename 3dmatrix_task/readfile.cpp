#include <iostream>
#include <fstream>

int main()
{

///esqany zut filic kardaln a
  const int X = 2;
  const int Y = 2;
  const int Z = 2;

  int*** myArray = new int**[X];

  for (int i = 0; i < X; i++)
  {
	  myArray[i] = new int*[Y];

	  for (int j = 0; j < Y; j++)
		  myArray[i][j] = new int[Z];
  }
    std::string str;
    int num=0;
    std::ifstream fin("matrix2");

if(!fin.is_open()){
	std::cout<<"file isn't open"<<std::endl;
	    return -1;
}
  int j, i, k=0, t=0;
  while (getline(fin, str) )
  { 
	  j=0;
	  for ( i = 0; str[i] != '\0'; i++ ) {
		  if ( str[i] >= '0' && str[i] <= '9') { 
			  num= num * 10 + (str[i] - '0');
		  }

		  else if( str[i] == ' ' ){
			  myArray[t][j][k] = num ;
			  j++;
			  num=0;
		  }
		  else{
			  std::cout<<"error"<<std::endl;
			  return 1;
		  }
	  }
	  if( str[i] == '\0' ){ 
		  myArray[t][j][k] = num ;
		  ++t;
		  num=0;
	  }
	if(t == X){
	t=0;
	k++;
	}
  }

  for ( int i = 0; i < X; i++ )
  {
	  for ( int j = 0; j < Y; j++ ){
		  for (int k = 0; k < Z; ++k)
		  {
			  std::cout << "myArray[" << i << "][" << j << "]["<<k<<"]" <<" = " << myArray[i][j][k]<<std::endl;
		  }
	  }
  }
  fin.close();
  return 0;
}
