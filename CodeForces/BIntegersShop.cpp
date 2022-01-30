
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
#define INF 100000000000000
#define MOD 1000000007

void solve()
{
    ll n;
    cin>>n;

    ll min_l=INF, max_r=0;
    ll cost_l=INF ,  cost_r = INF , cost_len=INF;
    ll max_len=0;

    for(ll x=0; x<n; x++)
    {
        ll l,r,c;
        cin>>l>>r>>c;

        if(l<min_l)
            min_l=l,cost_l=INF;
        if(l==min_l)
            cost_l = min(cost_l,c);

        if(max_r<r)
            max_r=r,cost_r=INF;
        if(r==max_r)
            cost_r = min(cost_r,c);

        if(max_len<r-l+1)
            max_len=r-l+1,cost_len=INF;
        if( max_len==r-l+1)
            cost_len=min(c, cost_len);

        ll ans=cost_l+cost_r;
        if(max_len==max_r-min_l+1)
            ans=min(ans,cost_len);

        cout<<ans<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    while(t--)
        solve();
}
