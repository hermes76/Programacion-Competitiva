
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

    for(ll x=0; x<n; x++)
        cin>>nums[x];

    sort(all(nums));
    ll diference = 0-nums[0];
    ll sum=0;
    ll ans=0;
    ll p=0;
    for(ll x=0; x<n; x++)
    {
        nums[x]+=diference;
    }
    if(nums[0]==nums[n-1])
    {
        cout<<-1<<endl;
        return;
    }
    vll ::iterator it = unique(nums.begin(), nums.end());
    nums.resize(distance(nums.begin(),it));
    ans=nums[1];
    for(ll x=1; x<nums.size(); x++)
    {
        ans=__gcd(ans, nums[x]);
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
