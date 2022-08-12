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
vector<bool> criba(1000001);
void precalc()
{   
    criba[1]=true;
    criba[0]=true;

    for(ll x=2; x*x<=1000000; x++)
    {
        if(criba[x]==true)
            continue;
        for(ll y=x*2; y<=1000000; y+=x)
            criba[y]=true;
    }
}
void solve()
{
    ll n,e; cin>>n>>e;
    vll nums(n);
    for(ll x=0; x<n; x++)
        cin>>nums[x];

   
    ll ans=0;
    for(ll x=n-1; x>=0; x--)
    {
        ll y=x-e;
        ll cont_l=0;
        ll cont_r=0;
        while(criba[nums[x]]==false && y>=0 && nums[y]==1)
        {
            cont_l++;
            y-=e;
        }
        y=x+e;
        while(criba[nums[x]]==false && y<=n-1 && nums[y]==1)
        {
            cont_r++;
            y+=e;
        }
        ans+= cont_l+ cont_r + cont_l*cont_r;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    precalc();
    t=1;
    cin>>t;
    for(ll x=0; x<t; x++)
        solve();
}