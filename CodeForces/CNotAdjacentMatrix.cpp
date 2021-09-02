
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
    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }
    ll arr[n][n];
    for(ll x=0; x<n; x++)
        for(ll y=0; y<n; y++)
        arr[x][y]=0;
    ll indice=1;
    ll x;
    ll y,z;
    for(x=0; x<n; x+=2)
    {
        y=0;
        z=x;
        while(z>=0)
        {
            arr[y][z]=indice;
            y++;
            z--;
            indice++;
        }
    }
    if(n%2==1)
        x=2;
    else x=1;
    for(x; x<n; x+=2)
    {
        y=x;
        z=n-1;
        while(y<n)
        {
            arr[y][z]=indice;
            y++;
            z--;
            indice++;
        }
    }
     for(x=1; x<n; x+=2)
    {
        y=0;
        z=x;
        while(z>=0)
        {
            arr[y][z]=indice;
            y++;
            z--;
            indice++;
        }
    }
    if(n%2==1)
        x=1;
    else x=2;
    for(x; x<n; x+=2)
    {
        y=x;
        z=n-1;
        while(y<n)
        {
            arr[y][z]=indice;
            y++;
            z--;
            indice++;
        }
    }
    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<n; y++)
        {
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    while(n--)
        solve();
}
