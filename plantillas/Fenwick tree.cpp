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

struct FenwickTree{
    vector <ll> tree;
    FenwickTree(ll len)
        {
            tree.resize(len);
        }
     FenwickTree(vector<ll>&nums)
        {
            tree.resize(nums.size()+1);
                for(ll x=1; x<tree.size(); x++)
                    add(x,nums[x-1]);
        }
    void add(ll k,ll x)
        {
           while (k <= tree.size())
            {
                tree[k] += x;
                k += k&-k;
            }
        }
    ll sum(ll k)
    {
       ll s =0;
        while (k >= 1) {
            s += tree[k];
            k -= k&-k;
        }
        return s;
    }
    ll range_sum(ll l, ll r)
    {
        return  sum(r)-sum(l-1);
    }
};
void solve()
{
    vector<ll> nums(8);
    nums= {1,4,4,16,6,7,4,29};
    FenwickTree t(nums);
    cout<<t.range_sum(2,5);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}
