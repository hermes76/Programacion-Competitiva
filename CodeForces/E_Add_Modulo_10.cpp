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
void solve()
{
    ll n; cin>>n;
    vll nums(n);
    for(ll x=0; x<n; x++)
        cin>>nums[x];
    
    for(ll x=0; x<n; x++)
            nums[x]+=nums[x]%10;
    
    bool band=true;
    for(ll x=1; x<n; x++)
        if(nums[x]!=nums[x-1])
            band=false;
    
    if(band)
    {
        cout<<"Yes"<<endl;
        return;
    }
    for(ll x=0; x<n; x++)
    {
        if(nums[x]%10==0)
        {
            cout<<"No"<<endl;
            return;
        }
        while(nums[x]%10!= 2 && nums[x]%10!= 4 && nums[x]%10!=8 && nums[x]%10!= 6)
        {
            nums[x]+=nums[x]%10;
            cout<<nums[x]<<endl;
        }
    }  
    sort(all(nums));
    for(ll x=0; x<n-1; x++)
    {
        ll div=abs(nums[x]-nums[x+1]);
        div%=20;
        if(div==0)
            continue;
       if(nums[x]%10==2)
       {
            if(div!=6 && div!=14 && div!=2)
            {
                  cout<<"No"<<endl;
                return;
            }
       }
       else if(nums[x]%10==4)
       {
            if(div!=12 && div!=18 && div!= 4)
            {
                cout<<"No"<<endl;
                return;
            }
       }
       else if(nums[x]%10==8)
       {
            if(div!=14 && div!=16 && div!=8)
            {
                  cout<<"No"<<endl;
                return;
            }
       }
       else if(nums[x]%10==6)
       {
            if(div!=8 && div!=12 && div!=6)
            {
                cout<<"No"<<endl;
                return;
            }
       }

    }
    cout<<"Yes"<<endl;
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