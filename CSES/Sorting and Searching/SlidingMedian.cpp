
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef double dll;

using namespace __gnu_pbds;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector <ll> vll;

ll solve()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ordered_set window;
    for(ll x=0; x<n; x++)
        cin>>arr[x];
    for(ll x=0; x<k; x++)
    {
        window.insert(make_pair(arr[x],x));
    }
       auto it=window.find_by_order((k-1)/2);
        cout<<it->first<<" ";
    for(ll x=k; x<n; x++)
    {
       window.erase(make_pair(arr[x-k],x-k));
       window.insert(make_pair(arr[x],x));
       cout<<window.find_by_order((k-1)/2)->first<<" ";
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
