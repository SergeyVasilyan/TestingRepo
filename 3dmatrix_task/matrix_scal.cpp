#include<iostream>

void mult (int ***image_matrix , int ***filtr_matrix, int ***input_matrix, int size_img, int size_fltr, int z){
	int g=0,f=0;
	for(int k=0; k<z;k++){
		for(int i=0; i<size_img-size_fltr+1; i++){ std::cout<<"222"<<std::endl;
			for(int j=0; j<size_img-size_fltr+1; j++){ std::cout<<"333"<<std::endl;
				int res=0,q1=-1,p1=-1;
				for(int q=i; q<size_fltr+f; q++){ q1++;std::cout<<"44"<<std::endl;
					for(int p=j; p<size_fltr+g; p++){ p1++;
						std::cout<<"Q- "<<q<<" "<<"P- "<<p<<" "<<"Q1- "<<q1<<" "<<"P1-"<<p1<<std::endl;
						res+=(image_matrix[q][p][k] * filtr_matrix[q1][p1][k]);
					}
				}std::cout<<"6"<<std::endl;
				std::cout<<input_matrix[i][j][k]<<std::endl;
				input_matrix[i][j][k]= res;
				g++;
				std::cout<<"000"<<std::endl;
			}std::cout<<"7"<<std::endl;
			f++;
		}std::cout<<"8"<<std::endl;
	}

	for ( int i = 0; i < size_img - size_fltr+1; i++ )
	{std::cout<<"9"<<std::endl;
		for ( int j = 0; j < size_img - size_fltr+1; j++ ){
			for (int k = 0; k < z; k++)
			{
				std::cout<<"input["<<i<<"]["<<j<<"]["<<k<<"]" <<" = "<<input_matrix[i][j][k]<<std::endl;
			}
		}
	}
}
int main(){

	const int X1 = 5;
	const int Y1 = 5;
	const int Z1 = 1;
	const int X = 2;
	const int Y = 2;
	const int Z = 1;

	int*** image = new int**[X1];
	for (int i = 0; i < X1; i++)
	{
		image[i] = new int*[Y1];
		for (int j = 0; j < Y1; j++)
			image[i][j] = new int[Z1];
	}

	int*** filtr = new int**[X];
	for (int i = 0; i < X; i++)
	{
		filtr[i] = new int*[Y];
		for (int j = 0; j < Y; j++)
			filtr[i][j] = new int[Z];
	}

	int X2=X1-X+1,Y2=Y1-Y+1;
	int*** input = new int**[X2];
	for (int i = 0; i < X2; i++)
	{
		input[i] = new int*[Y2];
		for (int j = 0; j < Y2; j++)
			input[i][j] = new int[Z];
	}

	for (int i = 0; i < X; i++){
		for (int j = 0; j < Y; j++){
			for (int k = 0; k < Z; k++){
				//std::cin>>filtr[i][j][k];
				filtr[i][j][k]=i+j;
			}
		}
	}

	for (int i = 0; i < X1; i++){
		for (int j = 0; j < Y1; j++){
			for (int k = 0; k < Z1; k++){
				image[i][j][k]=i+i+j;
			}
		}
	}

	/*
	for (int i = 0; i < X2; i++){
		for (int j = 0; j < Y2; j++){
			for (int k = 0; k < Z1; k++){
				//std::cin>>image[i][j][k];
				input[i][j][k]=0;
			}
		}
	}

*/
	mult(image,filtr,input,X1,X,Z);
	return 0;
}
