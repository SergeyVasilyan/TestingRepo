#include <iostream>
#include <string>
  
using namespace std;
  
int main()
{
   string str = "geeksforgeeks a computer science";
    string str1 = "lus";
  
    // Find first occurrence of "geeks"
    size_t found = str.find(str1);
    if (found != string::npos){
        cout << "First occurrence is " << found << endl;
    
    }
    cout << string::npos<< endl;
    cout << found << endl;

    
    return 0;
}
