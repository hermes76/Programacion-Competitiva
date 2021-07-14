#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <time.h>

#include <string>

#define all(a) a.begin(), a.end()

#include <fstream>
#include <iostream>

using namespace std;
ofstream fout ("outa.txt");
ofstream fout1 ("outA.txt");
ifstream fin ("a.txt");


using ull = unsigned long long;
using ll = long long;
using pll = pair<long, long>;
struct Calles{
    ll a,b,c;
    string Nombre;
};
struct Rutas{
    ll a;
    vector <string> street;
};
vector <Calles> vCalles;
vector <Rutas> vRutas;
map <string, bool> semaforos;
//unordered_map <ll , vector<string> callescomunes>visitados;
bool comp(Calles a, Calles b)
{
    if(a.a< b.a)
        return 1;
    return 0;
}
int main()
{
    ll segundos,intersecciones, calles,carros,puntos;
    unordered_map <ll,ll> mapa;
    fin>>segundos>>intersecciones>>calles>>carros>>puntos;
    Calles auxPush;
    Rutas auxRuta;
    string auxcalle;
    ll indice;
    ll res=0;
    for(int x=0; x<calles; x++)
    {
        fin>>auxPush.a>>auxPush.b;
        fin>>auxPush.Nombre;
        fin>>auxPush.c;
       // visitados[auxPush.a].callescomunes.push_back(auxPush.Nombre);
        vCalles.push_back(auxPush);
    }
    for(int x=0; x<carros; x++)
    {
        fin>>indice;
        auxRuta.a=indice;
        for(int y=0; y<indice; y++)
        {
            fin>>auxcalle;
            semaforos[auxcalle]=1;
            auxRuta.street.push_back(auxcalle);
        }
        vRutas.push_back(auxRuta);
    }
    sort(vCalles.begin(),vCalles.end(),comp);
    for(int x=0; x<vCalles.size(); x++)
    {
        mapa[vCalles[x].a]++;
    }
    indice=-1;
    for(int x=0; x<vCalles.size(); x++)
    {
        if(semaforos[vCalles[x].Nombre]==1)
        {
            if(indice!=vCalles[x].a)
            {
                res++;
                fout<<vCalles[x].a<<"\n"<<mapa[vCalles[x].a]<<"\n";
                indice=vCalles[x].a;
            }
            fout<<vCalles[x].Nombre<<" "<<1<<"\n";
        }
    }
    cout<<res;

}
