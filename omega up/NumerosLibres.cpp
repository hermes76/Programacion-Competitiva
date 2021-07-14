#include <iostream>
#include <queue>
using namespace std;
struct col{
    int posx;
    int posy;
};
queue<col>cola;
int main()
{
    int n,m;
    cin>>n>>m;
    int matriz[n][m];
    for(int x =0; x<n; x++)
    {
       for(int y =0; y<m; y++)
        {
            matriz[x][y] =0;
        }
    }
    int x[2]={1,0};
    int y[2]={0,1};
    col A;
    int contador=2;
    A.posx=0;
    A.posy=0;
    matriz[0][0] = 1;
    cola.push(A);
    while(!cola.empty())
    {
        col aux = cola.front();
         cola.pop();
        for(int i =0; i<2; i++)
        {
            int pax=aux.posx+x[i];
            int pay=aux.posy+y[i];
            if(pax<m and pay<n and matriz[pay][pax] ==0)
            {
                matriz[pay][pax] = contador;
                contador++;
                col aux2;
                aux2.posx = pax;
                aux2.posy = pay;
                cola.push(aux2);
            }
        }
    }
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
