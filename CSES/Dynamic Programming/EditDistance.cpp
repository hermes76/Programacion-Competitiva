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

string cad1,cad2;
vector<vll> dp(5005, vll(5005,-1));
ll cost(ll a,ll b)
{
    if(cad1[a]==cad2[b])return 0;
    return 1;
}
ll min_path(ll a,ll b)
{
    if(a<=-1 || b<=-1)
        return abs(a-b);

    if(dp[a][b]!=-1)return dp[a][b];

    ll best=min(min_path(a-1,b)+1,min( min_path(a,b-1)+1,min_path(a-1,b-1)+cost(a,b)));
      dp[a][b]=best;
    return dp[a][b];
}
void solve()
{
    cin>>cad1>>cad2;
    cout<<min_path(cad1.length()-1, cad2.length()-1);

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

