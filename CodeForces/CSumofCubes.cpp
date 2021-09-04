#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

string solve()
{
    ll n;
    cin>>n;
    for(ll x=1; x<=pow(n,1/3.); x++)
    {
        ll k=0;
        for(ll y=10000; y>0; y/=2)
        {
            while(x*x*x+(k+y)*(k+y)*(k+y)<= n)
            {
                k+=y;
            }
        }
        if(k!=0)
        if(x*x*x+(k)*(k)*(k)== n)
            return "YES";
    }
    return "NO";
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

