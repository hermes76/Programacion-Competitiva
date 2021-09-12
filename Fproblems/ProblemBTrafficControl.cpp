
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
ifstream in("input.txt");
ofstream out("output.txt");
void solve()
{
    ll n,m,a,b;
    in>>n>>m>>a>>b;
    ll arr[n][m];
    for(ll x=0; x<n; x++)
        for(ll y=0; y<m; y++)
        arr[x][y]=1000;
    arr[0][0]=a-(n+m-2);
    arr[n-1][0]=b-(n+m-2);
    for(ll x=1; x<m; x++)
        arr[0][x]=1;
    for(ll x=0; x<n; x++)
        arr[x][m-1]=1;
    for(ll y=1; y<m; y++)
        arr[n-1][y]=1;
    if(arr[0][0]>=1 && arr[n-1][0]>=1)
    {
        out<<"Possible\n";
        for(ll x=0; x<n; x++)
        {
            for(ll y=0; y<m; y++)
            {
                out<<arr[x][y]<<" ";
            }
            out<<"\n";
        }
    }else  out<<"Impossible\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    in>>t;
    for(ll x=1; x<=t; x++)
    {
        out<<"Case #"<<x<<": ";
        solve();
    }
}
