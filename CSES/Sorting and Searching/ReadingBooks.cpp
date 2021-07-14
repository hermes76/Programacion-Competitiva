
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

ll solve(ll arr[], ll n)
{
    ll kotivalo=0;
    ll justiina=n-1;
    ll kotivalo_time=arr[0];
    ll justiina_time=arr[n-1];
    ll interseccion=0;
    ll total_time=0;
    if(n==1)
        return arr[0]*2;
    while(kotivalo <n and justiina >=0)
    {
        if(kotivalo==justiina)
        {
            interseccion=justiina;
            if(justiina_time>=kotivalo_time)
            {
                justiina--;
                if(justiina>=0)
                justiina_time=arr[justiina];
            }
            else
            {
                kotivalo++;
                if(kotivalo<n)
                kotivalo_time=arr[kotivalo];
            }
        }
        if(kotivalo_time< justiina_time)
        {
            total_time+=kotivalo_time;
            justiina_time-=kotivalo_time;
            kotivalo++;
            kotivalo_time=arr[kotivalo];
        }
        else if(kotivalo_time> justiina_time)
        {
              total_time+=justiina_time;
            kotivalo_time-=justiina_time;
            justiina--;
            justiina_time=arr[justiina];
        }
        else
        {
            total_time+=kotivalo_time;
            kotivalo++;
            justiina--;
        }
    }
    if(kotivalo<n)
    {
        justiina_time=arr[interseccion];
        total_time+=kotivalo_time;
        if(kotivalo_time<=justiina_time)
        {
            kotivalo++;
            justiina_time-=kotivalo_time;
        }else
            justiina_time=0;
        for(ll x=kotivalo; x<n; x++)
        {
            if(justiina_time>0)
                justiina_time-=arr[x];
            total_time+=arr[x];
        }
        if(justiina_time>0)
            total_time+=justiina_time;
    }
    else if(justiina>=0)
    {
        kotivalo_time=arr[interseccion];
        total_time+=justiina_time;
        if(kotivalo_time>=justiina_time)
        {
            justiina--;
            kotivalo_time-=justiina_time;
        }else
            kotivalo_time=0;
        for(ll x=justiina; x>=0; x--)
        {
            if(kotivalo_time>0)
                kotivalo_time-=arr[x];
            total_time+=arr[x];
        }
         if(kotivalo_time>0)
            total_time+=kotivalo_time;
    }
    return total_time;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    sort(arr,arr+n);
    cout<<solve(arr,n);
}
