#include <iostream>
using namespace std;
int n,m;
int arr[1000][1000];
void V()
{
    int a[m];
    for(int y=0; y<n/2; y++)
    {
        for(int x=0; x<m; x++)
        {
            a[x]=arr[y][x];
        }
        for(int x=0; x<m; x++)
        {
            arr[y][x]=arr[n-1-y][x];
        }
        for(int x=0; x<m; x++)
        {
            arr[n-1-y][x]=a[x];

        }
    }
}
void H()
{
    int a[n];
    for(int y=0; y<m/2; y++)
    {
        for(int x=0; x<n; x++)
        {
            a[x]=arr[x][y];
        }
        for(int x=0; x<n; x++)
        {
            arr[x][y]=arr[x][m-1-y];
        }
        for(int x=0; x<n; x++)
        {
            arr[x][m-1-y]=a[x];

        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int p;
    cin>>n>>m;
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            cin>>arr[x][y];
    cin>>p;
    bool vueltas[2]={0,0};
    char car;
    for(int x=0; x<p; x++)
    {
        cin>>car;
        if(car=='H')
        {
           vueltas[0]=!vueltas[0];
        }else
        {
            vueltas[1]=!vueltas[1];
        }
    }
    if(vueltas[0]==1)
        H();
    if(vueltas[1]==1)
        V();
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<m; y++)
        {
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }


}
