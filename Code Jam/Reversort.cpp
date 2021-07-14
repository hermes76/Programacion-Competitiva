#include <iostream>
#define ll long long int
using namespace std;
ll min2(ll a, ll b)
{
    if(a<b)
        return a;
    return b;
}
ll Reverse(ll n,ll i,ll j, ll arr[])
{
    ll aux;
    for(int x=i-1; x<j/2; x++)
    {
            aux=arr[x];
        arr[x]=arr[j-x-1];
        arr[j-x-1]=aux;
    }
    return j-i+1;
}
ll solve(ll n, ll arr[])
{
    ll cont=0;
    ll j;
    ll menor;
    int x,y;
    for(y=0; y<n-1; y++)
    {
        j=y+1;
        menor=arr[y];
        for(x=y; x<n; x++)
        {
            if(menor>arr[x])
            {
                menor=arr[x];
                j=x+1;
            }
        }
       cont+= Reverse(n,y+1,j,arr);
    }
    return cont;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n;
    cin>>t;
    for(int x=1; x<=t; x++)
    {
        cin>>n;
        ll arr[n];
        for(int x=0; x<n; x++)cin>>arr[x];
        cout<<"Case #"<<x<<": "<<solve(n,arr)<<"\n";
    }

}
