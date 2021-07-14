#include <iostream>
#define ll long long int
using namespace std;
ll min2(ll a, ll b)
{
    if(a<b)
        return a;
    return b;
}
ll solve(ll CJ, ll JC, string cad)
{
    ll costo=0;
    ll x=0;
    char aux;
    while(cad[x]=='?')
        x++;
    for(x; x<cad.length()-1; x++)
    {
        if(cad[x]=='C' and cad[x+1]=='J')
            costo+=CJ;
        else if(cad[x]=='J' and cad[x+1]=='C')
            costo+= JC;
        else if(cad[x]=='?')
        {
            if(x-1>=0)
                aux=cad[x-1];
            while(cad[x]=='?' and x<cad.length())
                x++;
                if(x>=cad.length()) break;
            if(aux!=cad[x])
            {
                if(aux=='J')
                    costo+=JC;
                else
                    costo+=CJ;
            }
        }
    }
    return costo;
}
int main()
{
    ll t,CJ,JC;
    string cad;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        cin>>CJ>>JC>>cad;
        cout<<"Case #"<<x<<": "<<solve(CJ,JC,cad)<<endl;
    }
}
