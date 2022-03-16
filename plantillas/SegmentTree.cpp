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
    SegmentTree(vector<ll> &nums)
    {
        len=1;
        for(len; (len<<1)<=nums.size(); len<<=1);
        tree.resize(2*len,0);

        for(ll x=len; x<2*len; x++)
            tree[x]=nums[x-len];
        for(ll x=len-1; x>=1; x--)
            tree[x]= tree[2*x]+tree[2*x+1];

    }
    ll sum(ll a, ll b)
    {
        a += len; b += len;
        ll s = 0;
        while (a <= b)
        {
            if (a%2 == 1) s += tree[a++];
            if (b%2 == 0) s += tree[b--];
            a /= 2; b /= 2;

        }
        return s;
    }

    void add(ll k, ll x)
    {
        k += len;
        tree[k] += x;
        for (k /= 2; k >= 1; k /= 2)
        {
            tree[k] = tree[2*k]+tree[2*k+1];
        }
    }
};
void solve()
{
    vector<ll> nums(8);
    nums = {5,8,6,3,2,7,2,6};

    SegmentTree t(nums);

   cout<<t.sum(0,7);
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
