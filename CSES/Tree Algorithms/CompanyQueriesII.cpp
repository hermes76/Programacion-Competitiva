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
void dfs(ll root, vector<vll> &graph, vector<pair<ll,ll>> & path, ll depth)
{
    path.push_back({root,depth});

    for(ll x: graph[root])
    {
        dfs(x,graph,path,depth+1);
        path.push_back({root,depth});
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vll> graph(n);
    vector<pair<ll,ll>> path;

    for(ll x=1; x<n; x++)
    {
        ll a;
        cin>>a;
        graph[a-1].push_back(x);
    }

    set<pair<ll,ll>> nodes;

    dfs(0,graph,path,1);


    for(ll x=0; x<path.size(); x++)
        nodes.insert({path[x].first,x});
    

    
    SegmentTree t(path.size());
    t.construct(path);


   
    while(m--)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        set<pair<ll,ll>>::iterator it= nodes.lower_bound({a,0});
        set<pair<ll,ll>>::iterator et= nodes.lower_bound({b,0});
    
        ll l,r;
        l=min(it->second,et->second);
        r=max(et->second, it->second);
        cout<<t.query(l,r).first+1<<"\n";
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