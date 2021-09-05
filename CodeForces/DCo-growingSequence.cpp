
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    ll y;
    ll guardar=arr[0];
    cout<<0<<" ";
    ll mini;
    ll aux;
    for(ll x=1; x<n; x++)
    {
        mini=INF;
        for(y=2; y<=8589934592; y<<=1)
        {

            if((guardar&(y-1))==guardar && mini>((y-1)^arr[x]))
            {
               mini=((y-1)^arr[x]);
               aux=y-1;
            }
        }
        guardar=aux;
        cout<<mini<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)solve();
}
