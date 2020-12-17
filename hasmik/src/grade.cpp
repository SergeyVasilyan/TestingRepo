#include <iostream>
using namespace std;
int main()
{
    int score;
    cout<<"Enter the grade scored."<<endl;
    cin>>score;
if (score >= 0 && score <60){
    cout<<"You grade is F.";
	}
	else if (score >= 60 && score <70){
        cout<<"You grade is D.";
	}	
	else if (score >=70 && score <80){
        cout<<"You grade is C.";
	}
	else if (score >=80 && score <90){
        cout<<"You grade is B.";
	}
	else if (score >= 90 && score <=100){
        cout<<"You grade is A.";
	}	
	else {
        cout<<"Please, enter a number between 0-100.";
	}
    return 0;
}

