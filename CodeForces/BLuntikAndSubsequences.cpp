
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
    vll values(n);
    ll ceros=0;
    ll unos=0;
    ll ans=0;
    for(ll x=0; x<n; x++)
    {
        cin>>values[x];
    }
    for(ll x=0; x<n; x++)
    {
        if(values[x]==0)ceros++;
        if(values[x]==1)
            unos++;
    }
    ans=pow(2,ceros);
    if(unos-1>=0)
        ans*=unos;
    else ans=0;

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
