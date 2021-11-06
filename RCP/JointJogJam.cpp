
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
#define INF 1e9
#define MOD 1000000007

dll distance(dll a, dll b, dll c, dll d)
{
    double z1= a-c;
    double z2 = b-d;
    return sqrt(z1*z1 + z2*z2);
}
void solve()
{
    vector<dll> nums(8);
    for(ll x=0; x<8; x++)cin>>nums[x];

    dll ans=distance(nums[0],nums[1], nums[2], nums[3]);

    ans=max(ans, distance(nums[4], nums[5], nums[6], nums[7]));
    printf("%.8f\n",ans);

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
