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
#define INF 1000000000000000000
#define MOD 1000000007

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll>a(n+2);
    vector<ll>d(n+2);

    for(ll x=0; x<n; x++)cin>>a[x];
    a[n]=m;
    for(ll x=0; x<n; x++) cin>>d[x];

    vector<vector<ll>> dp(n+2,vector<ll>(k+2,INF));

    dp[0][0]=0;
    for(ll x=0; x<=n; x++)
    {
        for(ll y=0; y<=k; y++)
        {
            for(ll z=x+1; z<=n; z++)
            {

                if(y+z-x-1<=k)
                {
                    cout<<z<<" "<<y+z-x-1<<endl;
                    dp[z][y+z-x-1]= min(dp[z][y+z-x-1], dp[x][y] + d[x] * (a[z]- a[x]));
                }
            }
            cout<<endl;

        }
    }
    ll ans=INF;

        for(ll y=0; y<=k; y++)
        {
            ans=min(dp[n][y],ans);
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
