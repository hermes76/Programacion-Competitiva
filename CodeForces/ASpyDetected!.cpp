#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve()
{
    ll n;
    cin>>n;
    ll num;
    pair <ll,ll> conts[101];
    for(ll x=0; x<100; x++)
    {
        conts[x].second=0;
        conts[x].first=0;
    }
    for(ll x=0; x<n; x++)
    {
        cin>>num;
        conts[num-1].first=x;
        conts[num-1].second++;
    }
    for(ll x=0; x<100; x++)
        if(conts[x].second==1)
        return conts[x].first+1;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}

