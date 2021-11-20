
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
    vll city(n);
    for(ll x=0; x<n; x++)cin>>city[x];

    cout<<city[1]-city[0] <<" "<<city[n-1]-city[0]<<endl;
    for(ll x=1; x<n-1; x++)
    {
        cout<<min(city[x+1]-city[x], city[x]-city[x-1])<<" "<<max(city[x]-city[0], city[n-1]-city[x])<<endl;
    }
    cout<<city[n-1]-city[n-2] <<" "<<city[n-1]-city[0]<<endl;
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
