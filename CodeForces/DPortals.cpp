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
    ll n,m,k;
    cin>>n>>m>>k;
    ll warriors_need[n+1];
    ll warriors[n+1];
    ll points[n+1];
    multiset<ll,less<ll>>value;
    vector<set<ll>>castle_from;
    ll castle_to[n+1];
    ll a,b,c,from,to;
    castle_from.resize(n+1);
    for(ll x=1; x<=n; x++)
    {
        cin>>a>>b>>c;
        warriors_need[x]=a;
        warriors[x]=b;
        points[x]=c;
    }
    for(ll x=0; x<=n; x++)
        castle_to[x]=-1;
    for(ll x=0; x<m; x++)
    {
        cin>>from>>to;
        if(castle_to[to]==-1)
        {
            castle_from[from].insert(to);
            castle_to[to]=from;
        }else if(castle_to[to]<from)
        {
            castle_from[castle_to[to]].erase(to);
            castle_from[from].insert(to);
            castle_to[to]=from;
        }
    }
    for(ll x=1; x<=n; x++)
    {
        if(k<warriors_need[x])
        {
            ll request= warriors_need[x]-k;
            if(request>value.size())
                return -1;
            while(request--)
                value.erase(value.begin());
            k=warriors_need[x];
        }
        k+=warriors[x];
        for(auto y: castle_from[x])
        {
            if(points[y]>0)
            {
                value.insert(points[y]);
                k--;
            }
        }
        if(castle_to[x]==-1)
        {
            if(points[x]>0)
            {
                value.insert(points[x]);
                k--;
            }
        }
        if(k<0)
        {
            ll request = 0-k;
            if(request>value.size())
                return -1;

            while(request--)
                value.erase(value.begin());
            k=0;
        }
    }
    ll sum=0;
    for(auto x: value)
        sum+=x;
    return sum;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}
