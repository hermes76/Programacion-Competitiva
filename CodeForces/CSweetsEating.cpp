

#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;*/

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double dll;

vector <ll> sweet;

void solve()
{
    ll n, m;
    cin>>n>>m;
    sweet.resize(n);
    vector<ll> previous(m,0);

    ll ans=0;
    for(ll x=0; x<n; x++)
        cin>>sweet[x];

    sort(all(sweet));

    for(ll x=0; x<n; x++)
    {
        ans+=sweet[x]+previous[x%m];
        previous[x%m]+=sweet[x];
        cout<<ans<<" ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
