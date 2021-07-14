#include <iostream>
#include <queue>
using namespace std;
struct P
{
    int x;
    int y;
    long long int p;
};
queue <P> cola;
int n,m;
char arr[1252][1252];
bool visitados[1252][1252];
int ejex[4]={1,0,-1,0};
int ejey[4]={0,1,0,-1};
bool Access(int x, P &j)
{
    do{
        j.x+=ejex[x];
        j.y+=ejey[x];
    }while(arr[j.y][j.x]!='#');
    j.x-=ejex[x];
    j.y-=ejey[x];
    if(visitados[j.y][j.x])
    {
        return 0;
    }visitados[j.y][j.x]=1;
    j.p++;
    return 1;
}
void BFS()
{
    bool a;
    P aux;
    while(!cola.empty())
    {
        a=0;
        aux=cola.front();
        cola.pop();
        if(arr[aux.y][aux.x]=='X')
        {
            cout<<aux.p;
            return;
        }
        for(int x =0; x<4; x++)
        {
            P j=aux;
            j.x+=ejex[x];
            j.y+=ejey[x];
            if(arr[j.y][j.x]=='#')
            {
                a=1;
                break;
            }
        }
        for(int x =0; x<4; x++)
        {
            P j=aux;
            P k=aux;
            j.x+=ejex[x];
            j.y+=ejey[x];
            if(arr[j.y][j.x] != '#' and !visitados[j.y][j.x])
            {
                j.p++;
                visitados[j.y][j.x]=1;
                cola.push(j);
            }
            if(a)
            {
                if(Access(x,k))
                {
                    cola.push(k);
                }
            }
        }
    }
    cout<<"THE CAKE IS A LIE";
}

int main()
{
   cin>>m>>n;
   P jugador;
   for(int x =0; x<m; x++)
   {
       for(int y =0; y<n; y++)
       {
           cin>>arr[x][y];
           if(arr[x][y]=='O')
           {
               jugador.x=y;
               jugador.y=x;
               jugador.p=0;
           }
       }
   }
   visitados[jugador.y][jugador.x]=1;
   cola.push(jugador);
    BFS();
   /* cout<<endl;
    for(int x =0; x<m; x++)
    {
        for(int y =0; y<n; y++)
        {

            cout<<visitados[x][y];
        }
        cout<<endl;
    }*/
}
