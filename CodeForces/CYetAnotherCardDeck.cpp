
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
vector <pair<ll,ll>> vll;
bool cuentas[51];
ll solve(ll n, ll busq)
{
    ll res;
    ll x;
    ll y;
    pair<ll,ll> aux;
    for(x=0; x<n; x++)
        if(vll[x].first==busq)
        {
            res=vll[x].second;
            break;
        }
    aux=vll[x];
    aux.second=1;
    y=x-1;
   for(y; y>=0; y--)
        vll[y+1]=vll[y];
    for(x; x>=1; x--)
        vll[x].second++;
    vll[0]=aux;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,busq;
    ll dato;
    ll indice=0;
    pair<ll,ll> aux;
    cin>>n>>q;
    for(ll x=1; x<=n; x++)
    {
        cin>>dato;
        if(!cuentas[dato])
        {
            aux.first=dato;
            aux.second=x;
            vll.push_back(aux);
            cuentas[dato]=1;
            indice++;
        }
    }
    while(q--)
    {
        cin>>busq;
        cout<<solve(indice,busq)<<" ";
    }
}
