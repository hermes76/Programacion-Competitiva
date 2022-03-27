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
ll query(ll a,ll b,ll c, ll d, vector<vector<ll>> & forest)
{

   return forest[c][d] - forest[c][b-1] - forest[a-1][d] + forest[a-1][b-1];
}
void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<string> grid(n);
    vector<vector<ll>> forest(n+1, vector<ll>(n+1,0));
    for(ll x=0; x<n; x++)cin>>grid[x];

    for(ll x=1; x<=n; x++)
    {
        for(ll y=1; y<=n; y++)
            if(grid[x-1][y-1]=='*')
                forest[x][y]++;
        for(ll y=1; y<=n; y++)
            forest[x][y]+=forest[x][y-1];
        for(ll y=n; y>=0; y--)
            forest[x][y]+= forest[x-1][y];
    }

    for(ll x=0; x<m; x++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<query(a,b,c,d,forest)<<endl;
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
