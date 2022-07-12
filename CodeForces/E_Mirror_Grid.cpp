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
ll check(vector<string> & grid, ll n, ll x, ll y)
{
    ll count=0;
    if(grid[x][y]=='1')
        count++;
    if(grid[y][n-x-1]=='1')
        count++;
    if(grid[n-x-1][n-y-1]=='1')
        count++;
    if(grid[n-y-1][x]=='1')
        count++;
    return count;
}
void setter(vector<string> & grid, ll n, ll x, ll y)
{
    grid[x][y]='1';
    grid[y][n-x-1]='1';
    grid[n-x-1][n-y-1]='1';
    grid[n-y-1][x]='1';
}
void clear(vector<string> & grid, ll n, ll x, ll y)
{
     grid[x][y]='0';
    grid[y][n-x-1]='0';
    grid[n-x-1][n-y-1]='0';
    grid[n-y-1][x]='0';
}
void print(vector<string> & grid, ll n, ll x, ll y)
{
    cout<<"A"<<endl;
    cout<<x<< " "<<y<<endl;
    cout<<y<<" "<<n-x-1<<endl;
    cout<<n-x-1<<" "<<n-y-1<<endl;
    cout<<n-y-1<<" "<<x<<endl;
}
void solve()
{
    ll n;
    cin>>n;
    vector<string> grid(n);

    for(ll x=0; x<n; x++)
            cin>>grid[x];
    
    ll res=0;
    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<n; y++)
        {
           
            ll r=check(grid,n,x,y);
            if(r>=2)
            {
                setter(grid,n,x,y);
                res+=4-r;
            }
            else{
                clear(grid,n,x,y);
                res+=r;
            }
             //cout<<x<<" "<<y<<" "<<r<<endl;
        }

    }
    cout<<res<<endl;
    /*for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<n; y++)
        print(grid,n,x,y);
    }*/

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