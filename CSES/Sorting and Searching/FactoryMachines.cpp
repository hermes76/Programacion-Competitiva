#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
bool func(ll n,ll goal, ll time, ll arr[])
{
    ll p=0;
    for(ll x=0; x<n; x++)
        p+=time/arr[x];
    if(p<goal)
    return 1;
    return 0;
}
ll solve()
{
    ll n,m; cin>>n>>m;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    ll time=0;
    for(ll x=1000000000000/2; x>0; x/=2)
        while(func(n,m,time+x,arr))time+=x;
    time++;
    return time;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}

