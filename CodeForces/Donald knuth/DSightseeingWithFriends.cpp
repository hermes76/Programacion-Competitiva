#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve(ll n, ll m, pair<ll,ll> arr[], pair<ll,ll> mapeo[])
{
    ll aux=0;
    for(ll x=0; x<m; x++)
    {
        if(aux+1==arr[x].first)
        {
            mapeo[aux]=x;

            aux++;
        }
    }
}
string solve2(ll n, ll m,ll a, ll b,pair<ll,ll> arr[], pair<ll,ll> mapeo[])
{
    a--;
    if(mapeo[a].first==-1)return "NO";
    ll limite=mapeo[a].first+mapeo[b].second;

    ll k=mapeo[a].first-1;
    for(ll x=limite/2; x>mapeo[a].first; x/=2)
        while(k+x<limite && arr[k+x].second>=b)k+=x;
    if(k==mapeo[])
        return "YES";
    return "NO";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,q;
    cin>>n>>m>>q;
    pair<ll,ll> arr[m];
    pair<ll,ll> mapeo[n];
    ll a,b;
    for(ll x=0; x<m; x++)
    {
        cin>>a>>b;
        arr[x].first=a;
        arr[x].second =b;
    }
    sort(arr,arr+n);
    solve(n,m,arr,mapeo);

}
