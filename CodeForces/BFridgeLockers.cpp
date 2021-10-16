
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
    ll n,m;
    cin>>n>>m;

    vll fridge(n);

    vector<pair<ll,ll>> res(n);
    for(ll x=0; x<n; x++)
        cin>>fridge[x];

    ll ans=0;
    if(m<n || n==2){
        cout<<-1<<endl;
        return;
    }

     ans+=fridge[0]+fridge[n-1];
     res[0]={1,n};
    for(ll x=1; x<n; x++)
    {
        res[x]={x,x+1};
        ans+=fridge[x-1]+fridge[x];
    }
   // res[n-1]={n,1};

    cout<<ans<<endl;
    for(auto x:res)
        cout<<x.first<<" "<<x.second<<endl;
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
