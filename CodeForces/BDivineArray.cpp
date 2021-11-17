
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

vll make(vll nums,ll n)
{
    vll counting(n+2,0);
    for(ll x=0; x<n; x++)
        counting[nums[x]]++;
    for(ll x=0; x<n; x++)
        nums[x]=counting[nums[x]];
    return nums;
}
void solve()
{
    ll n,q;
    cin>>n;
    vll nums(n);
    for(ll x=0; x<n; x++)cin>>nums[x];
    cin>>q;

    ll cont=0;
    vector<vll> all;
    all.push_back(nums);
    vll save;
    do
    {
        save=make(all[cont],n);
        if(save==all[cont])break;
        all.push_back(save);
        cont++;
    }while(1);
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        if(b>=all.size())
            cout<<all[all.size()-1][a]<<endl;
        else
            cout<<all[b][a]<<endl;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    //t=1;
    cin>>t;
    while(t--)
        solve();
}
