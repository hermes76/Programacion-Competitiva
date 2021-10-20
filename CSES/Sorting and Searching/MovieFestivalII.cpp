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

bool comp(pair<ll,ll>a, pair<ll,ll> b)
{
    return a.second<b.second;
}
void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<pair<ll,ll>> movies(n);

    for(ll x=0; x<n; x++)
    {
        ll a,b;
        cin>>a>>b;
        movies[x].first=a;
        movies[x].second=b;
    }

    sort(all(movies),comp);

    multiset<ll> end_times;
    for(ll x=0; x<k; x++)
        end_times.insert(0);
    ll ans=0;

    for(ll x=0; x<n; x++)
    {
        auto it= end_times.upper_bound(movies[x].first);

        if(it==end_times.begin())
            continue;

        end_times.erase(--it);
        end_times.insert(movies[x].second);
        ans++;
    }
    cout<<ans;
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
