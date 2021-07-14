
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;
ll solve(ll n)
{
    bool arr[20010];
    for(ll x=0; x<=n; x++)arr[x]=0;
    ll cuenta=0;
    ll indice=2;
    ll cons=2;
    bool act=0;
    while(cuenta<n)
    {
        cout<<arr[indice]<<endl;
        cuenta++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    solve(n);
}
