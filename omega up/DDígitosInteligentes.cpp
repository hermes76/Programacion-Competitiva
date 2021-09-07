#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
ll fun(ll num)
{
    ll sum=0;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}
void solve()
{
    ll n;
    cin>>n;
    ll arr[100001];
    arr[0]=0;
    for(ll x=1; x<=100000; x++)
        arr[x]=arr[x-1]+fun(x);
    ll a,b;
    for(ll x=0; x<n; x++)
    {
        cin>>a>>b;
        if(a==0)
            cout<<(arr[b])<<"\n";
            else
        cout<<(arr[b]-arr[a-1])<<"\n";
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
