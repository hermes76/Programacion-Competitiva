
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

ll solve(ll N)
{
    ll sums=0;
    ll siguiente=1;
    ll cuenta=1;
    while(sums+siguiente<N)
    {
        sums+=siguiente;
        if((N-sums)%(siguiente+1)==0)
            cuenta++;
        siguiente++;
    }
    return cuenta;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,N;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        cin>>N;
        cout<<"Case #"<<x<<": "<<solve(N)<<"\n";
    }
}
