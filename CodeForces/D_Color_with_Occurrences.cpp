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
bool possible(string cad, string comp,ll start)
{
    bool band=true;
    if(start+comp.length()>cad.length())
        band=false;
    else{
        for(ll x=0; x<comp.length(); x++)
            if(cad[x+start]!=comp[x])
            {
                band=false;
                break;
            }
    }
    return band;
}
void solve()
{
    string cad;
    ll m;
    ll n;

    cin>>cad;
    cin>> m;
    n=cad.length();

    vector<string> cads(m);

    vll dp(n+1,INF);
    dp[n]=0;

    vector<vector<pair<ll,ll>>> steps(n+1);
    steps[n].push_back({0,0});
    for(ll x=0; x<m; x++)
        cin>>cads[x];
    
    for(ll x=n-1; x>=0; x--)
    {
        vector<pair<ll,ll>> aux;
        for(ll y=0; y<m; y++)
        {
            if(possible(cad,cads[y],x))
            {
                for(ll z=1; z<=cads[y].length(); z++)
                {
                    if(dp[x]>dp[x+z])
                    {
                        dp[x]=dp[x+z]+1;
                        aux=steps[x+z];
                        aux.push_back({y+1,x+1});
                    }
                }
            }
        }
        steps[x]=aux;
    }

    if(dp[0]==INF)
        dp[0]=-1;
    cout<<dp[0]<<endl;
    if(dp[0]!=-1)
    {
        for(ll x=0; x<steps[0].size(); x++)
        {
            if(steps[0][x].first!=0)
            cout<<steps[0][x].first<<' '<<steps[0][x].second<<endl;
        }
    }
    
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