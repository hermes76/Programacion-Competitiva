#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    ll len;
    string cad;
    ll indice;
    char aux;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        cin>>len>>cad;
        cout<<"Case #"<<x<<": ";
        cout<<1<<" ";
        aux=cad[0];
        indice=2;
        for(ll x=1; x<len; x++)
        {
            if(aux>=cad[x])
                indice=1;
            aux=cad[x];
            cout<<indice<<" ";
            indice++;
        }
        cout<<"\n";
    }
}
