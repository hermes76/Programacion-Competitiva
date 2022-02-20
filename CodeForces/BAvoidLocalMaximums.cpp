
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

void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll x=0; x<n; x++)cin>>arr[x];

    ll ans=0;

    for(ll x=1; x<n-1; x++)
        if(arr[x]> arr[x-1] && arr[x]> arr[x+1])
        {
        ans++;
        if(x+2<n)
        arr[x+1]=max(arr[x],arr[x+2]);
        else arr[x+1]=arr[x];
        }

    cout<<ans<<endl;
    for(ll x=0; x<n; x++)
        cout<<arr[x]<<" ";
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    while(t--)
        solve();
}
