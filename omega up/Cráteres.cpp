
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
struct estado
{
    int x,y;
};
queue <estado>cola;
int grid[500][500];
int ejex[4]={1,0,-1,0};
int ejey[4]={0,1,0,-1};
int DPS(int n, int m)
{
    int solucion=0;
    estado actual;
    while(!cola.empty())
    {
        actual=cola.front();
        cola.pop();
        for(int x=0; x<4; x++)
        {
            estado aux=actual;
            aux.x+=ejex[x];
            aux.y+=ejey[x];
            if(aux.x>=0 and aux.x <m and aux.y >=0 and aux.y <n and grid[aux.y][aux.x] != 0)
            {
                solucion+=grid[aux.y][aux.x];
                grid[aux.y][aux.x]=0;
                cola.push(aux);
            }
        }
    }
    return solucion;
}
void solve(int n, int m)
{
    estado actual;
    int pasos;
    int numCrateres=0;
    int solucionCrateres=0;
    int maximo=0;
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            cin>>grid[x][y];
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            if(grid[y][x]!=0)
            {
                numCrateres++;
                actual.x=x;
                actual.y=y;
                pasos=grid[y][x];
                grid[y][x]=0;
                cola.push(actual);
                pasos+= DPS(n,m);
                if(maximo<pasos)
                {
                    maximo=pasos;
                    solucionCrateres=numCrateres;
                }

            }
    cout<<solucionCrateres<<" "<<maximo;
}
int main()
{
    int n,m;
    cin>>n>>m;
    solve(n,m);
}
