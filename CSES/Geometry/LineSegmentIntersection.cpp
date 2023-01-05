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
struct line{
    ll x1,x2,y1,y2;
};
ll cross(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2- x2*y1;
}

ll make_line(line i, ll x1, ll y1)
{
    return cross(x1-i.x1, y1-i.y1, x1-i.x2 , y1-i.y2);
}
bool inside(line a, line b)
{
    double minx,maxx,miny,maxy;
    minx=min(a.x1,a.x2);
    maxx=max(a.x1,a.x2);
    miny = min(a.y1,a.y2);
    maxy = max(a.y1,a.y2);
    if(minx<= b.x1 && miny <= b.y1 && maxx>= b.x1 && maxy>= b.y1)
        return true;
    else if(minx<= b.x2 && miny <= b.y2 && maxx>= b.x2 && maxy>= b.y2)
        return true;
    return false;
}
void solve()
{
    line a,b;
    cin>>a.x1>>a.y1>>a.x2>>a.y2>>b.x1>>b.y1>>b.x2>>b.y2;

    line ca,cb;
    ca.x1=b.x1;
    ca.y1=b.y1;
    ca.x2=a.x1;
    ca.y2=a.y1;

    cb.x1=b.x1;
    cb.y1=b.y1;
    cb.x2=a.x2;
    cb.y2=a.y2;

    ll cA,cB,aBC,aBD;   

    cA= make_line(ca,b.x2,b.y2);
    cB=make_line(cb,b.x2,b.y2);
    aBC=make_line(a,b.x1,b.y1);
    aBD=make_line(a,b.x2,b.y2);

    if((cA>=0 && cB<=0) || (cA<=0 && cB >=0))
    {
        if((aBC>=0 && aBD<=0) || (aBC<=0 && aBD >=0))
        {
            if(cA==0 && cB ==0 && aBC==0 && aBD==0)
            {
                if(inside(a,b)|| inside(b,a))
                cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else
            cout<<"YES"<<endl;
        }else
            cout<<"NO"<<endl;
    }
    else
        cout<<"NO"<<endl;

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