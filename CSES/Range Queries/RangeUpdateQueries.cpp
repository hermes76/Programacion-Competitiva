
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
     void update(ll l, ll r, ll c)
    {
         l += len; r += len;
        while (l <= r)
        {
            if (l%2 == 1)
            {
                tree[l]+=c;
                l++;
            }
            if (r%2 == 0)
            {
                tree[r]+=c;
                r--;
            }
            l /= 2; r /= 2;
        }
    }
    ll k_position(ll position)
    {
        position += len;
        ll res=tree[position];
        for (position /= 2; position >= 1; position /= 2)
        {
            res+= tree[position];
        }


        return res;
    }
};
void solve()
{
    ll n,q;
    cin>>n>>q;

    vector<ll> arr(n);
    for(ll x=0; x<n; x++)cin>>arr[x];

    SegmentTree t(arr.size());
    for(ll x=0; x<arr.size(); x++)
            t.tree[x+t.len]=arr[x];
    while(q--)
    {
        ll option;
        cin>>option;
        if(option==1)
        {
            ll a,b,c;

            cin>>a>>b>>c;
            t.update(a-1,b-1,c);
        }else{
            ll a;
            cin>>a;
            cout<<t.k_position(a-1)<<endl;
        }

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
