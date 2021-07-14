#include <iostream>
using namespace std;
int valmax(int n)
{
    int maximo=0;
    while(n>0)
    {
        maximo=max(maximo,n%10);
        n/=10;

    }
    return maximo;
}
int main()
{
    int n;
    int cuenta=0;
    cin>>n;
    while(n>0)
    {
        n-=valmax(n);
        cuenta++;
    }
    cout<<cuenta;
}
