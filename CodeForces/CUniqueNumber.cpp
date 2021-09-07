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
     ll sum=0;
     vll.clear();
     for(ll x=9; x>=1; x--)
     {
         if(sum+x<=n)
         {
            sum+=x;
            vll.push_back(x);
         }
     }
     reverse(all(vll));
     if(sum==n)
        for(auto x:vll)
            cout<<x;
    else cout<<-1;
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();
}

