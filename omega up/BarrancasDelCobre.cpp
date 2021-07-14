#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    ll emocion=0;
    ll mayor=0;
    for(ll x=0; x<n; x++)cin>>arr[x];
    for(ll x=1; x<m; x++)emocion+=arr[x]-arr[x-1];
    mayor=emocion;
    for(ll x=m; x<n; x++)
    {
        emocion -= arr[x-m+1]-arr[x-m];
        emocion+= arr[x]-arr[x-1];
        mayor=max(emocion,mayor);
    }
    cout<<mayor;
}
