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
    vector<set<ll>> neighboor(n+1);
    bitset<500001> bs;
    bs.reset();
    for(ll x=0; x<n-2; x++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        neighboor[a].insert(b);
         neighboor[a].insert(c);

         neighboor[b].insert(a);
         neighboor[b].insert(c);

         neighboor[c].insert(a);
         neighboor[c].insert(b);
    }

    ll p_i1,p_i2;

    for(ll x=1; x<=n; x++)
    {
        if(neighboor[x].size()==2)
        {
            p_i1=x;
            bs[x]=1;
            break;
        }
    }

    for(auto x: neighboor[p_i1])
    {
        if(neighboor[x].size()==3)
        {
            p_i2=x;
            bs[x]=1;
            break;
        }
    }
    vll ans(n);

    ans[0]=p_i1;
    ans[1]=p_i2;

    for(ll x=2; x<n; x++)
    {
        for(auto y: neighboor[p_i1])
        {
            if(!bs[y] && neighboor[p_i2].find(y) != neighboor[p_i2].end())
            {
                bs[y]=1;
                ans[x]=y;
                p_i1=p_i2;
                p_i2=y;
            }
        }
    }

    for(auto x: ans)
        cout<<x<<" ";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    ///cin>>t;
    while(t--)
        solve();
}

