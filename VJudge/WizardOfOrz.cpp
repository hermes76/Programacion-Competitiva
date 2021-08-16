
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve(ll m)
{
   ll cuenta=9;
    for(ll x=0; x<m; x++)
    {
        cout<<cuenta;
        cuenta--;
        if(cuenta==-1)
            cuenta=9;
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        solve(m);
    }
}
