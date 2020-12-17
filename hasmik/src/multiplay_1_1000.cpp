#include <iostream>
using namespace std;
int main()
{
    int n,S=0;
    cout<<"Enter number in range of 1-1000."<<std::endl;
    cin>>n;
    while(true){
    if(n>=1 && n<= 1000){
        for(int i=0; i<=n; i++){
            if (i%5==0 || i%3==0)
                S+=i;
        }
        cout<<"sum is "<<sum<<endl;
        break;
    }
    else{
        std::cout<<"Please, enter a number between 1-1000.";
        continue;
    }
    }

    return 0;
}
