#include<iostream>
#include<fstream>

int ***image,***filtr,***output;
bool read_file(int ***threedarray,int X,int Y,int Z,std::string path){
	std::string str_row, str1_row;
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

			if((column_count+1) % Y != 0 or (column_count+1) / Y != 1 ){
				std::cout<<"The number of columns is incorrect."<<std::endl;
				return false;
			}
		}
	}
	if(row_count%X != 0 or row_count/X != Z){
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

void mult (int ***image_matrix , int ***filtr_matrix, int ***output_matrix, int size_img, int size_fltr, int z){
	int g, f, filtr_matrix_column_index, filtr_matrix_row_index;
	for(int k=0; k<z;k++){//sharjvum enq sherteri vrayov
		filtr_matrix_row_index=-1;g=0;f=0;//filteri indexnery,g ev f nra hamara vor imaje indexneri mecacman het mektex misht filtri erkarutyamb mareicner didarkeq imagum
		for(int i=0; i<size_img-size_fltr+1; i++){
			for(int j=0; j<size_img-size_fltr+1; j++){//aotput matrici elemetneri arjeqneri voroshumy/indexavorumy
				int res=0;//elementi arjeqna pahvum ,aysiqn erku matricneri sxalyar artadryali ardyunqy
				filtr_matrix_row_index=-1;//amen mi elementi arjeqy vorosheluc filtri indexnery zroyacnum enq
				for(int q=i; q<size_fltr+f; q++){
					filtr_matrix_row_index++;
					filtr_matrix_column_index=-1;
					for(int p=j; p<size_fltr+g; p++){
						filtr_matrix_column_index++;
						res+=(image_matrix[ q ][ p ][ k ] * filtr_matrix[ filtr_matrix_row_index ][ filtr_matrix_column_index ][ k ]);
					}
				}
				output_matrix[ i ][ j ][ k ]= res;
				g++;

			}
			f++;
			g=0;
		}
	}
/*	for ( int i = 0; i < size_img - size_fltr+1; i++ )
	{
		for ( int j = 0; j < size_img - size_fltr+1; j++ ){
			for (int k = 0; k < z; k++)
			{
				std::cout<<output_matrix[i][j][k]<<"  ";
			}
		}
		std::cout<<std::endl;

	}*/



std::ofstream myfile("example");

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
int main(){

	const int X1 = 32;
	const int Y1 = 32;
	const int X2 = 5;
	const int Y2 = 5;
	const int Z = 1;

	image = new int**[X1];
	for (int i = 0; i < X1; i++)
	{
		image[i] = new int*[Y1];
		for (int j = 0; j < Y1; j++)
			image[i][j] = new int[Z];
	}

	filtr = new int**[X2];
	for (int i = 0; i < X2; i++)
	{
		filtr[i] = new int*[Y2];
		for (int j = 0; j < Y2; j++)
			filtr[i][j] = new int[Z];
	}

	int X3=X1-X2+1,Y3=Y1-Y2+1;
	output = new int**[X3];
	for (int i = 0; i < X3; i++)
	{
		output[i] = new int*[Y3];
		for (int j = 0; j < Y3; j++)
			output[i][j] = new int[Z];
	}

	if(read_file(image, X1, Y1, Z,"../src/imagefile") == false ){ return -1; };
	if(read_file(filtr, X2, Y2, Z,"../src/filtrfile") == false ){ return -1; };

	for ( int i = 0; i < X1; i++ )
	{
		for ( int j = 0; j < X1; j++ ){
			for (int l = 0; l < Z; l++)
			{
				std::cout<<image[i][j][l]<<"  ";
			}
		}
		std::cout<<std::endl;

	}
	for ( int i = 0; i <X2; i++ )
	{
		for ( int j = 0; j <X2; j++ ){
			for (int l = 0; l < Z; l++)
			{
				std::cout<<filtr[i][j][l]<<"  ";
			}
		}
		std::cout<<std::endl;

	}

	mult(image, filtr, output, X1, X2,Z);
	return 0;
}
