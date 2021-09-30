
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
    ll original[n];
    ll cuenta=0;
    vector<tuple<ll,ll,ll>> res;
    for(ll x=0; x<n; x++)cin>>arr[x];
    for(ll x=0; x<n; x++)original[x]=arr[x];
    sort(original,original+n);
    for(ll x=0; x<n; x++)
    {
        if(arr[x]==original[x])
            continue;
        for(ll y=x+1; y<n; y++)
        {
            if(arr[y]==original[x])
            {
                cuenta++;
               // cout<<x+1<<" "<<y+1<<" "<<(y-x)+1<<endl;
               res.push_back({x+1,y+1,(y-x)});
               vector<ll> aux;
               aux.push_back(arr[y]);
               for(ll z=x; z<=y-1; z++)
               {
                    aux.push_back(arr[z]);
               }
                ll contador=x;
                for(auto z: aux)
                {
                    arr[contador]=z;
                    contador++;
                }
                break;
            }

        }
    }
    cout<<cuenta<<endl;
   for(ll x=0; x<cuenta; x++)
    {
        cout<<get<0>(res[x])<<" "<<get<1>(res[x])<<" "<<get<2>(res[x])<<endl;
    }
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

