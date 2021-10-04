
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

vector <ll> participants;

void solve()
{
    ll n;
    cin>>n;
    participants.resize(n);
    ll gold=0,silver=0,bronce=0;
    for(ll x=0; x<n; x++)
        cin>>participants[x];

    ll x=1;
    gold++;
    while(participants[x-1]==participants[x])
    {
        gold++;
        x++;
    }
    while( x<n/2 && silver<=gold || participants[x-1]==participants[x])
    {
        silver++;
        x++;
    }
    while(x<=n/2 && participants[(n/2)]!=participants[x])
    {
        bronce++;
        x++;
    }
    if(bronce<=gold)
    {
        gold=0;
        silver=0;
        bronce=0;
    }
    cout<<gold<<" "<<silver<<" "<<bronce<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();

}

