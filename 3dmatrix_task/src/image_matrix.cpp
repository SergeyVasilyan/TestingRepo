#include<iostream>
#include"image_matrix.h"
#include<fstream>

int const rows=32;
int const cols=32;
int const layer=1;


class IMatrix
IMatrix::IMatrix(std::string path) {

	filename=path;
        data = new int**[rows];
        for (int i = 0; i < rows; i++)
        {
                data[i] = new int*[cols];
                for (int j = 0; j < cols; j++)
                        data[i][j] = new int[layer];
        }

       if(read_file(data,filename) == false){
       throw new exception("Error.");
       }


}
bool IMatrix::read_file(int ***threedarray,std::string path){
        std::std::string str_row, str1_row;
        int i,row_count=0,column_count=0, num=0;
        std::ifstream file_input(path);
        std::ifstream file_input_check_row_column_count(path);

        if(!file_input.is_open()){
                std::cout<<" file isn't open"<<std::endl;
                return false;
        }
        if(!file_input_check_row_column_count.is_open()){
                std::cout<<" file isn't open"<<std::endl;
                return false;
        }

        while(getline(file_input_check_row_column_count, str1_row)){
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

                        if((column_count+1) % cols != 0 or (column_count+1) / cols != 1 ){
                                std::cout<<"The number of columns is incorrect."<<std::endl;
                                return false;
                        }
                }
        }
        if(row_count%rows != 0 or row_count/rows != layer){
                std::cout<<"The number of rows is incorrect."<<std::endl;
                return false;
        }
        file_input_check_row_column_count.close();

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
                                        threedarray[row_index][column_index][layer_index] = num ;
                                        column_index++;
                                        num=0;
                                }

                        }
                        else{
                                std::cout<<"error"<<std::endl;
                                return false;
                        }
                }
                std::cout<<"I -"<<i<<std::endl;
                if( str_row[i] == '\0' ){
                        if(str_row[i-1]!= ' '){
                                threedarray[row_index][column_index][layer_index] = num ;
                                ++row_index;
                                num=0;
                        }
                }
                if(row_index == X){
                        row_index=0;
                        layer_index++;
                }
        }
        return true;
}

