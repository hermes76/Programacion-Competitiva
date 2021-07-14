#include <iostream>
#include <queue>
using namespace std;
struct estado{
    int x;
    int y;
};
int n,m;
char arr[1000][1000];
int ejex[4]={1,0,-1,0};
int ejey[4]={0,1,0,-1};
int cuenta=0;
queue <estado> cola;
void a()
{
    estado aux;
    while(!cola.empty())
    {
        aux=cola.front();
        cola.pop();
        for(int x=0; x<4; x++)
        {
            estado p=aux;
            p.x+=ejex[x];
            p.y+=ejey[x];
            if(arr[p.y][p.x]=='.' and p.x>=0 and p.x <n and p.y >=0 and p.y <m)
            {
                arr[p.y][p.x]='#';
                cola.push(p);
            }
        }
    }
    cuenta++;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>m>>n;
    for(int x =0; x<m; x++)
    {
        for(int y =0; y<n; y++)
        {
            cin>>arr[x][y];
        }
    }
    estado aux;
    for(int x=0; x<m; x++)
    {
        for(int y =0; y<n; y++)
        {
            if(arr[x][y]=='.')
            {
                aux.x=y;
                aux.y=x;
                cola.push(aux);
                a();
            }
        }
    }
    cout<<cuenta;
}
