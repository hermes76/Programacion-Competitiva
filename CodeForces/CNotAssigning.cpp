
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
struct SegmentTree
{
    vector<ll> tree;
    ll len;
     SegmentTree()
    {
        len=0;
    }
    SegmentTree(ll size_)
    {
        len=1;
        for(; len<size_; len<<=1);
        tree.resize(2*len,0);

    }
    void construct(vector<ll> &nums)
    {
        for(ll x=0; x<nums.size(); x++)
            tree[x+len]=nums[x];
        for(ll x=len-1; x>=1; x--)
            tree[x]= tree[2*x]+tree[2*x+1];
    }
    ll sum(ll l, ll r)
    {
        l += len; r += len;
        ll s = 0;
        while (l <= r)
        {
            if (l%2 == 1) s += tree[l++];
            if (r%2 == 0) s += tree[r--];
            l /= 2; r /= 2;
        }
        return s;
    }

    void add(ll position, ll increment)
    {
        position += len;
        tree[position] += increment;
        for (position /= 2; position >= 1; position /= 2)
        {
            tree[position] = tree[2*position]+tree[2*position+1];
        }
    }
};
void bfs(ll node, ll color, vector<vector<ll>> &graph,map<pair<ll,ll>,ll> &prime)
{
    for(ll x=0; x<graph[node].size(); x++)
    {
        if(prime[{node, graph[node][x]}] ==0)
            {
                prime[{node, graph[node][x]}] = color;
                prime[{graph[node][x],node}] = color;
                if(color==2)
                bfs(graph[node][x],3, graph, prime);
                else if(color==3)
                bfs(graph[node][x],2, graph, prime);
            }

    }
}
void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> graph(n+5);
    vector<pair<ll,ll>> input_order;
    map<pair<ll,ll> ,ll> prime;
    vector<ll> weight(n+5,0);
    for(ll x=0; x<n-1; x++)
    {
        ll u,v;
        cin>>u>>v;
        input_order.push_back({u,v});
        graph[u].push_back(v);
        graph[v].push_back(u);

        weight[u]++;
        weight[v]++;

    }

    for(ll x=1; x<=n; x++)
        if(weight[x]>=3)
        {
            cout<<-1<<endl;
            return;
        }
    ll start=0, ending=0;

    for(ll x=1; x<=n; x++)
    {
        if(weight[x]==1 && start==0)
            start=x;
        else if(weight[x]==1 && start==1)
            ending=x;
    }
    bfs(start, 2, graph,prime);
    bfs(ending,2, graph, prime);

    for(auto x: input_order)
    {
        cout<<prime[x]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    while(t--)
        solve();
}
