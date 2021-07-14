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
ofstream fout ("outb.txt");
ifstream fin ("b.txt");


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
    if(a.b< b.b)
        return 1;
    return 0;
}
int main()
{
    ll segundos,intersecciones, calles,carros,puntos;
    unordered_map <int, int> mapa;
    unordered_map <string, int> mapi;
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
    indice=-1;
    for(int x=0; x<vCalles.size(); x++)
    {
        if(indice!=vCalles[x].b and semaforos[vCalles[x].Nombre]==1)
        {
            mapa[vCalles[x].b]++;
        }
    }
    indice=-1;
    int conta=0;
    for(int x=0; x<vCalles.size(); x++)
    {
        if(semaforos[vCalles[x].Nombre]==1)
        {
            conta=0;
            if(indice!=vCalles[x].b)
            {
                res++;
                fout<<vCalles[x].b<<"\n"<<mapa[vCalles[x].b]<<"\n";
                indice=vCalles[x].b;
            }
            fout<<vCalles[x].Nombre<<" "<<1<<"\n";
        }
    }
    cout<<res;

}
