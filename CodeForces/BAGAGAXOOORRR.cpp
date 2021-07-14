#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;
string solve(ll arr[], ll n)
{
    ll cuenta=0;
    for(ll x=0; x<n; x++)cuenta+=arr[x];
    if(cuenta%2)return "NO";
    ll izq=0;
    ll der=0;
    ll x=0;
    for(x; x<n and izq!= cuenta/2; x++)
    {
        izq^=arr[x];
    }
    for(x; x<n; x++)
    {
        der^=arr[x];
    }
    if(der==izq)
        return "YES";
    return "NO";

}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll arr[n];
        for(ll x=0; x<n; x++)cin>>arr[x];
        cout<<solve(arr,n)<<"\n";

    }
}

