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

vector<vll> graph(100005);
vector<bool> visited(100005);
void dfs(ll node)
{
    if(visited[node])
        return;
    visited[node]=true;
    for(ll x=0; x<graph[node].size(); x++)
        dfs(graph[node][x]);
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    for(ll x=0; x<m; x++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        visited[a]=false;
        visited[b]=false;
    }
    ll ans=0;
    vector<pair<ll,ll>>edges;
    ll a=-1;
    for(ll x=1; x<=n; x++)
    {
        if(!visited[x])
        {
            if(a!=-1)
            {
                edges.push_back({a,x});
            }

            a=x;
            ans++;
            dfs(x);
        }
    }

    cout<<ans-1<<endl;
    for(pair<ll,ll>edge : edges)
    {
        cout<<edge.first<<" "<<edge.second<<endl;
    }
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

