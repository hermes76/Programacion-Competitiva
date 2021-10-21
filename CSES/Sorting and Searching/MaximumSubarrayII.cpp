//libraries
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//namespaces
//using namespace __gnu_pbds;
using namespace std;

//templates
/*
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

*/

//typedefs
typedef long long ll;
typedef double dll;
typedef vector<ll> vll;

//defines
#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e18
#define MOD 1000000007


void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    multiset<ll> window;
    vll nums(n+1,0);
    vll prefix_sum(n+1,0);

    for(ll x=1; x<=n; x++)
        cin>>nums[x];


    for(ll x=1; x<=n; x++)
    {
        prefix_sum[x]=nums[x];
        prefix_sum[x]+=prefix_sum[x-1];
    }

    ll ans=-INF;
    for(ll x=a; x<=n; ++x)
    {
        if(b<x)
        {
            window.erase(window.find(prefix_sum[x-b-1]));
        }
        window.insert(prefix_sum[x-a]);
        ans=max(ans,prefix_sum[x]-*window.begin());
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}

