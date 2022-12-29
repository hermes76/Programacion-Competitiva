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
    void remplace(ll position, ll new_value)
    {
        position += len;
        tree[position] = new_value;
        for (position /= 2; position >= 1; position /= 2)
        {
            tree[position] = tree[2*position]+tree[2*position+1];
        }
    }
};
vector<vll> tree;
vector<bool>visited;
vector<bool>visited_d;
pair<ll,ll> leaf(ll root)
{
    pair<ll,ll> res;
    pair<ll,ll>ans;
    ans={root,0};
    visited[root]=true;
    for(ll x: tree[root])
    {
        if(visited[x])
            continue;
        res=leaf(x);
        if(res.second+1>ans.second)
        {
            ans.second=res.second+1;
            ans.first=res.first;
        }
    }
    return ans;
}
pair<ll,ll> diameter(ll root)
{
    pair<ll,ll> res;
    pair<ll,ll>ans;
    ans={root,0};
    visited_d[root]=true;
   // cout<<root<<endl;
    for(ll x: tree[root])
    {
        if(visited_d[x])
            continue;
        res=diameter(x);
        if(res.second+1>ans.second)
        {
            ans.second=res.second+1;
            ans.first=res.first;
        }
    }
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    tree.resize(n+1);
    visited.resize(n+1,false);
    visited_d.resize(n+1,false);
    for(ll x=1; x<n; x++)
    {
        ll a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    pair<ll,ll> left=leaf(1);
    pair<ll,ll> ans= diameter(left.first);
    cout<<ans.second<<endl;
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