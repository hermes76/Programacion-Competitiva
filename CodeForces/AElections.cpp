
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
    vll votes(3);
    ll maximo=0;
    ll rep=0;
    for(ll x=0; x<3; x++)
        cin>>votes[x];

    for(ll x=0; x<3; x++)
        maximo=max(maximo,votes[x]);

    for(ll x=0; x<3; x++)
        if(votes[x]==maximo)
        rep++;

    for(ll x=0; x<3; x++)
        if(rep>1)
        {cout<<(maximo+1)-votes[x]<<" ";
        }else
        {
            if(votes[x]!=maximo)
                cout<<(maximo+1)-votes[x]<<" ";
            else cout<<0<<" ";
        }
    cout<<endl;
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
