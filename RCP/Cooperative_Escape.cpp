#include <iostream>
#include <queue>
using namespace std;
struct Personajes
{
    int x;
    int y;
    int pasos=0;
};
int r,c;
char mapa[30][30];
queue <Personajes> cola;
int arr[2][4] ={1,0,-1,0,
                0,1,0,-1};
int busqueda();
int main()
{
    cin>>r>>c;
    Personajes Bonnie;
    Personajes Clyde;
    for(int x =0; x<r; x++)
    {
        for(int y =0; y<c; y++)
        {
            cin>>mapa[x][y];
            if(mapa[x][y]=='B')
            {
                Bonnie.x=y;
                Bonnie.y=x;
            }
            if(mapa[x][y] == 'C')
            {
                Clyde.x=y;
                Clyde.y=x;
            }
        }

    }
    cola.push(Bonnie);
    int boni=busqueda();
    while(!cola.empty())
    {
        cola.pop();
    }
    cola.push(Clyde);
    int cly=busqueda();
    if(boni !=-1 and cly !=-1)
    {
        cout<<boni+cly;
    }else{
        cout<<-1;
    }
    cout<<endl;
}
int busqueda()
{
    while(!cola.empty())
    {
        Personajes aux =cola.front();
        cola.pop();
        for(int x=0; x<4; x++)
        {
            Personajes aux2 = aux;
            aux2.x+=arr[0][x];
            aux2.y+=arr[1][x];
            aux2.pasos++;
            if(mapa[aux2.y][aux2.x]== 'F')
            {
                return aux2.pasos;
            }
        }
        for(int x=0; x<4; x++)
        {
            Personajes aux2 = aux;
            aux2.x+=arr[0][x];
            aux2.y+=arr[1][x];
            aux2.pasos++;

            if(aux2.x >0 and aux2.y >0 and aux2.y<r and aux2.x<c)
                {
                    if(mapa[aux2.y][aux2.x] !='x' and mapa[aux2.y][aux2.x] != 'C' and mapa[aux2.y][aux2.x]!='B')
                    {
                        mapa[aux2.y][aux2.x] = 'x';
                        cola.push(aux2);
                    }
                }
        }
    }
    return -1;
}
