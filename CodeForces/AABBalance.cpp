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
    string cad;
    cin>>cad;

    ll ab=0,ba=0;
    for(ll x=1; cad[x]; x++)
    {
        if(cad[x-1]=='a' && cad[x]=='b')
            ab++;
        else if(cad[x-1]=='b' && cad[x]=='a')
            ba++;
    }
    if(ab>ba)
    {
        for(ll x=0; cad[x]; x++)
            if(cad[x]=='a')
            {
                cad[x]='b';
                break;
            }
    }
    else if(ab<ba)
    {
        for(ll x=0; cad[x]; x++)
            if(cad[x]=='b')
            {
                cad[x]='a';
                break;
            }
    }
    cout<<cad<<endl;
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
