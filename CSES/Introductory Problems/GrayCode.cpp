
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
void print(ll num, ll maxPow)
{
    for(ll x=maxPow; x>0; x>>=1)
       cout<<((num&x)? 1:0);
    cout<<"\n";
}
ll solve(ll n)
{
    ll aux;
    ll maxPow=(1<<(n-1));
    for(ll x=0; x<(1<<n); x++)
    {
        aux=x>>1;
        print(x^aux,maxPow);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    solve(n);
}
