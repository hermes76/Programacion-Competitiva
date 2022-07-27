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
void convert(ll k)
{
    cout<<k<<' ';
    for(ll x=30; x>=0; x--)
    {
        if(k&(1<<x))
            cout<<1;
        else
        cout<<0;
    }cout<<endl;
}
void solve()
{
     ll n, m;
     cin>>n>>m;
     ll a,b;
     a=0; b=n-1;
     vll nums(n);
     for(ll x=0; x<n; x++)
        nums[x]=x;
    
    ll index_a=1;
    for(ll x=n-2; x>=0; x--)
    {
        if(m>=(nums[n-1]& nums[x]))
        {
            m-= (nums[n-1]& nums[x]);
            swap(nums[n-1], nums[index_a]);
            break;
        }
        index_a++;
    }
    if(m==1 && n>4)
    {
        if(m==(nums[n/2-1]&nums[n/2+1]))
        {
            swap(nums[n/2],nums[n/2+1]);
            m--;
        }
    }
    if(m!=0)
    {
        cout<<-1<<endl;
        return;
    }
    while(a<b)
    {
        cout<<nums[a]<<' '<<nums[b]<<endl;
        a++;
        b--;
    }

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