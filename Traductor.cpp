#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int>mapa;
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int x=0; x<n; x++)
    {
        cin>>a>>b;
        mapa[a]=b;
    }
    for(int y=0; y<m; y++)
    {
        cin>>a;
        b=mapa[a];
        if(b!=0)
        {
            cout<<mapa[a]<<"\n";
        }else{cout<<"C?"<<'\n';}
    }
}
