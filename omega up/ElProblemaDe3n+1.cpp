#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;
int solve(int m)
{
    int cuenta=1;
     while(m!=1)
    {
    if(m%2==0)m/=2;
    else m=m*3+1;
    cuenta++;
    }
    return cuenta;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a=-1;
    float k;
    int g;
    for(int x=m; x>=n; x--)
    {
        k=ceil(x/2.0);
        cout<<x<<endl;
        g=k;
        if(g%2==1)
        {
            a=solve(x);
            break;
        }
    }
    cout<<a;
}
