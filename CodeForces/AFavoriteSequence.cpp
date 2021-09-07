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
    ll n; cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    ll indexL=0, indexR=n-1;
    while(indexL<=indexR)
    {
        if(indexL!=indexR)
            cout<<arr[indexL]<<" "<<arr[indexR]<<" ";
        else
            cout<<arr[indexL];
        indexL++;
        indexR--;
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
