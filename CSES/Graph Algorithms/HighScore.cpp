
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

vector<tuple<ll,ll,ll>> graph;
vll score(2505,-INF);
vector<bool> conectivity(2505,false);
void bellman(ll n)
{
    score[1]=0;
    conectivity[1]=true;
    for(ll x=1; x<=n-1; x++)
    {
        for(tuple<ll,ll,ll> y : graph)
        {
            ll a,b,c;
            tie(a,b,c)=y;
            if(conectivity[a])
                conectivity[b]=true;
        }
    }

    for(ll x=1; x<=n-1; x++)
    {
        for(tuple<ll,ll,ll> y : graph)
        {

            ll a,b,c;
            tie(a,b,c)=y;
            if(!conectivity[a])continue;
            score[b]= max(score[b], score[a]+c);
        }
    }
    ll ans=score[n];
     for(ll x=1; x<=n-1; x++)
    {
        for(tuple<ll,ll,ll> y : graph)
        {
            ll a,b,c;
            tie(a,b,c)=y;
            if(score[b]< score[a]+c && conectivity[a])
            {
                score[b]=INF;
            }
        }
    }

    if(score[1]!=0 || score[n]!= ans)
    {
        cout<<-1;
        return;
    }
    cout<<score[n];
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    for(ll x=0; x<m; x++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph.push_back({a,b,c});
    }

    bellman(n);
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
