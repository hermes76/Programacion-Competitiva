#include <iostream>
#include <math.h>
using namespace std;
bool func(int tempo, int a,int b, int n)
{
    if(floor(tempo/a) + floor(tempo/b) >=n)
        return 1;
        return 0;
}
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(n==1)
        cout<<min(a,b);
    else
    {
        int k=0;
        for(int x=1e9; x>=1; x/=2)
        {
            while(!func(k+x,a,b,n-1))k+=x;
        }
        cout<<k+1+min(a,b);
    }
}
