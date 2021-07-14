#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define all(x) x.begin(),x.end()
#define INF 1e9
#define mod 10000009
using namespace std;
vector <ll> vll;
bool isgood(ll n, ll va, ll k)
{
    ll inicial = vll[0];
    ll cuenta=2;
    if(va==2){
        if(vll[n-1]-inicial>=k)
        {
            return 1;
        }
        else return 0;
    }
    for(ll x=1; x<n; x++)
    {
        if(vll[x]-inicial>=k)
        {
            cuenta++;
            inicial= vll[x];
        }
        if(cuenta>=va)
        {
              if(vll[n-1]-inicial>=k)
                return 1;
              return 0;
        }
    }
    return 0;
}
ll solve(ll n, ll va)
{
    ll r,k,l;
    l=0;
    r=vll[n-1]-vll[0]+1;
    while(r>l+1)
    {
        k=(l+r)/2;
        if(isgood(n,va,k))
            l=k;
        else
            r=k;
    }
    return l;
}
int main()
{
    ll n, vacas,dato;
    cin>>n>>vacas;
    forr(0,n,1)
    {
        cin>>dato;
        vll.push_back(dato);
    }
    cout<<solve(n,vacas);
}
