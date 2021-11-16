
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
#define INF 100000000000000000
#define MOD 1000000007

vector<vector<pair<ll,ll>>> graph(100005);
vll distances(100005,INF);
vector<bool> visited(100005,false);
void dijkstra(ll n)
{
    priority_queue<pair<ll,ll>> cola;
    cola.push({0,1});
    distances[1]=0;

    while(!cola.empty())
    {
        ll state = cola.top().second;
        cola.pop();
        if(visited[state])
            continue;
        visited[state]=true;

        for(pair<ll,ll> x:graph[state])
        {
            ll b= x.first , w= x.second;
            if(distances[b]> distances[state]+w)
               {
                distances[b]=distances[state]+w;
                    cola.push({-distances[b],b});
               }
        }
    }
    for(ll x=1; x<=n; x++)
        cout<<distances[x]<<" ";
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    for(ll x=0; x<m; x++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    dijkstra(n);
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
