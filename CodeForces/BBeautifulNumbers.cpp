
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

vector <pair<ll,ll>> vll;

string solve()
{
    ll n;
    cin>>n;
    vll.resize(n);
    ll l,r;
    string ans;
    for(ll x=0; x<n; x++)
    {
        cin>>vll[x].first;
        vll[x].second=x;
    }
    sort(all(vll));

        l=vll[0].second;
        r=vll[0].second;
    for(ll x=0; x<n; x++)
    {
        l=min(l,vll[x].second);
        r=max(r,vll[x].second);
        if(r-l +1 == vll[x].first && vll[x].second>=l && vll[x].second<=r)
            ans+='1';
        else ans+='0';
    }
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

