
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
    ll a,b,c;
    cin>>a>>b>>c;
    ll mini,maxi,dif;
    mini=min(a,b);
    maxi=max(a,b);
    dif=maxi-mini;
    if(maxi/2<mini)
        return -1;
    if(dif*2<c)
        return -1;
    if((dif+1)<c)
        return c-dif;
    if((dif+1)>c)
        return c+dif;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)cout<<solve()<<endl;
}
