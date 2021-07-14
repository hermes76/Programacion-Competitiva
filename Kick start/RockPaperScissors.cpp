
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

string solve(ll X,ll W, ll E,ll *R, ll *P, ll *S, ll puntuacion)
{
    string cad;
    dll PrR,PrP,PrS;
    for(int x=0; x<60; x++)
    {
        PrR=(*S)/(x+1);
        PrP=(*R)/(x+1);
        PrS=(*P)/(x+1);
        if(PrR==1/3)
        {
            cad+='R';
            (*R)++;
        }else if(PrR> PrP and PrR>PrS)
        {
            cad+='P';
            (*P)++;
        }
        else if(PrP >PrR and PrP>PrS)
        {
            cad+='S';
            (*S)++;
        }
        else if(PrS> PrR and PrS>PrP)
        {
            cad+='R';
            (*R)++;
        }
    }
    return cad;
}
int main()
{
   // ios::sync_with_stdio(false);
    //cin.tie(NULL);
    ll t,X,W,E,puntuacion;
    ll R,P,S;
    R=P=S=0;
    cin>>t>>X;
    for(int x=1; x<=t; x++)
    {
        cin>>W>>E;
        cout<<"Case #"<<x<<": "<<solve(X,W,E,&R,&P,&S,0)<<'\n';
    }
}
