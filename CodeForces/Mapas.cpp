#include <iostream>
using namespace std;
int n;
char arr[500][500];
char arr2[500][500];
void V()
{
    int a[n];
    for(int y=0; y<n/2; y++)
    {
        for(int x=0; x<n; x++)
        {
            a[x]=arr[y][x];
        }
        for(int x=0; x<n; x++)
        {
            arr[y][x]=arr[n-1-y][x];
        }
        for(int x=0; x<n; x++)
        {
            arr[n-1-y][x]=a[x];

        }
    }
}
void H()
{
    int a[n];
    for(int y=0; y<n/2; y++)
    {
        for(int x=0; x<n; x++)
        {
            a[x]=arr[x][y];
        }
        for(int x=0; x<n; x++)
        {
            arr[x][y]=arr[x][n-1-y];
        }
        for(int x=0; x<n; x++)
        {
            arr[x][n-1-y]=a[x];

        }
    }
}
void noventa()
{
    int aux[n][n];
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            aux[x][n-1-y]=arr[y][x];
        }
    }
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            arr[x][y]=aux[x][y];
        }
    }
}
bool iguales()
{
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            if(arr[x][y]!=arr2[x][y])
                return 0;
    return 1;
}
bool solve()
{
     for(int x=0; x<4; x++)
        {
            if(iguales())return 1;
            V();
            if(iguales())return 1;
            H();
            if(iguales())return 1;
            V();
            if(iguales())return 1;
            H();
            if(iguales())return 1;
            noventa();
        }
        return 0;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            cin>>arr[x][y];
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)
            cin>>arr2[x][y];
    if(solve())cout<<"IGUALES";
    else cout<<"DIFERENTES";

}
