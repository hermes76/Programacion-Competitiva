
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
ll maxi(ll a, ll b)
{
    if(a>b)
        return a;
    return b;
}
ll mini(ll a, ll b)
{
    if(a<b)
        return a;
    return b;
}
ll solve(int n)
{
    ll arr[n];
    ll cuenta;
    ll indice=1;
    ll maximo;
    for(int x=0; x<n; x++) cin>>arr[x];
    cuenta=arr[0];
    maximo=cuenta;
    for(int x=1; x<n; x++)
    {
        if((indice+1)*cuenta<arr[x])
        {
            cuenta=arr[x];
            indice=1;
        }
        else
        {
            indice++;
            cuenta=mini(cuenta,arr[x]);
        }
        cout<<indice*cuenta<<endl;
        maximo=maxi(maximo,indice*cuenta);
    }
    return maxi(maximo,n);
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
}
