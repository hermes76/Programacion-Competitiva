#include <iostream>
using namespace std;
int n;
int espacios;
long long int cuenta=0;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    if(n>=3)
    {
        cuenta=(n/3)*7;
        n%=3;
    }
    if(n==1)
    {
        cuenta-=3;
        n==0;
    }else if (n==2)
    {
        cuenta++;
        n=0;
    }
    cout<<cuenta;
}
