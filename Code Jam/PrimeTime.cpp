
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
bool posible(pair<ll,ll> arr[], ll n, ll k)
{
    ll prod=1;
    ll y;
    for(int x=n-1; x>=0;x--)
    {
        y=0;
    //    cout<<k<<" "<<arr[x].first*prod<<endl;
        while(k%(arr[x].first*prod)==0 and y<arr[x].second)
        {
            prod*=arr[x].first;
            y++;
        }
    }
    if(prod==k)
        return 1;
    return 0;
}
bool isgood(pair<ll,ll> arr[], ll n, ll k)
{
    ll prod=1;
    ll suma=0;
    ll y;
    for(int x=n-1; x>=0;x--)
    {
        y=0;
         while(k%(arr[x].first*prod)==0 and y<arr[x].second)
        {
            prod*=arr[x].first;
            y++;
        }
        suma+=(arr[x].second-y)*arr[x].first;
    }
    if(suma==k)
        return 1;
    return 0;
}
ll solve(pair<ll,ll> arr[], ll n)
{
    ll k=0;
    ll suma=0;
    ll res=0;
    for(ll x=0; x<n; x++)
        suma+=(arr[x].first*arr[x].second);
    for(ll x=suma/2; x<suma; x++)
    {
        if(posible(arr,n,x))
            if(isgood(arr,n,x))
                if(res<x)
                    res=x;
       // cout<<res<<endl;
    }
    return res;
}
int main()
{
    ll t;
    ll n;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        cin>>n;
        pair<ll,ll> arr[n];
        for(ll y=0; y<n; y++)
            cin>>arr[y].first>>arr[y].second;
        cout<<"Case #"<<x<<": "<<solve(arr,n)<<"\n";
    }
}
