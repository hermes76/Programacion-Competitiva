
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
    ll n,m,rb,cb,rd,cd;
    cin>>n>>m>>rb>>cb>>rd>>cd;


    ll res=INF;
    if(rb>rd)
        res = min( res, (n-rb) * 2 + (rb-rd));
    else if(rd==rb)
        res=0;
    else
        res = min( res, (rd - rb));

    if(cb > cd)
        res= min( res, (m-cb) * 2 + (cb-cd));
    else if( cb==cd)
        res=0;
    else res = min( res, (cd- cb));

    cout<<res<<endl;
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
