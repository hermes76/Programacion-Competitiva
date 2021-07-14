#include <iostream>
#include <map>
using namespace std;
int fil[6]={-1,-1,0,0,1,1};
int col[6]={-1,0,-1,1,0,1};
int aux;
int m;
int pasos[2][100000];
int acabar=0;
//map <<int, int>> mapeo; 
int pascal(int r,int k)
{
    int res=1;
    for(int n=r; n>k; n--)
    {
        res*=n;
    }
    int div=1;
    for(int n=1; n<=r-k; n++)
    {
        div*=n;
    }
    return res/div;
}
void busqueda(int r,int k,int sum,int indice)
{
    if(acabar==0)
    {
        if(sum>=m)
        {
            acabar=1;
            for(int x =0; x<indice; x++)
            {
                cout<<pasos[0][x]<<" "<<pasos[1][x]<<endl;
            }
            return;
        }
        for(int x =0; x<6; x++)
        {
            if(r+fil[x]>=1 and k+col[x]>=1)
            {
                
                aux=pascal(r+fil[x],k+col[x]);
                if(aux+sum<=m)
                {
                    pasos[0][indice]=r+fil[x];
                    pasos[1][indice]=k+col[x];
                    busqueda(r+fil[x],k+col[x],aux+sum,indice+1);
                }
            }
        }
    }
    return;
}
int main()
{   
    int n;
    cin>>n;
    for(int x=0; x<n; x++)
    {
        cin>>m;
        acabar=0;
        busqueda(0,0,0,0);
    }
}