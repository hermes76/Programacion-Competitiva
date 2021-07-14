#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m,k,l;
    cin>>n>>m;
    float asesinos[n];
    float ataque;
    for(int x=0; x<n; x++)
    {
        asesinos[x]=1.000000;
    }
    for(int x =0; x<m; x++)
    {
        cin>>l;
        cin>>k;
        cin>>ataque;
        asesinos[k-1]=ataque*asesinos[l-1];
        asesinos[k-1]=1-asesinos[k-1];
    }
    for(int x =0; x<n; x++)
    {
        cout<<asesinos[x]<<endl;
    }
}