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
    string cad;
    cin>>cad;

    ll ans=0;

    ll mini=INF;
    ll x=cad.length()-1;
    ll aux=0;
    for(x; x>=0; x--)
    {

        if(cad[x]=='5')
        {
            aux=0;
            for(ll y=x-1; y>=0; y--)
            {
                if(cad[y]=='7'|| cad[y]=='2')
                    break;
                else aux++;
            }
            mini=min(mini,ans+aux);
        }
        else if(cad[x]=='0')
        {
            aux=0;
            for(ll y=x-1; y>=0; y--)
            {
                if(cad[y]=='0' || cad[y]=='5')
                    break;
                else aux++;
            }
            mini=min(mini,ans+aux);
        }
        ans++;
    }
    cout<<mini<<endl;
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

