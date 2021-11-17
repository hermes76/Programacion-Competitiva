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
#define INF 1000000000000000
#define MOD 1000000007

vector<vll> graph(505,vll(505,INF));
void floyd(ll n)
{
    for(ll x=1; x<=n; x++)
        for(ll y=1; y<=n; y++)
            for(ll z=1; z<=n; z++)
                graph[y][z]=min(graph[y][z], graph[y][x]+graph[x][z]);

}
void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;

    for(ll x=0; x<m; x++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(graph[a][b]>c)
        {
            graph[a][b]=c;
            graph[b][a]=c;
        }
    }
    for(ll x=1; x<=n; x++)
        graph[x][x]=0;

    floyd(n);

    for(ll x=0; x<q; x++)
    {
        ll a,b;
        cin>>a>>b;
        if(graph[a][b]==INF)
            cout<<-1<<endl;
        else cout<<graph[a][b]<<endl;
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
