
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
void solve()
{
    ll n;
    cin>>n;
    map<ll,ll> counting;
    vector<ll> nums;
    vector<ll>ans;
    for(ll x=0; x<n; x++){
        ll a;
        cin>>a;
        counting[a]++;
    }
    for(auto x: counting)
        nums.push_back(x.second);

    sort(all(nums),greater<>());
    ans.push_back(n);
    nums[0]--;
    while(nums[0]>=1)
    {
        ans.push_back(ans[ans.size()-1]-1);
        nums[0]--;
    }
    ll x=1;
    for(; x<nums.size(); x++)
    {
        if(nums[x]==1)
            ans.push_back(ans[ans.size()-1]);
        else
        {
           while(nums[x]>1)
            {
                ans.push_back(ans[ans.size()-1]-1);
                nums[x]--;
            }
        }
    }
    for(x=ans.size(); x<n; x++)ans.push_back(ans[ans.size()-1]);
    reverse(all(ans));

    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    while(t--)
        solve();
}
