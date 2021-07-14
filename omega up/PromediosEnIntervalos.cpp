#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
ll suma[100005];
bool isgoodlow(pair<ll,ll> alumnos[], ll n, ll abajo,ll k)
{
    if(k<n)
        if(alumnos[k].first< abajo)
        return 1;
    return 0;
}
bool isgoodup(pair<ll,ll> alumnos[], ll n, ll arriba,ll k)
{
    if(k<n)
        if(alumnos[k].first<= arriba)
        return 1;
    return 0;
}
ll solve(pair<ll,ll> alumnos[], ll n,ll abajo,ll arriba)
{
    ll low=-1;
    ll up=-1;
    for(ll x=n>>1; x>0; x>>=1)
        while(isgoodlow(alumnos,n,abajo,low+x))low+=x;
    for(ll x=n>>1; x>0; x>>=1)
        while(isgoodup(alumnos,n,arriba,up+x))up+=x;
    if(up ==low)
        return -1;
    else if(low==-1)
        return suma[up]/(up+1);
    return (suma[up]-suma[low])/(up-low);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll preguntas;
    ll abajo,arriba;
    cin>>n;
    pair<ll,ll> alumnos[n];
    for(int x=0; x<n; x++)
        cin>>alumnos[x].first>>alumnos[x].second;
    cin>>preguntas;
    sort(alumnos,alumnos+n);
    suma[0]=alumnos[0].second;
    for(int x=1; x<n; x++)
        suma[x]=alumnos[x].second+suma[x-1];
    while(preguntas--)
    {
        cin>>abajo>>arriba;
        cout<<solve(alumnos,n,abajo,arriba)<<"\n";
    }
}
