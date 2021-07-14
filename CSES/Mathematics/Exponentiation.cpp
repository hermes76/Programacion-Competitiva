#include <iostream>
#include <math.h>
using namespace std;
long long int expotenciacion(int a,int b, int c)
{
    if(b==0)
    {
        return 1;
    }
    long long int u = expotenciacion(a,b/2,c);
    u=(u*u)%c;
    if(b%2==1)
    {
        u=(u*a)%c;
    }
    return u;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int x;
    cin>>x;
    int a,b;
    while(x--)
    {
        cin>>a>>b;
        cout<<expotenciacion(a,b,1000000007)<<endl;
    }
}