
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

ll solve()
{

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    bool res[n];
    for(ll x=0; x<(1<<n); x++)
    {
        for(ll y=0; y<n; y++)
        {
            if(x&(1<<y))
                res[y]=1;
            else res[y]=0;
        }
        for(ll z=n-1; z>=0; z--)
            cout<<res[z];
        cout<<"\n";
    }
}
