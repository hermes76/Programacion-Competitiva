
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
vector <ll> sorted;

string solve()
{
    ll n,m;
    cin>>n>>m;

    vll.resize(n);
    sorted.resize(n);

    for(ll x=0; x<n; x++){cin>>vll[x]; sorted[x]=vll[x];}

    if(m<=n/2)
        return "YES";
    sort(all(sorted));
    if(m>=n)
    {
        for(ll x=0; x<n; x++)
         if(sorted[x]!=vll[x])
        return "NO";
    return "YES";
    }
    for(ll x=n-m; x<m; x++)
        if(sorted[x]!=vll[x])
        return "NO";
    return "YES";
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

