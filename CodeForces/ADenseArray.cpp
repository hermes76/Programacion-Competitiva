#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll x=0; x<n; x++)cin>>arr[x];
    ll res=0;
    for(ll x=1; x<n; x++)
    {
        if(arr[x-1]<arr[x])
        {
            for(ll y=arr[x-1]; float(arr[x])/y>2.0; y*=2)
            res++;
        }
        else
        {
             for(ll y=arr[x]; float(arr[x-1])/y>2.0; y*=2)
                res++;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}

