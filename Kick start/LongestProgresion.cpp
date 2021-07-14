
#include <iostream>
#define ll long long int
using namespace std;
ll maxi(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}

ll solve(ll arr[], ll n)
{
    ll arit=2;
    ll act=0;
    ll mayor=0;
    ll dif=arr[1]-arr[0];
    ll aux;
    ll indice;
    for(ll x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]==dif)
            arit++;
        else{
            if(act==0)
            {
                act=1;
                arit++;
                aux=arr[x];
                arr[x]=arr[x-1]+dif;
                indice=x;
            }else
            {
                act=0;
                arr[indice]=aux;
                if(x<n)
                {
                    dif=arr[x]-arr[x-1];
                    arit=2;
                }
                else arit=1;
            }
        }
       // cout<<arr[x-1]<<" "<<arr[x]<<" "<<arit<<" "<<dif<<endl;
        mayor=maxi(arit,mayor);
    }
    arit=2;
    act=0;
    dif=arr[1]-arr[0];
    ll mayor2=0;
    for(ll x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]==dif)
            arit++;
        else{
            if(act==0)
            {
                act=1;
                arit++;
                aux=arr[x];
                arr[x]=arr[x-1]+dif;
                indice=x;
            }else
            {
                act=0;
                arr[indice]=aux;
                x++;
                if(x<n)
                {
                    dif=arr[x]-arr[x-1];
                    arit=2;
                }
                else arit=1;
            }
        }
        mayor2=maxi(mayor2,arit);
    }
    return maxi(mayor2,mayor);
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
        for(ll x=0; x<n; x++)cin>>arr[x];
        cout<<"Case #"<<x<<": "<<solve(arr,n)<<"\n";
    }
}
