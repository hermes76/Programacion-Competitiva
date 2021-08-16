
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a,b;
    b=2;
    a=n*(n+1)/2;
    if(a==0)
        a=1;
    if(a%2==0)
    {
        a/=2;
        b=1;
    }
    cout<<a<<"/"<<b;
}
