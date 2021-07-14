#include <iostream>
using namespace std;
long long int fac(int n)
{
    if(n==1 or n==0)
    {
        return 1;
    }
    return fac(n-1)*n;
}
int main()
{
    int n;
    cin>>n;
    cout<<fac(n);
}