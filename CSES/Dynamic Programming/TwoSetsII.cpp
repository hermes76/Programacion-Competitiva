
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

ll n;
ll goal;

ll ways()
{
    vll dp(goal+1,0);
    vll aux_dp(goal+1,0);
    for(ll x=2; x<=n; x++)
    {
        aux_dp[1]=1;
        for(ll y=0; y<=goal; y++)
        {
            if(y-x>=1)
                dp[y]=aux_dp[y]+aux_dp[y-x]%MOD;
            else
                dp[y]=aux_dp[y]%MOD;
        }

        aux_dp=dp;
    }
    return dp[goal]%MOD;
}
void solve()
{

    cin>>n;
    goal=n*(n+1)/2;
    if(goal%2==1)
        cout<<0;
    else
    {
        goal/=2;
        cout<<ways();
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
