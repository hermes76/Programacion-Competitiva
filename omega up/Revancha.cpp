#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a;
    cin>>a;
    int minimo=a;
    int maximo=a;
    long long int suma=a;
    for(int x=1; x<n; x++)
    {
        cin>>a;
        minimo=min(minimo,a);
        maximo=max(maximo,a);
        suma+=a;
    }
    cout<<minimo<<" "<<maximo<<" "<<suma/n;
}
