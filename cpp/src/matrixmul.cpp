#include <iostream>
#include <tr1/memory>
class Matrix{
	public:
		int rsize;
		int csize;
		int** value;
		Matrix(int rows,int cols){
			rsize=rows;
			csize=cols;
			value=new introws];
			for(int i=0;i<rsize;++i)
				value[i]=new int[csize];
		}
		void input_value(){
			for(int i=0;i<this->rsize;++i){
				for(int j=0;j<this->csize;++j){
					std::cin>>this->value[i][j];
				}
			}
		}
		void print(){
			for(int i=0;i<rsize;++i){
				for(int j=0;j<csize;++j){
					std::cout<<value[i][j]<<" ";
				}
			std::cout<<std::endl;
			}
		}
		~Matrix(){
			for(int i=0;i<rsize;++i)
				delete value[i];
			delete [] value;
		}
};
int main(){
	Matrix a(4,4);
	a.input_value();
	a.print();
return 0;
}
