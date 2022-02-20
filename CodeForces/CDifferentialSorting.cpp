
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

     for(ll x=0; x<n; x++)
     {
         cin>>arr[x];
     }
     if(arr[n-2]>arr[n-1])
        cout<<-1<<endl;
     else if(is_sorted(all(arr)))
        cout<<0<<endl;
     else if(arr[n-1]>=0)
     {
        cout<<n-2<<endl;
        for(ll x=0; x<n-2; x++)
            cout<<x+1<<" "<<n-1<<" "<<n<<endl;
     }else cout<<-1<<endl;
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
