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


vll nums;
bool isGood(ll k, ll n, ll m)
{
    ll sum=0;
    ll parts=1;
    for(ll x=0; x<n; x++)
    {
        if(sum+nums[x]<=k)
        sum+=nums[x];
        else
        {
            if(nums[x]>k)
                return 1;
            parts++;
            sum=nums[x];
        }
    }
    if(parts>m)
        return 1;
    return 0;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    nums.resize(n);
    for(ll x=0; x<n; x++)
        cin>>nums[x];

    ll ans=-1;
    for(ll x=1000000000000; x>0; x/=2)
        while(isGood(ans+x,n, m))ans+=x;
    cout<<ans+1;

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

