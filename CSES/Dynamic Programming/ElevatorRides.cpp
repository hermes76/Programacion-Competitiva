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
#define INF 10000000000000000
#define MOD 1000000007

void solve()
{
    ll n,m;
    cin>>n>>m;

    vll weight(n);
    for(ll x=0; x<n; x++)cin>>weight[x];

    vector<pair<ll,ll>> solutions(1<<n,{1,0});

    for(ll x=1; x<1<<n; x++)
    {
        solutions[x]={n+1,0};
        for(ll y=0; y<n; y++)
        {
            if(x&(1<<y))
            {
                pair<ll,ll> best= solutions[x^(1<<y)];

                if(best.second+weight[y]<=m)
                {
                    best.second+=weight[y];
                }
                else{
                    best.first++;
                    best.second=weight[y];
                }

                solutions[x]=min(solutions[x],best);
            }
        }
    }
    cout<<solutions[(1<<n)-1].first;
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
