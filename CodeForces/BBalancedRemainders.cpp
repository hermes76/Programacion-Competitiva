
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
    ll modulos[3]={0,0,0};
    for(ll x=0; x<n; x++)
        modulos[arr[x]%3]++;
    ll target=modulos[0]+modulos[1]+modulos[2];
    target/=3;
    ll res=0;
    ll precio[3][3]={{0,2,1},{1,0,2},{2,1,0}};
    ll menor;
    for(ll x=0; x<3; x++)
    {
        if(modulos[x]<target)
        for(ll y=0; y<3; y++)
        {
            if(x==y)continue;
            if(modulos[y]>target)
            {
                menor=min(target-modulos[x],modulos[y]-target);
                modulos[x]+=menor;
                modulos[y]-=menor;
                res+=menor*precio[x][y];
            }

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
