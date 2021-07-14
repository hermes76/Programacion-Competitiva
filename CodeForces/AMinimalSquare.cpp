#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,b;
    int lon;
    int minimo;
    int maximo;
    while(n--)
    {
        cin>>a>>b;
        minimo=min(a,b);
        maximo=max(a,b);
        lon=max(maximo,minimo*2);
        cout<<lon*lon<<endl;
    }
}
