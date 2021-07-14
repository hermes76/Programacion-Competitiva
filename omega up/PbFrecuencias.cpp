#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    for(int x=0; x<=n; x++)arr[x]=0;
    int b,a;
    for(int x =0; x<m; x++)
    {
        cin>>b;
        arr[b]++;
    }
    for(int x=1; x<=n; x++)
    {
        cout<<x<<"-"<<arr[x]<<endl;
    }
}
