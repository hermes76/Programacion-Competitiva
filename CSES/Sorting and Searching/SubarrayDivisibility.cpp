
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
    ll ans=0;
    map<ll,ll> positive;
    map<ll,ll> negative;
    ll num;
    ll sum=0;
    for(ll x=0; x<n; x++)
    {
        cin>>num;
        sum+=num;
        if(sum<0)
            negative[(sum*-1)%n]++;
        else positive[(sum)%n]++;

        if(sum>=0 && sum%n==0 || sum<0 && (sum*-1)%n==0)
            ans+=positive[0]+negative[0];
        else if(sum>0)
        ans+=positive[sum%n]-1+negative[n-sum%n];
        else
             ans+=positive[n-(sum*-1)%n]+negative[(sum*-1)%n]-1;
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
