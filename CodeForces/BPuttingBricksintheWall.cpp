#include <iostream>
#include <queue>
using namespace std;
bool arr[200][200];
bool visitados[200][200];
int m;
struct pos
{
    int x;
    int y;
};
queue <pos>cola;
int ejex[4]={-1,0,1,0};
int ejey[4]={0,1,0,-1};
bool a()
{
    for(int x=0; x<m; x++)
    {
       for(int y=0; y<m; y++)
        {
            visitados[x][y]=0;
        }
    }
    pos aux;
    aux=cola.front();
    bool var=arr[aux.y][aux.x];
    pos posi;
    while(!cola.empty())
    {
        aux=cola.front();
        cola.pop();
        for(int x=0; x<4; x++)
        {
            posi=aux;
            posi.x+=ejex[x];
            posi.y+=ejey[x];
            if(posi.x ==0 and posi.y==0)
            {
                 while(!cola.empty())
                    cola.pop();
                    return 1;
            }
            if(posi.x>=0 and posi.x<m and posi.y>=0 and posi.y<m and var == arr[posi.y][posi.x] and visitados[posi.y][posi.x]==0)
            {
                cola.push(posi);
                visitados[posi.y][posi.x]=1;
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    int cuenta;
    string cad;
    pos cord[2];
    pos aux;
    cin>>n;
    char t;
    while(n--)
    {
        cin>>m;
        for(int x=0; x<m; x++)
        {
            cin>>cad;
            for(int y=0; y<m; y++)
            {
                if(cad[y]=='1')
                    arr[x][y]=1;
                else arr[x][y]=0;
            }
        }
        cuenta=0;
        aux.x=m-1;
        aux.y=m-2;
        cola.push(aux);
        if(a())
        {
             cord[0].x=m;
             cord[0].y=m-1;
             cuenta++;
            aux.x=m-1;
            aux.y=m-2;
            cola.push(aux);
            arr[aux.y][aux.x]=!arr[aux.y][aux.x];
            if(a())
            {
                 cord[0].x=2;
                 cord[0].y=2;
                 cord[1].x=1;
                 cord[1].y=2;
                 cuenta=2;
            }
        }
        aux.x=m-2;
        aux.y=m-1;
        cola.push(aux);
        if(a())
        {
            cord[cuenta].x=m-1;
            cord[cuenta].y=m;
            cuenta++;
                aux.x=m-2;
                aux.y=m-1;
                cola.push(aux);
                arr[aux.y][aux.x]=!arr[aux.y][aux.x];
                if(a())
                {
                    cord[0].x=2;
                     cord[0].y=1;
                     cord[1].x=1;
                     cord[1].y=2;
                     cuenta=2;
                }
        }
        cout<<cuenta<<endl;
        for(int x=0; x<cuenta; x++)
        {
            cout<<cord[x].y<<" "<<cord[x].x<<endl;
        }

    }
}
