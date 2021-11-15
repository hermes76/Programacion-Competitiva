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
vector<ll> visited(100005,-1);
bool posible;
bool bipartito(ll node, ll color)
{
    visited[node]=color;

    for(ll x=0; x<graph[node].size(); x++)
    {
        if(visited[graph[node][x]]!=-1 && visited[graph[node][x]] == visited[node])
            return false;
        if(visited[graph[node][x]]==-1)
            if( !bipartito(graph[node][x],(color+1)%2))
                return false;
    }
    return true;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(ll x=0; x<m; x++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(ll x=1; x<=n; x++)
    {
        if(visited[x]==-1)
        if(!bipartito(x,0)){
            cout<<"IMPOSSIBLE";return;
        }
    }
    for(ll x=1; x<=n; x++)
        cout<<visited[x]+1<<endl;
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

