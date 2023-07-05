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
    ll query(ll l, ll r)
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
vll ans;
vector<set<ll>> diferent;
vector<vll> graph;
vll color;
void dfs(ll v,ll p)
{
    diferent[v].insert(color[v]);
    for(auto i: graph[v])
    {
        if(i!=p)
        {
            dfs(i,v);
            if(diferent[v].size()<diferent[i].size())
                swap(diferent[v],diferent[i]);
            
            for(auto j : diferent[i])
                diferent[v].insert(j);
        }
    }
    ans[v]=diferent[v].size();
}
void solve()
{
    ll n;
    cin>>n;
    color.resize(n+1);
    for(ll i=1; i<=n; i++)
        cin>>color[i];
    
    graph.resize(n+1);
    for(ll i=0; i<n-1; i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ans.resize(n+1);
    diferent.resize(n+1);

    dfs(1,0);
    for(ll i=1; i<=n; i++)
        cout<<ans[i]<<' ';
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