#include <iostream>
#define ll long long int
using namespace std;
bool func(ll a ,ll b, ll n, ll mid)
{
    ll h1= mid/a;
    ll h2= mid/b;
    return h1*h2>=n;
}
ll binary(ll a, ll b, ll n)
{
    ll m,l,h;
    l=0;
    h=3037000499;
    while(l+1<h)
    {
        m=(l+h)/2;
        if(func(a,b,n,m))
            h=m;
        else l=m;
    }
    return h;
}
int main()
{
    ll n,a,b;
    cin>>a>>b>>n;
   cout<<binary(a,b,n);
}
