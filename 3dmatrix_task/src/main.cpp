#include<iostream>
#include<fstream>
#include"image_matrix.h"
#include"filtr_matrix.h"

void mult (IMatrix image , FMatrix filtr){
	std::string str;
	std::cout<<"Input output file name:";
	std::cin>>str;
	int size_fltr=5;
	int z=1;
	int out_cols= 28;
	int out_rows= 28;
	int g=0, f=0, fmatrix_col_index=-1, fmatrix_row_index=-1;
	std::ofstream myfile(str);
	for(int k=0; k<z;k++){
		fmatrix_row_index=-1;g=0;f=0;
		for(int i=0; i<out_rows; i++){
			for(int j=0; j<out_cols; j++){
				int res=0;
				fmatrix_row_index=-1;
				for(int q=i; q<size_fltr+f; q++){
					if (size_fltr+f < out_rows){
						fmatrix_row_index++;
						fmatrix_col_index=-1;
						for(int p=j; p<size_fltr+g; p++){
							if(size_fltr+g < out_cols ){
								fmatrix_col_index++;
								res+=(image.data[ q ][ p ][ k ] * filtr.data[ fmatrix_row_index ][ fmatrix_col_index ][ k ]);
							}
							else
							{
								throw("Access out of range");
							}
						}
					}
					else{
						throw("Access out of range");

					}
				}
				myfile<<res<<"  ";
				g++;
			}
			f++;
			g=0;
		}
	}
	myfile.close();
}
std::string ask(){
	std::string path;
	std::cout<<"Enter  filter file name:";
	std::cin>>path;
	return path;
}
int main(){
	std::string filename, answer;
	std::cout<<"Enter image file name: ";
	std::cin>>filename;
	IMatrix image(filename);
	FMatrix f(ask());
	while(true){
		std::cout<<std::endl;
		std::cout<<"Enter option: "<<std::endl;
		std::cout<<"1.Dot product of two matrices."<<std::endl;
		std::cout<<"2.Change filter. "<<std::endl;
		std::cout<<"3.Input new filter. "<<std::endl;
		std::cout<<"4.Exit. "<<std::endl;
		std::cout<<"Answer: ";
		std::cin>>answer;
		if(answer == "1"){
			mult(image, f);
		}
		else if (answer == "2"){
			f.change();
		}
		else if (answer == "3"){
			f.read_file(ask());
		}
		else if(answer == "4")
		{
			return -1;
		}
		else{
			std::cout<<"Incorrect option "<<std::endl;
			continue;
		}
	}
}
