
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

ll solve(ll arr[], ll n, ll m)
{
    ll cont=0;
    for(cont; cont<m; cont++)
    for(ll x=0; x<n/2 and cont<m; x++)
    {
        if(arr[x]==0)continue;
        arr[x]--;
        arr[n-1-x]++;
    }
        for(ll x=0; x<n; x++)cout<<arr[x]<<" ";
        cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll n,m;
    while(t--)
    {
        cin>>n>>m;
        ll arr[n];
        for(ll x=0; x<n; x++)cin>>arr[x];
        solve(arr,n,m);
    }

}
