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
    ll n,m;
    cin>>n>>m;
    vll dp(100000);
    vll keys(100000);

    dp[0]=1;
    dp[10]=10;
    for(ll x=11; x<=19; x++)
        dp[x]=dp[x-1]+dp[10]-1;

        ll current=20;
    for(ll x=200; x<=1000; x++,current++)
    {
        dp[current]=dp[current-1]+81;
        keys[current]=x;
    }

    for(ll x=200; x<100000000000000000; x+=100,current++)
    {
        dp[current]=dp[current-1]+81;
        keys[current]=x;
        cout<<keys[current]<<" "<<dp[current]<<endl;
    }
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

