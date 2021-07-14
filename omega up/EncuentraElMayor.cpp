#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m;
    int maximo=0;
    for(int x =0; x<n; x++)
    {
        cin>>m;
        maximo=max(m,maximo);
    }
    cout<<maximo;
}