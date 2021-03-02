//sa zut erku matrix scalar artadryal hashvox .cpp,heto k,iacnem irar,gitem krknaki gorc em anum,bayc chem uzum xarnem irar

#include<iostream>
//erkchapi hamar grem nor erachapi hamar kdzem
int scalar(int ***arr1,int*** arr2,int n, int m,int layer){
	//stex poxancac 3dmatrixy mi shertanoca 
	int res=0;
	for(int i=0; i<n,i++){
		for(int j=0; j<m,j++){
			res+=(arr1[i][j][layer] * arr2[i][j][layer]);//heto layer-i anuny kpoxem
		}
	}
return res;-_-
//mnac djvar masy anem
void mult (int ***image_matrix , int ***filtr_matrix, int ***input_matrix, int size_img, int size_fltr, int z){
for(int k=0; k<z,k++){
	//stex shriftn el piti apahoves 
	 for(int i=0; i<size_img-size_fltr, i++){
	    for(int j=0; j<size_img-size_fltr, j++){//te aranc scal funkciayi anem


		    e//eli forerov banner piti gres
	     input_matrix[i][j][k]= scalar(int (*image_matrix)[size_fltr][k], int (*filtr_matrix)[size_fltr][k], x, y,k);

}
int main(){}
