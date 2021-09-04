
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
    vector <ll>::iterator it;
    vll.push_back(arr[0]);
    for(ll x=1; x<n; x++)
    {
        it=upper_bound(all(vll),arr[x]);
        if(it-vll.begin()== vll.size())
            vll.push_back(arr[x]);
        else
            *it=arr[x];
    }
    return vll.size();

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}
