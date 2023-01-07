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
ll cross(ll x1,ll y1, ll x2, ll y2)
{
    return x1*y2-x2*y1;
}
void solve()
{
    ll n;
    cin>>n;

    vector<pair<ll,ll>> polygon(n);

    for(ll x=0; x<n; x++)
    {
        ll a,b;
        cin>>a>>b;
        polygon[x]={a,b};
    }

    sort(all(polygon));

    vector<pair<ll,ll>> convexHullLeft,convexHullRight;
    //convexHullLeft.push_back(polygon[0]);
    //convexHullLeft.push_back(polygon[1]);

    for(ll x=0; x<n; x++){
        while(convexHullLeft.size()>=2)
        {
            ll x1,x2,y1,y2,x3,y3;
            x1= convexHullLeft[convexHullLeft.size()-2].first;
            y1= convexHullLeft[convexHullLeft.size()-2].second;
            x2= convexHullLeft[convexHullLeft.size()-1].first;
            y2= convexHullLeft[convexHullLeft.size()-1].second;
            x3= polygon[x].first;
            y3= polygon[x].second;

            if(cross(x3-x1,y3-y1, x3-x2,y3-y2)>0)
                convexHullLeft.pop_back();
            else break;
        }
        convexHullLeft.push_back(polygon[x]);
    }   
    for(ll x=n-1; x>=0; x--)
    {
        while(convexHullRight.size()>=2)
        {
            ll x1,x2,y1,y2,x3,y3;
            x1= convexHullRight[convexHullRight.size()-2].first;
            y1= convexHullRight[convexHullRight.size()-2].second;
            x2= convexHullRight[convexHullRight.size()-1].first;
            y2= convexHullRight[convexHullRight.size()-1].second;
            x3= polygon[x].first;
            y3= polygon[x].second;

            if(cross(x3-x1,y3-y1, x3-x2,y3-y2)>0)
                convexHullRight.pop_back();
            else break;
        }
        convexHullRight.push_back(polygon[x]);
    
    }
    cout<<convexHullLeft.size()+ convexHullRight.size()-2<<endl;
    for(ll x=0; x<convexHullLeft.size(); x++)
        cout<< convexHullLeft[x].first<<' '<< convexHullLeft[x].second<<endl;
    for(ll x=1; x<convexHullRight.size()-1; x++)
        cout<<convexHullRight[x].first<<' '<<convexHullRight[x].second<<endl;
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