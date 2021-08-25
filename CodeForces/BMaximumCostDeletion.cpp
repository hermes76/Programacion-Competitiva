#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll cubos(ll n, string cad,char a)
{
    bool act=0;
    ll cont=0;
    for(ll x=0; x<n; x++)
    {
        if(cad[x]==a)
            act=1;
        else if (act)
        {
            cont++;
            act=0;
        }
    }
    if(act)
        cont++;
    return cont;
}
ll solve(ll n, ll a, ll b, string cad)
{
    ll res=a*n;
    ll cu0= cubos(n,cad,'0');
    ll cu1=cubos(n,cad,'1');
    ll aux=cu0;
    cu0+= (cu1>=1) ? 1:0;
    cu1+= (aux>=1) ? 1:0;

    return res + max(b*n ,max(cu0*b,cu1*b));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,a,b;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>s;
        cout<<solve(n,a,b,s)<<endl;
    }
}
