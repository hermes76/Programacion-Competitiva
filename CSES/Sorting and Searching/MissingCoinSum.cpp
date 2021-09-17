#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    sort(arr,arr+n);
    ll target=1;
    for(ll x=0; x<n && target>=arr[x]; x++)
    {
        target+=arr[x];
    }
    return target;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}

