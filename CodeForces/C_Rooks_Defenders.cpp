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
    ll n,q;
    cin>>n>>q;
    set<ll> rows;
    set<ll> columns;
    vll rows_c(n+1,0);
    vll columns_c(n+1,0);
    for(ll x=1; x<=n; x++)
    {
        rows.insert(x);
        columns.insert(x);
    }
    while(q--)
    {
        ll a;
        cin>>a;
        if(a==1)
        {
            ll b,c;
            cin>> b>>c;
            rows_c[b]++;
            columns_c[c]++;
            if(rows_c[b]==1){
            auto it= rows.lower_bound(b);
            rows.erase(it);
            }
            if(columns_c[c]==1)
            {
            auto et= columns.lower_bound(c);
            columns.erase(et);
            }
        }else if(a==2)
        {   
            ll b,c;
            cin>> b>> c;
            rows_c[b]--;
            columns_c[c]--;
            if(rows_c[b]==0)
            rows.insert(b);
            if(columns_c[c]==0)
            columns.insert(c);

        }else
        {
            ll b,c,d,e;
            cin>>b>>c>>d>>e;
            set<ll>:: iterator it = rows.lower_bound(b);
            set<ll> :: iterator et = columns.lower_bound(c);
            bool rows_cheked=true;
            bool columns_cheked=true;

            if(it!= rows.end() && *it <= d)
                rows_cheked= false;
            if(et!= columns.end() && *et <= e)
                columns_cheked= false;
            if(rows_cheked || columns_cheked)
                cout<<"Yes\n";
            else cout<<"No\n";
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