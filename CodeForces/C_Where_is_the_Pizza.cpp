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
struct  DSU
{
    ll len;
    vll parent;
    vll size;
    DSU(ll len_)
    {
        len= len_;
        parent.resize(len);
        for(ll x=0; x<len; x++)parent[x]=x;
        size.resize(len,1);
    }

    void make_set(ll v) 
    {
        parent[v] = v;
    }

   int find_set(ll v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
         }
    }
    ll size_of_set(ll a)
    {
        return size[find_set(a)];
    }
};
void solve()
{
    ll n;
    cin>>n;
    vll a(n),b(n),c(n);

    for(ll x=0; x<n; x++)
        cin>>a[x];
     for(ll x=0; x<n; x++)
        cin>>b[x];
     for(ll x=0; x<n; x++)
        cin>>c[x];

    DSU union_set(n+1);

    for(ll x=0; x<n; x++)
        union_set.union_sets(a[x],b[x]);
    
    set<ll> parent;
    for(ll x=1; x<=n; x++)
        parent.insert(union_set.find_set(x));
    for(ll x=0; x<n; x++)
    {
        if(c[x]!=0)
        {
            ll aux= union_set.find_set(c[x]);
            auto it = parent.lower_bound(aux);
            if(it != parent.end() && *it == aux)
                parent.erase(it);
        }
    }
    ll cycles=0;
    for(auto x : parent)
        if(union_set.size_of_set(x)>1)
            cycles++;

    ll ans=1;
    for(ll x=0; x<cycles; x++)
    {
        ans*=2;
        ans%=MOD;
    }
    cout<<ans<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    for(ll x=0; x<t; x++)
        solve();
}