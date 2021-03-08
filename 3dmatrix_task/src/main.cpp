#include<iostream>
#include<fstream>
#include"image_matrix.h"
#include"filtr_matrix.h"

void mult (IMatrix image , FMatrix filtr, int ***output_matrix,std::string path, int size_img, int size_fltr, int z){
        int g, f, filtr_matrix_column_index, filtr_matrix_row_index;
        for(int k=0; k<z;k++){
                filtr_matrix_row_index=-1;g=0;f=0;
                for(int i=0; i<size_img-size_fltr+1; i++){
                        for(int j=0; j<size_img-size_fltr+1; j++){
                                nt res=0;
                                filtr_matrix_row_index=-1;
                                for(int q=i; q<size_fltr+f; q++){
                                        filtr_matrix_row_index++;
                                        filtr_matrix_column_index=-1;
                                        for(int p=j; p<size_fltr+g; p++){
                                                filtr_matrix_column_index++;
                                                res+=(image.data[ q ][ p ][ k ] * filtr.data[ filtr_matrix_row_index ][ filtr_matrix_column_index ][ k ]);
                                        }
                                }
                                output_matrix[ i ][ j ][ k ]= res;
                                g++;
                        }
                        f++;
                        g=0;
                }
        }
std::ofstream myfile("path");
for ( int i = 0; i < size_img - size_fltr+1; i++ )
        {
                for ( int j = 0; j < size_img - size_fltr+1; j++ ){
                        for (int k = 0; k < z; k++)
                        {
                                myfile<<output_matrix[i][j][k]<<"  ";
                        }
                }
                 myfile<<std::endl;
}
myfile.close();
}
int i=0;
std::string ask(){
	std::string path; 
	std::cout<<"Input filtr file name:"
        std::cin>>path;
	return path;
}
int main(){

	int X1=32, X2=5, Z=1;
	std::string path, answer;
	std::cout<<"Input image file name: "
	std::cin>>path;
	IMatrix image(path);
	path = ask();
        FMatrix f(path);
	while(true){
       		path = ask();
		FMatrix f(path);
		std::cout<<"Enter option: "<<std::endl;
		std::cout<<"1.dot product of two matrices."<<std::endl;
		std::cout<<"2.Change filter. "<<std::endl;
		std::cout<<"3.Input new filter. "<<std::endl;
		std::cinn>>answer;
		if(answer == "1"){
			std::string str;
			std::cout<<"Input output file name:"
			std::cin>>str;
			mult(image,f,str,X1,X2,Z);
		}
		else if (answer == "2"){
			f.change();
		}
		else if (answer == "3"){
			 path = ask();
      			 FMatrix f(path);
		}
		else{
			std::cout<<"Incorrect option "<<std::endl;
			return -1;}
	}
}
