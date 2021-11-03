
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
#define INF 10000000000000000
#define MOD 1000000007

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll ans=0;

    vector<vll> dp(501,vll(501,INF));

    for(ll x=0; x<m; x++)
    {
        dp[0][x]=x;
        if(x<n)
            dp[x][0]=x;
    }
    for(ll x=1; x<min(n,m); x++)
    {
        dp[x][x]=0;
        for(ll y=x+1; y<max(m,n); y++)
        {
            dp[x][y] = dp[x-1][y]+dp[0][y];
            for(ll z=0; z<y; z++)
            {
                dp[x][y]=min(dp[x][y], dp[x][z]+dp[x][(y-z)-1]+1);
            }
            for(ll z=0; z<x; z++)
            {
                dp[x][y]=min(dp[x][y], dp[z][y]+dp[(x-z)-1][y]+1);
            }
            if(y<n)
            dp[y][x]=dp[x][y];
        }
    }
   /* for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<m; y++)
            cout<<dp[x][y]<<" ";
        cout<<endl;
    }*/
    cout<<dp[n-1][m-1];
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
