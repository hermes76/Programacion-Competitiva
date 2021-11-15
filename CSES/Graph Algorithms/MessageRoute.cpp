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

vector <vll> graph(100005);
vector <ll> path(100005,-1);

void bfs(ll n)
{
    queue <pair<ll,ll>> cola;

    cola.push({1,1});
    path[1]=1;
    vll ans;

    while(!cola.empty())
    {
        pair<ll,ll> state_currently = cola.front();
        cola.pop();

        for(ll x=0; x<graph[state_currently.first].size(); x++)
        {
             pair<ll,ll> state_future ={graph[state_currently.first][x],state_currently.second+1};
            if(path[graph[state_currently.first][x]]==-1)
            {
                pair<ll,ll> state_future ={graph[state_currently.first][x],state_currently.second+1};
                path[state_future.first]=state_future.second;
                cola.push(state_future);
            }

        if(state_future.first==n)
        {
            cout<<state_future.second<<endl;
            ll node=n;
            ans.push_back(n);
            while(node!=1)
            {
                for(ll z=0; z<graph[node].size(); z++)
                {
                    if(path[graph[node][z]]==state_future.second-1)
                    {
                        state_future.second--;
                        node=graph[node][z];
                        ans.push_back(node);
                        break;
                    }
                }
            }
            reverse(all(ans));
            for(ll y: ans)
                cout<<y<<" ";
            return;
        }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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

    bfs(n);
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
