#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

struct coord{
    ll x,y,val;
};
queue <coord> cola;
ll grid[300][300];
bool boolgrid[300][300];
int ejex[4]={1,0,-1,0};
int ejey[4]={0,1,0,-1};
void mapeo(int n, int m)
{
    coord aux;
    while(!cola.empty())
    {
        aux= cola.front();
        cola.pop();
        for(int x=0; x<4; x++)
        {
            coord suma=aux;
            suma.x+=ejey[x];
            suma.y+=ejex[x];
           // cout<<suma.x<<" "<<suma.y;
            if(suma.x<n and suma.x>=0 and suma.y>=0 and suma.y<m and grid[suma.x][suma.y]<suma.val and suma.val>0 and !boolgrid[suma.x][suma.y])
            {
                //cout<<" "<<1;
                grid[suma.x][suma.y]=suma.val;
                suma.val--;
                cola.push(suma);
            }
           // cout<<endl;
        }
    }
}
ll conteo(int n,int m)
{
    ll suma=0;
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            if(!boolgrid[x][y])
                suma+=grid[x][y];
    return suma;
}
void reset(int n , int m)
{
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            grid[x][y]=0;
}
void breset(int n , int m)
{
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            boolgrid[x][y]=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    ll res;
    coord aux;
    cin>>t;
    for(int x=1; x<=t; x++)
    {
        cin>>n>>m;
        reset(n,m);
        breset(n,m);
        for(int y=0; y<n; y++)
            for(int z=0; z<m; z++)
            {
                cin>>grid[y][z];
                if(grid[y][z]>0)
                {
                    boolgrid[y][z]=1;
                    aux.x=y;
                    aux.y=z;
                    aux.val=grid[y][z]-1;
                    cola.push(aux);
                }
            }
            mapeo(n,m);/*
            cout<<endl;
            for(int y=0; y<n; y++)
            {
                for(int z=0; z<m; z++)
                {
                    cout<<grid[y][z]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;*/
            res= conteo(n,m);

            cout<<"Case #"<<x<<": "<<res<<"\n";
    }
}
