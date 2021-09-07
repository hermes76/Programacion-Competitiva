
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
    ll suma=0,suma2=0;
    for(ll x=0; x<n/2; x++)
        suma+=arr[x];
     for(ll x=n/2; x<n; x++)
        suma2+=arr[x];

        if(suma==suma2)
                    cout<<suma<<" "<<1;
        else cout<<suma+suma2<<" "<<0;
        cout<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
