#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a, b;
    int suma=0;
    for(int x =0; x<n; x++)
    {
        cin>>a>>b;
        suma+=a*b;
    }
    cout<<suma;
}