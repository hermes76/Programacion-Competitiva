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
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(k): Kth element in a Set (counting from zero).
*/
 
//typedefs
typedef long long ll;
typedef double dll;
typedef vector<ll> vll;
 
//defines
#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 10000000000
#define MOD 1000000007
struct SegmentTree
{
    vector<pair<ll,ll>> tree;
    ll len;
     SegmentTree()
    {
        len=0;
    }
    SegmentTree(ll size_)
    {
        len=1;
        for(; len<size_; len<<=1);
        tree.resize(2*len,{INF,INF});
 
    }
    void construct(vector<pair<ll,ll>> &nums)
    {
        for(ll x=0; x<nums.size(); x++)
            tree[x+len]=nums[x];
        for(ll x=len-1; x>=1; x--)
            if(tree[2*x].second<tree[2*x+1].second)
                tree[x]=tree[2*x];
            else 
                tree[x]=tree[2*x+1];
    }
    pair<ll,ll> minimum(pair<ll,ll> a, pair<ll,ll> b)
    {
        if(a.second<b.second)
            return a;
        return b;
    }
    pair<ll,ll> query(ll l, ll r)
    {
        l += len; r += len;
        pair<ll,ll> s = {INF,INF};
        while (l <= r)
        {
            if (l%2 == 1) s =minimum(s,tree[l++]);
            if (r%2 == 0) s = minimum(s,tree[r--]);
            l /= 2; r /= 2;
        }
    return s;
    }
};
void dfs(ll root, vector<vll> &tree, vector<pair<ll,ll>> & path, ll depth, vll &visited)
{
    if(visited[root]==1)
        return;
    visited[root]=1;
    path.push_back({root,depth});
 
    for(ll x: tree[root])
    {
        dfs(x,tree,path,depth+1,visited);
        path.push_back({root,depth});
    }
}
void distances(ll root, vector<vll> &tree, ll depth, vll & visited, vll &d)
{
    if(visited[root]==0)
        return;
    visited[root]=0;
    d[root]=depth;
 
    for(ll x: tree[root])
        distances(x,tree,depth+1,visited,d);
}
void solve()
{
    ll n,m;
    cin>>n>>m;
 
    vector<vll> tree(n);
    vector<pair<ll,ll>> path;
    vll d(n,0);
    vll visited(n,0);
    vll find_node(n,INF);
 
    for(ll x=0; x<n-1; x++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    dfs(0,tree,path,1,visited);
    distances(0,tree,1,visited,d);

    set<pair<ll,ll>> nodes;
 
 
 
    for(ll x=0; x<path.size(); x++)
        if(find_node[path[x].first]==INF)
            find_node[path[x].first]=x;
    
    SegmentTree t(path.size());
    t.construct(path);
 
    while(m--)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        
        ll l,r;

        l=min(find_node[a],find_node[b]);
        r=max(find_node[a],find_node[b]);
        
        ll ans=d[a]+d[b]-(2*d[t.query(l,r).first]);
        cout<<ans<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    for(ll x=0; x<t; x++)
        solve();
}