#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve(ll m)
{
   ll cuenta=1;
   ll actual=1;
  for(ll x=1; m-actual>0; x+=2, actual+=x)
    cuenta++;
  return cuenta;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        cout<<solve(m)<<endl;
    }

}
