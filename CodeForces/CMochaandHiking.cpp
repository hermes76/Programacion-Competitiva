
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

void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];

    if(arr[n-1]==0)
    {
        for(ll x=1; x<=n+1; x++)
            cout<<x<<" ";
    }else if(arr[0]==1){
        cout<<n+1<<" ";
        for(ll x=1; x<=n; x++)
            cout<<x<<" ";
    }else
    {
        for(ll x=1; x<n; x++)
        {
            if(arr[x-1]==0 && arr[x]==1)
            {
                for(ll y=0; y<x; y++)
                {
                    cout<<y+1<<" ";
                }
                cout<<n+1<<" ";
                for(ll y=x+1; y<=n; y++)
                {
                    cout<<y<<" ";
                }
                cout<<endl;
                return;
            }
        }
        cout<<-1;
    }
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
