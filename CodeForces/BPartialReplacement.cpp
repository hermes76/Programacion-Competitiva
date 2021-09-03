
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
    ll n,k;
    string cad;
    cin>>n>>k>>cad;
    ll i;
    for(i=0; i<n; i++)if(cad[i]=='*')
        break;
    ll j;
    for(j=n-1; j>=0; j--)if(cad[j]=='*')
        break;
    if(i==j)
        return 1;
    if(i== n)
        return 0;
    ll ultimo=i;
    ll distancia=0;
    ll res=2;
    ll xi=i;
    for(ll x=i; x<j; x++)
    {
        distancia=abs(x-xi);
        if(cad[x]=='*')
            ultimo=x;
        if(distancia>=k)
        {

            xi=ultimo;
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
