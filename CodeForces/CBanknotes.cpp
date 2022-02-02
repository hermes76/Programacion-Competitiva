
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
    ll n,k;
    cin>>n>>k;
    k++;
    vector<ll> nums(n);
    for(ll x=0; x<n; x++)
        cin>>nums[x];

    for(ll x=0; x<n; x++)
    {
        ll a= nums[x];
        nums[x]=1;
        for(ll y=1; y<=a; y++)
            nums[x]*=10;
    }

    ll res=0;
    for(ll x=0; x<n; x++)
    {
        ll cnt= k;
        if(x+1<n)
            cnt= min(cnt, nums[x+1]/nums[x]-1);
            res+= nums[x]*cnt;
        k-=cnt;
    }
    cout<<res<<endl;

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
