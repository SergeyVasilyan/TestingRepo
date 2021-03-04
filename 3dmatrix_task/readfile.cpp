#include <iostream>
#include <fstream>

int main()
{
  const int X = 2;
  const int Y = 2;
  const int Z = 1;

  int*** myArray = new int**[X];

  for (int i = 0; i < X; i++)
  {
	  myArray[i] = new int*[Y];

	  for (int j = 0; j < Y; j++)
		  myArray[i][j] = new int[Z];
  }
    std::string str,str1;
    int row_count=0,colum_count,i1=0, num=0;
    std::ifstream fin("matrix2");
    std::ifstream fin1("matrix2");

if(!fin.is_open()){
	std::cout<<"file isn't open"<<std::endl;
	    return -1;
}


while(getline(fin1,str1)){
	std::cout << str1<<std::endl;
	if(str1[0]!='\0'){colum_count=0;
	row_count++;
		for(int i=0; str1[i]!='\0';i++){
			std::cout<<"str["<<i<<"]= "<<str[i]<<std::endl;
			if(str1[i] == ' ' ){
				if(i!=0 && str1[i-1] !=' '){
					colum_count++;
					std::cout<<"COUNT1- "<<colum_count<<" str["<<i<<"]= "<<str[i]<<std::endl;
					i1=i;
				}
			}
		}
		if(i1!=0 && str1[i1-1] == ' '){
			std::cout<<"aaaaaaa"<<std::endl;
			colum_count--;
		}
		if((colum_count+1) % Y != 0 ){
			std::cout<<"syunnery qanaqy sxala"<<std::endl;
			return -1;
		}
	}
}
if(row_count%X != 0 && row_count/X != Z){
	std::cout<<"toxery qanaqy sxala"<<std::endl;
	return -1;
}




 std::cout<<"1111111"<<std::endl;

int j, i, k=0, t=0;
  while (getline(fin, str) )
  { std::cout<<"2222222"<<std::endl;

	  j=0;
	  for ( i = 0; str[i] != '\0'; i++ ) { std::cout<<"333"<<std::endl;

		  if ( str[i] >= '0' && str[i] <= '9') { 
			  num= num * 10 + (str[i] - '0');
		  }

		  else if( str[i] == ' ' ){ std::cout<<"44444"<<std::endl;

			  myArray[t][j][k] = num ;
			  j++;
			  num=0;
		  }
		  else{
			  std::cout<<"error"<<std::endl;
			  return 1;
		  }
	  }
	  if( str[i] == '\0' ){std::cout<<"5"<<std::endl;

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
  {std::cout<<"6"<<std::endl;

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
