
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
    vll knots_knowledge(n-1);
    vll knots(n);

    for(ll x=0; x<n; x++)
    cin>>knots[x];

    for(ll x=0; x<n-1; x++)
        cin>>knots_knowledge[x];



    sort(all(knots));
    sort(all(knots_knowledge));

    for(ll x=0; x<n-1; x++)
    {
        if(knots[x]!=knots_knowledge[x])
        {
            cout<<knots[x]<<endl;
            return;
        }
    }
    cout<<knots[n-1]<<endl;
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
