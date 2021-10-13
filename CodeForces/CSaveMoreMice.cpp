
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

bool isGood(ll k,ll n,vll mice)
{
    ll cat=0;

    for(ll x=k-1; x>=0; x--)
    {
        if(cat>=mice[x])
            return 0;
        cat+=n-mice[x];
    }
    return 1;
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    vll mice(m);
    for(ll x=0; x<m; x++)
        cin>>mice[x];

    sort(all(mice),greater<>());

    ll ans=1;

    for(ll x=INF/2; x>0; x/=2)
    {
        while( ans+x<=m && isGood(ans+x,n,mice)) ans+=x;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    //t=1;
    cin>>t;
    while(t--)
        solve();
}
