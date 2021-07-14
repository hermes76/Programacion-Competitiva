
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

ll solve(ll arr[], ll n)
{
    ll anterior = arr[0];
    ll operaciones=0;
    bool activador;
    for(int x=1; x<n; x++)
    {
        activador=0;
        while(anterior>= arr[x])
        {
            operaciones++;
            arr[x]*=10;
            activador=1;
            if(anterior-10<=arr[x] and anterior%10 != 9)break;
        }
        if(anterior>= arr[x])
        {
            if(!activador)
                operaciones++;
            arr[x]+=(anterior%10)+1;

        }
        anterior=arr[x];
    }
    return operaciones;
}
int main()
{
    ll t;
    ll n;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        cin>>n;
        ll arr[n];
        for(ll y=0; y<n; y++)cin>>arr[y];
        cout<<"Case #"<<x<<": "<<solve(arr, n)<<"\n";
    }
}
