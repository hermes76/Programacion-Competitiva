//libraries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using namespace __gnu_pbds;
using namespace std;

//templates

template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(k): Kth element in a Set (counting from zero).


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
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> nums(n);
    
    for(ll x=0; x<n; x++)
    {
        ll a;
        cin>>a;
        nums[x] = {a,x};
    }

    sort(all(nums));
    ll wins=0;

    ordered_set<pair<ll,ll>> winners;

    ll index=0;
    for(index; index<n; index++)
    {
        if(m-nums[index].first>=0)
            wins++;
        else break;
        m-=nums[index].first;
        winners.insert({nums[index].second, nums[index].second});
    }

    if(wins==0)
    {
        cout<<n+1<<endl;
        return;
    }


    for(ll x=index; x<n; x++)
        winners.insert({nums[x].second+1, nums[x].second});

    winners.insert({wins,-1});
    ll ans=0;

    ll l=winners.order_of_key({wins,INF});
    ll distance;
    ans=winners.size()-l+1;

    for(ll x=index; x<n; x++)
    {
        m+=nums[x-1].first;
        if(m-nums[x].first>=0)
        {
            m-=nums[x].first;
            winners.erase(winners.find({nums[x-1].second, nums[x-1].second}));
            winners.insert({nums[x-1].second+1, nums[x-1].second});
            winners.erase(winners.find({nums[x].second+1, nums[x].second}));
            winners.insert({nums[x].second, nums[x].second});
            l= winners.order_of_key({wins,INF});
            distance= winners.size()-l+1;
            ans=min(ans,distance);
        }
        else break;
    }
    //for(auto x: winners)
     //   cout<<x.first<<' '<<x.second<<endl;
    //cout<<endl;
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