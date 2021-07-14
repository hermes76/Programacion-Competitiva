#include <iostream>
using namespace std;
int n,m;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int arr[n];
    int a;
    int maximo=0;
    for(int x =0; x<n; x++)
    {
        arr[x]=0;
    }
    for(int x =0; x<m; x++)
    {
        for(int y =0; y<n; y++)
        {
            cin>>a;
            arr[y]+=a;
            maximo=max(maximo,arr[y]);
        }
    }
    for(int x =0; x<n; x++)
    {
        if(maximo==arr[x])
        {
            cout<<x+1<<" ";
        }
    }
}
