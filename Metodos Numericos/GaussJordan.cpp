#include <iostream>
#include <cmath>
#define n 2
#define n2 3
using namespace std;

int main()
{
    //num de filas
    //n,n+1
    float zigmas[n][n2]={5.33334,2,4.69446889,-8.33334,8.16666,-9.03472278};
    float dividir=0;
    float aux;
    for(int x =0; x<n; x++)
        {
             for(int y =0; y<n2; y++)
            {
                cout<<zigmas[x][y]<<" ";
            }
            cout<<endl;
        }
    for(int x =0; x<n; x++)
    {
        if(zigmas[x][x] !=0)
        {
            if(zigmas[x][x] !=1)
            {
                dividir=zigmas[x][x];
                for(int y=0; y<n2; y++)
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
                for(int z=0; z<n2; z++)
                {
                   if(aux<0)
                    {
                     zigmas[y][z]+=dividir*zigmas[x][z];
                    }else{
                        zigmas[y][z]-=dividir*zigmas[x][z];
                    }
                   if(abs(zigmas[y][z])<.0005)
                    {
                        zigmas[y][z]=0;
                    }
                }
            }
            for(int y=x+1; y<n; y++)
            {
                dividir=zigmas[y][x];
                aux=zigmas[y][x];
                 if(zigmas[y][x]<0)
                {
                    dividir*=-1;
                }
                for(int z=0; z<n2; z++)
                {
                    if(aux<0)
                    {
                     zigmas[y][z]+=dividir*zigmas[x][z];
                    }else{
                        zigmas[y][z]-=dividir*zigmas[x][z];
                    }
                     if(abs(zigmas[y][z])<.0005)
                    {
                        zigmas[y][z]=0;
                    }
                }
            }
            cout<<endl;
            for(int x =0; x<n; x++)
        {
             for(int y =0; y<n2; y++)
            {
                cout<<zigmas[x][y]<<" ";
            }
            cout<<endl;
        }
        }else{
            cout<<endl;
            cout<<"tiene infinitas soluciones";
        }
    }
}

