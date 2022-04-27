
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
        tree.resize(2*len,{0,-INF});

    }
    void construct(vector<ll> &nums)
    {
        for(ll x=0; x<nums.size(); x++)
        {
            tree[x+len].first=nums[x];
            tree[x+len].second= nums[x];
        }
        for(ll x=len-1; x>=1; x--)
        {
            tree[x].first= tree[2*x].first+tree[2*x+1].first;
            tree[x].second = max(tree[2*x].second, tree[2*x].first+tree[2*x+1].second);
        }
    }
    ll query(ll l, ll r)
    {
        l += len; r += len;
        pair<ll,ll>a={0,0};
        pair<ll,ll>b={0,0};
        while (l <= r)
        {

            if (l%2 == 1)
            {
                a.second= max(a.second, a.first+tree[l].second);
                a.first+=tree[l].first;
                l++;
            }
            if (r%2 == 0)
            {
               b.second= max(tree[r].second, tree[r].first + b.second);
               b.first= tree[r].first+b.first;
                r--;
            }
            l /= 2; r /= 2;
        }
        return max((ll)0,max(a.second, a.first+b.second));
    }

    void add(ll position, ll increment)
    {
        position += len;
        tree[position].first = increment;
        tree[position].second= increment;
        for (position /= 2; position >= 1; position /= 2)
        {
            tree[position].first = tree[2*position].first+tree[2*position+1].first;
            tree[position].second = max(tree[2*position].second, tree[2*position].first+tree[2*position+1].second);
        }
    }
};
void solve()
{
   ll n,m;
   cin>>n>>m;
   vector<ll> nums(n);
   for(ll x=0; x<n; x++)cin>>nums[x];

   SegmentTree t(nums.size());

   t.construct(nums);

   while(m--)
   {
       ll a,b,c;
       cin>>a>>b>>c;
       if(a==1)
            t.add(b-1,c);
        else cout<<t.query(b-1,c-1)<<endl;
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
