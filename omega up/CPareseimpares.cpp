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
    ll im=0,par=0;
    ll num;
    for(ll x=0; x<n; x++)
        cin>>num , im+= (num%2==1) ? 1:0 , par +=(num%2==0) ? 1:0;
    cout<<par<<" "<<im;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
