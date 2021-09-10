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
    ll n; cin>>n;
    ll arr[n];
    ll cuenta[n];
    ll maximo=0;
    ll nums=0;
    for(ll x=0; x<n; x++)
    {
        cin>>arr[x];
        cuenta[x]=0;
    }
    for(ll x=0; x<n; x++)
        cuenta[arr[x]-1]++;
    for(ll x=0; x<n; x++)
    {
        maximo=max(maximo,cuenta[x]);
        if(cuenta[x]>=1)
            nums++;
    }
    return max(min(nums-1,maximo),min(nums,maximo-1));


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)cout<<solve()<<endl;
}

