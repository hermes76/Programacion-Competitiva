
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
    ll sx,sy;
    cin>>n>>sx>>sy;
    pair<ll,ll> arr[n];
    for(ll x=0; x<n; x++)
        cin>>arr[x].first>>arr[x].second;

    //arriba,derecha,abajo,izquierda
    ll dir[4]={0,0,0,0};
    pair<ll,ll> shawarma[4]={{sx,sy+1},{sx+1,sy},{sx,sy-1},{sx-1,sy}};
    pair<ll,ll> res;
    ll maximo=0;
       for(ll y=0; y<n; y++)
       {
           if(arr[y].second>=shawarma[0].second)
           {
               dir[0]++;
           }
       }
        for(ll y=0; y<n; y++)
       {
           if(arr[y].first>=shawarma[1].first)
           {
               dir[1]++;
           }
       }
        for(ll y=0; y<n; y++)
       {
           if(arr[y].second<=shawarma[2].second)
           {
               dir[2]++;
           }
       } for(ll y=0; y<n; y++)
       {
           if(arr[y].first<=shawarma[3].first)
           {
               dir[3]++;
           }
       }
       for(ll x=0; x<4; x++)
       {
           if(dir[x]>maximo && shawarma[x].second>=0 && shawarma[x].second<=1000000000 && shawarma[x].first>=0 && shawarma[x].first<=1000000000)
           {
               maximo=dir[x];
               res=shawarma[x];
           }
       }
       cout<<maximo<<"\n"<<res.first<<" "<<res.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

