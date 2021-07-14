#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define all(x) x.begin(),x.end()
#define INF 1e9
#define mod 10000009
using namespace std;
vector <ll> vll;

bool isgood(ll n, ll casillas, ll k)
{
    ll suma=0;
    ll tam=1;
    for(ll x=0; x<n; x++)
    {
        if(vll[x]>k)
            return 0;
        if(suma+vll[x]<=k)
            suma+=vll[x];
        else{
            suma=vll[x];
            tam++;
        }
    }
     if(tam<=casillas)
        return 1;
     return 0;
}
ll solve(ll n, ll casillas)
{
    ll k=0;
    ll r=1;
    for(int x=0; x<n; x++)
        r+=vll[x];
   for(ll x=r/2; x>0; x/=2)
        while(!isgood(n,casillas,k+x))k+=x;
    return k+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,casillas,num;
    cin>>n>>casillas;
    forr(0,n,1)
    {
        cin>>num;
        vll.push_back(num);
    }
      cout<<solve(n,casillas);
}
