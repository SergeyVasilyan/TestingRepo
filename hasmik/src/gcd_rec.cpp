#include <iostream>
using namespace std;
int gcd(int n, int m)
{
    if (m==0)
       return n;
    if (n==0)
       return m;

    if (n==m)
        return n;

    if (n > m)
        return gcd(n-m, m);
    return gcd(n,m-n);
}

int main()
{
    int a,b;
    cin>>b>>b;
    cout<<" GCD is "<<gcd(a, b)<<endl;
    return 0;
}
