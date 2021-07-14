#include <iostream>
#define ll long long int
using namespace std;
ll expotenciacion(ll a,ll b, ll c)
{
    if(b==0)
    {
        return 1%c;
    }
    ll u = expotenciacion(a,b/2,c);
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
    int n;
    int a,b,c;
    ll valor;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        valor = expotenciacion(b,c,1000000006);
        cout<<expotenciacion(a,valor,1000000007)<<'\n';
    }
}