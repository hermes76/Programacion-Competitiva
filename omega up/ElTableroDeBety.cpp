#include <iostream>
using namespace std;
int n,m;
int matriz[100][100];
void arriba()
{
    int arr[m];
    for(int x=0; x<m; x++)
        arr[x]=matriz[0][x];
    for(int x=0; x<n-1; x++)
        for(int y=0; y<m; y++)
            matriz[x][y]=matriz[x+1][y];
    for(int x =0; x<m; x++)
        matriz[n-1][x]=arr[x];
}
void abajo()
{
    int arr[m];
    for(int x=0; x<m; x++)
        arr[x]=matriz[n-1][x];
    for(int x=n-1; x>=1; x--)
        for(int y=0; y<m; y++)
            matriz[x][y]=matriz[x-1][y];
    for(int x =0; x<m; x++)
        matriz[0][x]=arr[x];
}
void izquierda()
{
    int arr[m];
    for(int x=0; x<n; x++)
        arr[x]=matriz[x][0];
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            matriz[x][y]=matriz[x][y+1];
    for(int x =0; x<n; x++)
        matriz[x][m-1]=arr[x];
}
void derecha()
{
    int arr[m];
    for(int x=0; x<n; x++)
        arr[x]=matriz[x][m-1];
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            matriz[x][m-1-y]=matriz[x][m-2-y];
    for(int x =0; x<n; x++)
        matriz[x][0]=arr[x];
}
int main()
{
    int c;
    cin>>n>>m>>c;
    int operaciones[4]={0,0,0,0};
    int direcciones;
    for(int x=0; x<c; x++)
    {
        cin>>direcciones;
        operaciones[direcciones-1]++;
    }
    for(int x=0; x<n; x++)
    {
        for(int y =0; y<m; y++)
        {
            cin>>matriz[x][y];
        }
    }
    for(int x=0;x<4; x++)
        if(x<=1)operaciones[x]%n;
        else operaciones[x]%m;
    if(operaciones[0]>=operaciones[1]){operaciones[0]-=operaciones[1];operaciones[1]=0;}
    if(operaciones[0]<operaciones[1]){operaciones[1]-=operaciones[0];operaciones[0]=0;}
    if(operaciones[2]>=operaciones[3]){operaciones[2]-=operaciones[3];operaciones[3]=0;}
    if(operaciones[2]<operaciones[3]){operaciones[3]-=operaciones[2];operaciones[2]=0;}
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<operaciones[x]; y++)
        {
            if(x==0)arriba();
            if(x==1)abajo();
            if(x==2)izquierda();
            if(x==3)derecha();
        }
    }
    for(int x=0; x<n; x++)
    {
        for(int y =0; y<m; y++)
        {
            cout<<matriz[x][y]<<" ";
        }
        cout<<"\n";
    }
}
