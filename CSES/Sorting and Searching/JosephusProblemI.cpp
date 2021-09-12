
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
    ll x=2;
    for(x; x<=n; x+=2)
        cout<<x<<" ";
    for(ll y =1; y<=n; y+=2)
        vll.push_back(y);
    if(n%2==1)
        x=0;
    else x=1;
    while(!vll.empty())
    {
        for(x; x<vll.size(); x++)
        {
            cout<<vll[x]<<" ";
            vll.erase(vll.begin()+x);
        }
        if(vll.size()>0)
            x%=vll.size();
    }
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
