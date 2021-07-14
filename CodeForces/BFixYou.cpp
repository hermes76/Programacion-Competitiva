#include <iostream>
using namespace std;

char arr[100][100];
int n,a,b;
long long int solve()
{
    int cuenta=0;
    for(int x =0; x<b; x++)
    {
        if(arr[a-1][x]=='D')
        {
            cuenta++;
        }
    }
    for(int x =0; x<a; x++)
    {
        if(arr[x][b-1]=='R')
        {
            cuenta++;
        }
    }
    return cuenta;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        for(int x =0; x<a; x++)
        {
            for(int y=0; y<b; y++)
            {
                cin>>arr[x][y];
            }
        }
        cout<<solve()<<endl;
    }
}