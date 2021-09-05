#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
ll arr[300001];
ll solve()
{
    ll n, m;
    cin>>n>>m;
    ll longitud=n;
    ll res=0;
    ll x;
    res=arr[n-1];
    if(res==m)
        return longitud;
    else if((res^m)!=n)
       return longitud+1;
    return longitud+2;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    arr[0]=0;
    for(ll x=1; x<=300001; x++)
        arr[x]=arr[x-1]^x;
    while(t--)cout<<solve()<<endl;
}

