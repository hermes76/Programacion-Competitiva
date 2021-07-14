#include <iostream>
#include <queue>
using namespace std;
struct coordenadas
{
    int x;
    int y;
};
queue <coordenadas> cola;
short int arr[50][50];
int cuartos=0;
int posx[4]={0,1,0,-1};
int posy[4]={1,0,-1,0};
bool visitados[50][50];
int cuartosmem[100];
char direccion;
int ContarCuartos(int r,int c)
{
    int maximo=1;
    coordenadas aux;
    int pos=8;
    while(!cola.empty())
    {
        coordenadas uno;
        uno=cola.front();
        cola.pop();
        for(int x =0; x<4; x++)
        {
            if(arr[uno.y][uno.x]>=pos)
            {
                arr[uno.y][uno.x]-=pos;
            }else{
                aux.x=uno.x+posx[x];
                aux.y=uno.y+posy[x];
                if(aux.x>=0 and aux.x<c and aux.y>=0 and aux.y<r and visitados[aux.y][aux.x]==0)
                {
                    cola.push(aux);
                    arr[aux.y][aux.x]=cuartos+1;
                    visitados[aux.y][aux.x]=1;
                    maximo++;
                }
            }
            pos/=2;
        }
        pos=8;
    }
    cuartos++;
    return maximo;
}
coordenadas MaximizarCuartos(int r,int c)
{
    coordenadas res;
    coordenadas uno;
    coordenadas aux;
    uno.x=0;
    uno.y=0;
    int maximo=0;
    int presente,futuro;
    cola.push(uno);
    while(!cola.empty())
    {
        uno= cola.front();
        cola.pop();
        for(int x =0; x<2; x++)
        {
            aux.x=uno.x+posx[x];
            aux.y=uno.y+posy[x];
            if(aux.x>=0 and aux.x<c and aux.y>=0 and aux.y<r)
            {
                cola.push(aux);
                presente= arr[uno.y][uno.x]-1;
                futuro=arr[aux.y][aux.x]-1;
                if(presente!= futuro)
                {
                    if(maximo<cuartosmem[presente]+cuartosmem[futuro])
                    {
                        maximo=cuartosmem[presente]+cuartosmem[futuro];
                        res.x= uno.x+1;
                        res.y=uno.y+1;
                        if(uno.x<aux.x)
                        {
                            direccion = 'E';
                        }else if(uno.y<aux.y)
                        {
                            direccion = 'S';
                        }
                        else if (uno.x>aux.x)
                        {
                            direccion= 'W';
                        }else if ( uno.y > aux.y){
                            direccion='N';
                        }
                        
                    }
                }
            }
        }
    }
    return res;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int r,c;
    int mayor=0;
    cin>>r>>c;
    coordenadas prueba;
    for(int x =0; x<r; x++)
    {
        for(int y=0; y<c; y++)
        {
            cin>>arr[x][y];
        }
    }
    for(int y =0; y<r; y++)
    {
        for(int x =0; x<c; x++)
        {
            if(visitados[y][x]==0)
            {
                prueba.x=x;
                prueba.y=y;
                cola.push(prueba);
                arr[y][x]=cuartos+1;
                cuartosmem[cuartos]=ContarCuartos(r,c);
               mayor=max( cuartosmem[cuartos-1],mayor);
            }
        }
    }
    prueba=MaximizarCuartos(r,c);
    cout<<cuartos<<" "<<mayor<<endl;
    cout<<prueba.y<<" "<<prueba.x<<" "<<direccion;
}