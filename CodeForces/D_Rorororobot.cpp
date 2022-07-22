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
            tree[x]= max(tree[2*x],tree[2*x+1]);
    }
    ll query(ll l, ll r)
    {
        l += len; r += len;
        ll s = 0;
        while (l <= r)
        {
            if (l%2 == 1) s = max(s,tree[l++]);
            if (r%2 == 0) s = max(s, tree[r--]);
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
    vll nums(m);
    for(ll x=0; x<m; x++)
        cin>>nums[x];
    
    SegmentTree t(m);
    t.construct(nums);
    
    ll q;
    cin>>q;
    while(q--)
    {
        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll max_r, min_r, max_c, min_c;
        max_r= max(c,a);
        min_r= min(c,a);
        max_c=max(b,d);
        min_c=min(b,d);
      //  cout<<max_r-min_r<<' '<< max_c-min_c<< endl;
        if((max_r-min_r)%k!=0 || (max_c-min_c)%k !=0)
        cout<<"NO"<<endl;
        else{
            ll maximum_level = (n-max_r)%k;
            maximum_level=n-maximum_level;
            if(t.query(min_c-1,max_c-1)>= maximum_level){
                cout<<"NO";
            }else
            cout<<"YES";
            cout<<endl;
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
    for(ll x=0; x<t; x++)
        solve();
}