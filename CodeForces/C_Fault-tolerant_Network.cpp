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
ll n;
vll a,b;
ll two_wires()
{
    ll ans=abs(a[0]-b[0])+ abs(a[n-1]- b[n-1]);
    ll res= abs(a[0]-b[n-1])+ abs(a[n-1]- b[0]);
    return min(ans,res);
}
ll minimum_line(vll &elements, ll k)
{
    ll ans=INF;
    for(ll x=0; x<n; x++)
        ans= min(ans, abs(elements[x]-k));
    return ans;
}
ll four_wires()
{
    vll e(4);
    e[0]= minimum_line(b,a[0]);
    e[1] = minimum_line(b,a[n-1]);
    e[2] = minimum_line(a,b[0]);
    e[3] = minimum_line(a,b[n-1]);
    return e[0]+e[1]+e[2]+e[3];
}
ll three_wires()
{
     vll e(4);
    e[0]= minimum_line(b,a[0]);
    e[1] = minimum_line(b,a[n-1]);
    e[2] = minimum_line(a,b[0]);
    e[3] = minimum_line(a,b[n-1]);
    ll total= e[0]+e[1]+e[2]+e[3];
    ll ans=INF;
    ans=min(ans,total-e[0]-e[2] + abs(a[0]-b[0]));
    ans=min(ans,total-e[0]-e[3] + abs(a[0]-b[n-1]));

    ans=min(ans,total-e[1]-e[2] + abs(a[n-1]-b[0]));
    ans=min(ans,total-e[1]-e[3] + abs(a[n-1]-b[n-1]));

    return ans;
}
void solve()
{
    cin>>n;
    a.clear();
    b.clear();
    a.resize(n);
    b.resize(n);
    for(ll x=0; x<n; x++)
        cin>> a[x];
    for(ll x=0; x<n; x++)
        cin>> b[x];
    
    ll two,three,four;
    two= two_wires();
    three= three_wires();
    four=four_wires();
    cout<< min(min(two, three), four)<<endl;
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