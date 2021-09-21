
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

string solve()
{
    ll arr[3];
    ll m;
    ll minimo=0, maximo=0;
    for(ll x=0; x<3; x++)
        cin>>arr[x];
    cin>>m;
    for(ll x=0; x<3; x++)
        if(arr[x]>0)
            maximo+=arr[x]-1;
    sort(arr,arr+3, greater<>());

    minimo=(arr[0]-arr[1]);
    minimo=(minimo-arr[2]);
    if(minimo>0)
        minimo--;
    else minimo=0;
    if(minimo<=m && maximo>=m)
        return "YES";
    return "NO";
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

