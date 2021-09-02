
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
     ll res=0;

     for(ll x=1; x<=n; x=x*10+1)
    {
        for(ll y=1; y<=9 && x*y<=n; y++)
            res++;
    }
    return res;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    while(n--)
        cout<<solve()<<endl;
}
