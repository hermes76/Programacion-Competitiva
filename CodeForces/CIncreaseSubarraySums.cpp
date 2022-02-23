
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
    ll n,m;
    cin>>n>>m;
    vector<ll> nums(n);
    vector<ll> range(n+1,-INF);
    range[0]=0;

    for(ll x=0; x<n; x++)   cin>> nums[x];

    for(ll x=0; x<n; x++)
    {
        ll sum=0;
        for(ll y=x; y<n; y++)
        {
            sum+=nums[y];
            range[y-x+1]= max(range[y-x+1],sum);
        }
    }
    for(ll x=0; x<=n; x++)
    {
        ll res=-INF;
        for(ll y=0; y<=n; y++)
        {
            res=max(res, range[y] + min(x,y) * m);
        }
        cout<<res<<" ";
    }
    cout<<endl;



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
