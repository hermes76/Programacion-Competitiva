#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int maximo=-99999;
    int cuenta=0;
    while(n--)
    {
        cin>>a;
        cuenta=max(cuenta+a,a);
        maximo=max(cuenta,maximo);
    }
    cout<<maximo;
}