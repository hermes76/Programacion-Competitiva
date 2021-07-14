
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;
ll maxi(ll a, ll b)
{
    if(a>b)
        return a;
    return b;
}
bool isgood(ll arr[], ll n, ll k,ll maximo)
{
    ll suma=0;
    if(k>maximo)
        return 0;
    for(ll x=n-1; x>=0; x--)
    {
        if(suma+arr[x]<=k)
            suma+=arr[x];
    }
    if(suma==k)
        return 1;
    return 0;
}
ll solve(ll arr[], ll n)
{
    ll k=0;
    ll maximo=0;
    for(ll x=0; x<n; x++)maximo=maxi(maximo,arr[x]);
    for(ll x=maximo/2; x>=1; x>>=2)
        while(isgood(arr,n,k+n,maximo))k+=n;
    k++;
    return k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    sort(arr,arr+n);
    cout<<solve(arr,n);
}
