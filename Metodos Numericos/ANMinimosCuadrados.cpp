#include <iostream>
#include <cmath>
//num de columnas
#define N 6
//num de filas
#define N2 2
#define Vez 5
using namespace std;
void Reset(double Res[N][N+1]);
void MinimosCuadrados(double arr[N2][N],double Res[N][N+1], int IndiceX, int IndiceY);
void Imprimir(double Res[N][N+1],int IndiceX, int IndiceY);
void GaussJordan(double zigmas[N][N+1],int IndiceX, int IndiceY);
int main()
{
    //primero x y depsues ys
    double arr[N2][N]={1,2,4,5,10,16,
                        6,1,2,3,4,5};
    double Res[N][N+1];
    int IndiceX=2,IndiceY=2;
    for(int x=0; x<Vez; x++)
    {
        Reset(Res);
        MinimosCuadrados(arr,Res,IndiceX,IndiceY);
        GaussJordan(Res,IndiceX+1,IndiceY);
        Imprimir(Res,IndiceX+1,IndiceY);
        IndiceX++;
        IndiceY++;
    }

}
void Imprimir(double Res[N][N+1],int IndiceX, int IndiceY)
{
    double aux;
    for(int x =0; x<IndiceY; x++)
    {
        for(int y =0; y<IndiceX; y++)
        {
            aux=Res[x][y];
            cout<<aux<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Reset(double Res[N][N+1])
{
     for(int x =0; x<N; x++)
    {
        for(int y =0; y<N+1; y++)
        {
            Res[x][y]=0;
        }
    }
}
void MinimosCuadrados(double arr[N2][N],double Res[N][N+1], int IndiceX, int IndiceY)
{
    for(int x =0; x<IndiceY; x++)
    {
        for(int y =0; y<IndiceX; y++)
        {
            if(x==0 and y==0)
            {
                Res[0][0] = N;
            }else{
                for(int z=0; z<N; z++)
                {
                    Res[x][y] += pow(arr[0][z],y+x);
                }
            }
        }
    }
    for(int x=0; x<IndiceY; x++)
    {
        for(int y =0; y<N; y++)
        {
           Res[x][IndiceX] += pow(arr[0][y],x)*arr[1][y];
        }
    }
    Imprimir(Res,IndiceX+1,IndiceY);
}
void GaussJordan(double zigmas[N][N+1],int IndiceX, int IndiceY)
{
    double dividir=0;
    double aux=0;
     for(int x =0; x<IndiceY; x++)
    {
        if(zigmas[x][x] !=0)
        {
            if(zigmas[x][x] !=1)
            {
                dividir=zigmas[x][x];
                for(int y=0; y<IndiceX; y++)
                {
                    zigmas[x][y]/=dividir;
                }
            }
            for(int y=0; y<x; y++)
            {
                dividir=zigmas[y][x];
                aux=zigmas[y][x];
                if(zigmas[y][x]<0)
                {
                    dividir*=-1;
                }
                for(int z=0; z<IndiceX; z++)
                {
                   if(aux<0)
                    {
                     zigmas[y][z]+=dividir*zigmas[x][z];
                    }else{
                        zigmas[y][z]-=dividir*zigmas[x][z];
                    }
                   if(abs(zigmas[y][z])<.000005)
                    {
                        zigmas[y][z]=0;
                    }
                }
            }
            for(int y=x+1; y<IndiceY; y++)
            {
                dividir=zigmas[y][x];
                aux=zigmas[y][x];
                 if(zigmas[y][x]<0)
                {
                    dividir*=-1;
                }
                for(int z=0; z<IndiceX; z++)
                {
                    if(aux<0)
                    {
                     zigmas[y][z]+=dividir*zigmas[x][z];
                    }else{
                        zigmas[y][z]-=dividir*zigmas[x][z];
                    }
                     if(abs(zigmas[y][z])<.000005)
                    {
                        zigmas[y][z]=0;
                    }
                }
            }
            Imprimir(zigmas,IndiceX,IndiceY);
        }else{
            cout<<endl;
            cout<<"tiene infinitas soluciones";
        }
    }
}
