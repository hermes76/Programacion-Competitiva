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

vector <ll> vll;

ll solve()
{
    ll n,m;
    cin>>n>>m;
    vll.resize(n);
    ll ans=0;
    for(ll x=0; x<n; x++)
        cin>>vll[x];

    sort(all(vll),greater<>());
    ll weapons= vll[0]+vll[1];

    ans=(m/weapons)+1;
    m-=ans*weapons;
    ans*=2;
    if(m+weapons<=0)
        ans-=2;
    else if(m+vll[1]<=0)
        ans--;
    return ans;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}
