
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
#define INF 1e9
#define MOD 1000000007


void solve()
{
    ll n;
    cin>>n;
    vll nums(n);

    for(ll x=0; x<n; x++)cin>>nums[x];
    vll dp(n,1);
    set<pair<ll,ll>> dp_set;
    ll ans=1;

    dp[0]=1;
    dp_set.insert({nums[0],1});

    for(ll x=1; x<n; x++)
    {
       set<pair<ll,ll>>::iterator it =dp_set.lower_bound({nums[x],1});
       if(it==dp_set.begin())
       {
           if(it->first>=nums[x])
           {
                dp_set.erase(it);
                dp_set.insert({nums[x],1});
           }
           continue;
       }
       advance(it,-1);
       dp[x]=max(dp[x],dp[x]+it->second);
       it=dp_set.lower_bound({nums[x],dp[x]+1});
       if(it->first>= nums[x] && it->second<=dp[x])
            dp_set.erase(it);
       ans=max(dp[x],ans);
       dp_set.insert({nums[x],dp[x]});
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
