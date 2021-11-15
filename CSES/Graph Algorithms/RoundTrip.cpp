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
vector<bool> visited(100005,false);
vll ans;
bool contener;
bool bfs(ll parent_node, ll node)
{
    visited[node]=true;

    for(ll x=0; x<graph[node].size(); x++)
    {
        if(visited[graph[node][x]])
        {
            if(graph[node][x]!=parent_node)
            {
                ans.push_back(graph[node][x]);
                ans.push_back(node);
                return true;

            }
        }
        else
            if(bfs(node, graph[node][x]))
            {
                if(contener)
                ans.push_back(node);
                if(ans[0]==node)
                    contener=false;
                return true;
            }
    }
    return false;
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    contener=true;
    for(ll x=0; x<m; x++)
    {
        ll a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    for(ll x=1; x<=n; x++)
    {
        if(!visited[x])
            if(bfs(0,x)){
                cout<<ans.size()<<endl;
                for(auto y: ans)
                    cout<<y<<" ";
                return;
            }
    }
    cout<<"IMPOSSIBLE";
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
