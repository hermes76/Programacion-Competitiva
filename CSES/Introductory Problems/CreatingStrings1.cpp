#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int cuenta=1;
map <char, int> mapa;
set <char> conjunto;
int longitud;
string palabra;
string cad;
int res=1;
void search(int len)
{
    if(len==longitud)
    {
        cout<<palabra<<endl;
    }
    else{
            set <char> ::iterator it;
        for(it=conjunto.begin(); it!= conjunto.end(); it++)
        {
            if(mapa[*it]>0)
            {
                palabra[len]=*it;
                mapa[*it]--;
                search(len+1);
                mapa[*it]++;
            }
        }
    }
}
int main()
{
    cin>>cad;
    longitud=cad.length();
    for(int x=0; x<longitud; x++)
    {
        mapa[cad[x]]++;
        conjunto.insert(cad[x]);
    }
    for(int x=1; x<=longitud; x++)
    {
        cuenta*=x;
    }
    set <char> ::iterator it;
        for(it=conjunto.begin(); it!= conjunto.end(); it++)
        {
            for(int x =1; x<=mapa[*it]; x++)
            {
                res*=x;
            }
        }
        cuenta/=res;
    sort(cad.begin(),cad.end());
    palabra=cad;
    cout<<cuenta<<endl;
    search(0);
}
