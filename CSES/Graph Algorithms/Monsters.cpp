
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

vector<vector<char>> grid (1005,vector<char>(1005));
vector<vll> visited (1005,vll(1005,0));
vector<tuple<ll,ll,ll>> monsters;
ll pos_x[4]={1,0,-1,0};
ll pos_y[4]={0,1,0,-1};
string direccion = "ULDR";
void bfs(ll n, ll m)
{
    queue<tuple<ll,ll,ll>> cola;
    tuple<ll,ll,ll> player;
    vector<char> path;
    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<m; y++)
        {
            if(grid[x][y]=='A')
            {
                player={x,y,1};
                  visited[x][y]=1;
            }
            else if(grid[x][y]=='M')
            {
                visited[x][y]=-1;
                cola.push({x,y,-1});
            }
        }
    }
    cola.push(player);
    if(get<0>(player)==0 || get<0>(player)==n-1 || get<1>(player)==0 || get<1>(player)==m-1)
    {
        cout<<"YES\n"<<0;
        return;
    }

    while(!cola.empty())
    {
        tuple<ll,ll,ll> state = cola.front();
        cola.pop();
        for(ll x=0; x<4; x++)
        {
            tuple<ll,ll,ll> next = state;
            get<0>(next)+=pos_x[x];
            get<1>(next)+=pos_y[x];
            if(get<2>(next)<0)
                get<2>(next)--;
            else
                get<2>(next)++;

            if(get<0>(next)<n && get<0>(next)>=0 && get<1>(next)<m && get<1>(next)>=0 && grid[get<0>(next)][get<1>(next)] != '#' && visited[get<0>(next)][get<1>(next)]==0)
            {

                visited[get<0>(next)][get<1>(next)] = get<2>(next);
                if((get<0>(next)==0 || get<0>(next)==n-1 || get<1>(next)==0 || get<1>(next)==m-1) && get<2>(next)>=1)
            {
                cout<<"YES\n"<<get<2>(next)-1<<endl;

                while(get<2>(next)>0)
                {
                    for(ll y=0; y<4; y++)
                    {
                        tuple<ll,ll,ll>ultimate=next;
                        get<0>(ultimate)+=pos_x[y];
                        get<1>(ultimate)+=pos_y[y];
                        if(get<0>(ultimate)<n && get<0>(ultimate)>=0 && get<1>(ultimate)<m && get<1>(ultimate)>=0 && visited[get<0>(ultimate)][get<1>(ultimate)]==get<2>(next)-1)
                        {

                            get<0>(next) = get<0>(ultimate);
                            get<1>(next) = get<1>(ultimate);
                            get<2>(next)--;
                            path.push_back(direccion[y]);
                            break;
                        }
                    }
                }
                reverse(all(path));
                    for(ll y=1; y<path.size(); y++)
                        cout<<path[y];
                    return ;
            }
                cola.push(next);
            }

        }
    }
    cout<<"NO";

}
void solve()
{
    ll n,m;
    cin>>n>>m;

    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<m; y++)
            cin>>grid[x][y];
    }

    bfs(n,m);

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
