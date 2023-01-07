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
#define INF 1000000000
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
struct point
{
    ll x,y;
};
struct line{
    point a,b;
};
ll cross(point a,point b)
{
    return (a.x*b.y) - (b.x* a.y);
}
ll direction(line ab, point p)
{
    point f,g;
    f.x= p.x-ab.a.x;
    f.y= p.y-ab.a.y;
    g.x= p.x-ab.b.x;
    g.y= p.y-ab.b.y;
    return cross(f,g);
}
bool boundary(line ab, point p)
{
    ll maxx=max(ab.a.x,ab.b.x);
    ll maxy= max(ab.a.y, ab.b.y);
    ll minx=min(ab.a.x, ab.b.x);
    ll miny= min(ab.a.y, ab.b.y);

    if(direction(ab,p)==0 && minx<= p.x && miny<=p.y && maxx>= p.x && maxy>=p.y)
        return true;
    return false;
}
ll intersect(line ab, line pq)
{
    line pa,pb;
    ll ca,cb,abc,abd;

    pa.a.x= pq.a.x;
    pa.a.y= pq.a.y;
    pa.b.x= ab.a.x;
    pa.b.y= ab.a.y;

    pb.a.x= pq.a.x;
    pb.a.y= pq.a.y;
    pb.b.x= ab.b.x;
    pb.b.y= ab.b.y;

    ca=direction(pa,pq.b);
    cb=direction(pb,pq.b);

    abc=direction(ab,pq.a);
    abd=direction(ab,pq.b);

    if(boundary(ab,pq.a))
        return -1;
    if(((ca<0)!=(cb<0)) && ((abc<0) !=(abd<0)))
        return 1;
    return 0;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<point> polygon(n);
    for(ll x=0; x<n; x++)
    {
        ll a,b;
        cin>>a>>b;
        polygon[x].x=a;
        polygon[x].y=b;
    }

    vector<point> points(m);

    for(ll x=0; x<m; x++)
    {
        ll a,b;
        cin>>a>>b;
        points[x].x=a;
        points[x].y=b;
    }
    ll count=0;

    for(ll x=0; x<m; x++)
    {
        point uper;
        line aux;
        line pq;
        bool ok=true;

        uper.x=INF;
        uper.y= points[x].y;
        
        pq.a = points[x];
        pq.b = uper;

        aux.a= polygon[n-1];
        aux.b= polygon[0];
        count=0;

        ll col = intersect(aux,pq);

        if(col==-1)
            ok=false;
        count+=col;
        for(ll y=1; y<n && ok; y++)
        {
            aux.a= polygon[y-1];
            aux.b= polygon[y];


            col=intersect(aux, pq);
            if(col==-1)
                ok=false;
                
            count+=col;
        }
        if(ok)
        {
            if(count%2==1)
                cout<<"INSIDE"<<endl;
            else 
                cout<<"OUTSIDE"<<endl;
        }else
            cout<<"BOUNDARY"<<endl;
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