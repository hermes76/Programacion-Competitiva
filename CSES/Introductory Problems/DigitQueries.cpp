
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;
char cads[10000];
ll solve(ll pos)
{
    if(pos<9)
        return pos;
    if(pos<180)
        if(pos%2)
            return (pos/2)-1;
        return
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll pos;
    cin>>n;
    for()
    while(n--)
    {
        cin>> pos;
        cout<<solve(pos);
    }
}
