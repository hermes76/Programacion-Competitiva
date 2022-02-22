
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

    vector<int> keys(3,0);

    for(int x=0; cad[x]; x++)
    {
        if(cad[x]=='r' || cad[x]=='R')
            if(islower(cad[x]))
            {
                keys[0]++;
            }else
            {
                keys[0]--;
            }
        if(cad[x]=='g' || cad[x]=='G')
        if(islower(cad[x]))
        {
            keys[1]++;
        }else
        {
            keys[1]--;
        }if(cad[x]=='b' || cad[x]=='B')
        if(islower(cad[x]))
        {
            keys[2]++;
        }else
        {
            keys[2]--;
        }

        for(int y=0; y<3; y++)
            if(keys[y]<0)
            {
                    cout<<"NO\n";
                    return;
            }
    }
    cout<<"YES\n";
    return;
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
