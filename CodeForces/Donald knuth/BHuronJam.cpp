
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    ll suma=0;
    ll arr[n];
    for(ll x=0; x<n; x++)
        cin>>arr[x];
    sort(arr,arr+n);
    for(ll x=n-1; x>=1; x-=2)
        suma+=arr[x]-arr[x-1];
    cout<<suma;
}
