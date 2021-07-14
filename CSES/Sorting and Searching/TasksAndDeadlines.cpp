
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

ll solve(pair<ll,ll> arr[], ll n)
{
    ll reward=0;
    ll duration=0;
    for(ll x=0; x<n; x++)
    {
        duration+=arr[x].first;
        reward+=arr[x].second-duration;
    }
    return reward;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
     pair< ll , ll > arr[n];
    for(ll x=0; x<n; x++)
        cin>>arr[x].first>>arr[x].second;
    sort(arr,arr+n);
    cout<<solve(arr,n);
}
