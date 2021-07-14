#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
bool comp(string cad, char res[], ll n)
{
    string cadaux;
    for(ll x=0; x<n; x++)
        cadaux+=res[x];
    if(cadaux<cad)
        return 1;
        return 0;
}
ll cuentaPar(ll n, ll k, string cad,char res[], ll pos,bool *ya)
{
    if(pos==(n/2))
    {
        ll posx=(n/2)-1;
        for(ll x=(n/2); x<n; x++)
        {
            res[x]=res[posx];
            posx--;
        }
       /* for(ll x=0; x<n; x++)
            cout<<res[x];
        cout<<endl;*/
        if(comp(cad,res,n))
        return 1;
        else
        {
             *ya=0;
            return 0;
        }
    }
    ll cuenta=0;
    for(ll x=0; x<k; x++)
    {
        if(*ya==0)
            break;
        res[pos]= 'a'+x;
        cuenta+=cuentaPar(n,k,cad,res,pos+1,ya)%MOD;
    }
    return cuenta;
}
ll cuentaImpar(ll n, ll k, string cad,char res[], ll pos,bool *ya)
{
    if(pos==(n/2)+1)
    {
        ll posx=(n/2)-1;
        for(ll x=(n/2)+1; x<n; x++)
        {
            res[x]=res[posx];
            posx--;
        }
           /* for(ll x=0; x<n; x++)
            cout<<res[x];
        cout<<endl;*/
        if(comp(cad,res,n))
            return 1;
        else
        {
             *ya=0;
            return 0;
        }
    }
    ll cuenta=0;
    for(ll x=0; x<k; x++)
    {
        if(*ya==0)
            break;
        res[pos]= 'a'+x;
        cuenta+=cuentaImpar(n,k,cad,res,pos+1,ya)%MOD;
    }
    return cuenta;
}
ll solve(ll n, ll k, string cad)
{
    bool ya=1;
    if(n%2==0)
    {
        char res[n];
        return cuentaPar(n,k,cad,res,0,&ya);
    }else
    {
        char res[n];
        return cuentaImpar(n,k,cad,res,0,&ya);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    string cad;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        cin>>n>>k>>cad;
         cout<<"Case #"<<x<<": "<<solve(n,k,cad)<<"\n";
    }
}
