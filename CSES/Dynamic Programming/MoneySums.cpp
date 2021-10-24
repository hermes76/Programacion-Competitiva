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
    ll limite=100005;

    vector<vector<bool>> dp(2,vector<bool>(limite));

    for(ll x=0; x<n; x++)
        cin>>nums[x];

    for(ll x=1; x<limite; x++)
        dp[0][x]=false;

    dp[0][0]=true;
    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<=limite; y++)
        {
            dp[1][y]=dp[0][y];
            if(y-nums[x]>=0)
                dp[1][y]=dp[1][y]|dp[0][y-nums[x]];
        }
        dp[0]=dp[1];
    }

    vll ans;
    for(ll x=1; x<limite; x++)
        if(dp[1][x])
            ans.push_back(x);

    cout<<ans.size()<<endl;
    for(auto x:ans)
        cout<<x<<" ";
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

