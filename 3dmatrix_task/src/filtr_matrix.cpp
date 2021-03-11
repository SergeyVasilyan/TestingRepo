#include"filtr_matrix.h"
#include<iostream>
#include<fstream>

int Rows=5;
int Cols=5;
int layers=1;
FMatrix::FMatrix(std::string path) {

	filename=path;
	data = new int**[Rows];
	for (int i = 0; i < Rows; i++)
	{
		data[i] = new int*[Cols];
		for (int j = 0; j < Cols; j++)
			data[i][j] = new int[layers];
	}
	if(read_file(filename) == false){
		throw("Error.");
	}
}

bool FMatrix::read_file(std::string path){
	std::string str_row, str1_row;
	int i,row_count=0,column_count=0, num=0;
	std::ifstream file_input(path);
	std::ifstream file_input1(path);

	if(!file_input.is_open()){
		std::cout<<" file isn't open"<<std::endl;
		return false;
	}
	if(!file_input1.is_open()){
		std::cout<<" file isn't open"<<std::endl;
		return false;
	}

	while(getline(file_input1, str1_row)){
		if(str1_row[0]!='\0'){
			row_count++;
			column_count=0;
			for( i=0; str1_row[i]!='\0';i++){
				if(i != 0 && str1_row[i] == ' ' ){
					if(i!=0 && str1_row[i-1] !=' '){
						column_count++;
					}
				}
			}
			if(str1_row[i] == '\0'){
				if(i!=0 && str1_row[i-1] == ' '){
					column_count--;
				}
			}

			if((column_count+1) % Cols != 0 or (column_count+1) / Cols != 1 ){
				std::cout<<"The number of columns is incorrect."<<std::endl;
				return false;
			}
		}
	}
	if(row_count%Rows != 0 or row_count/Rows != layers){
		std::cout<<"The number of Rows is incorrect."<<std::endl;
		return false;
	}
	file_input1.close();

	int column_index, layer_index=0, row_index=0;
	while (getline(file_input, str_row) )
	{
		column_index=0;
		for ( i = 0; str_row[i] != '\0'; i++ ) {
			if ( str_row[i] >= '0' && str_row[i] <= '9') { 
				num= num * 10 + (str_row[i] - '0');
			}
			else if( str_row[i] == ' ' ){
				if( i!=0 && str_row[i-1]!= ' ' ){
					this->data[row_index][column_index][layer_index] = num ;
					column_index++;
					num=0;
				}
			}
			else{
				std::cout<<"error"<<std::endl;
				return false;
			}
		}
		if( str_row[i] == '\0' ){
			if(str_row[i-1]!= ' '){
				this->data[row_index][column_index][layer_index] = num ;
				num=0;
			}
		}
		++row_index;
		if(row_index == Rows){
			row_index=0;
			layer_index++;
		}
	}
	file_input.close();
	return true;
}
bool check_number(std::string str) {
        for (int i = 0; i < str.length(); i++)
                if (isdigit(str[i]) == false)
                        return false;
	return true;
}
void  FMatrix::change(){
	std::string answer;
	int value;
	std::cout<<"Do you want to change all the elements of the array?(yes/no) "<<std::endl;
	std::cin>>answer;
	if(answer=="yes"){
		for ( int i = 0; i < Rows; i++ )
		{
			for ( int j = 0; j < Cols; j++ ){
				for (int k = 0; k < layers; k++)
				{
					std::cin>>value;
					this->data[i][j][k] = value;
				}
			}
		}
	}
	else{
		int row,col,layer;
		std::string value;
		std::cout<<"Enter row number: "<<std::endl;
		std::cin>>row;
		if(row <Rows)
			std::cout<<"Enter column number: "<<std::endl;
		std::cin>>col;
		if(col<Cols){
			std::cout<<"Enter layer number: "<<std::endl;
			std::cin>>layer;
			if(layer < layers){
				std::cout<<"Enter  value: "<<std::endl;
				std::cin>>value;
				if(check_number(value)== true){
					this->data[row][col][layer]= std::stoi(value);
				}
			}

		}
	}
		std::ofstream myfile(this->filename);
	for ( int i = 0; i < Rows; i++ )
	{
		for ( int j = 0; j < Cols; j++ ){
			for (int k = 0; k < layers; k++)
			{
				myfile<<this->data[i][j][k]<<"  ";
			}
		}
		myfile<<std::endl;
	}
	myfile.close();}

