#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int r,c,a,b;
    cin>>r>>c>>a>>b;
    int filas[a];
    int columnas[b];
    char pintar='B';
    string aux;
    string iaux;
    for(int x =0; x<a; x++)
    {
        cin>>filas[x];
    }
    for(int y=0; y<b; y++)
    {
        cin>>columnas[y];
    }
    for(int z=0; z<b; z++)
    {
        for(int ax=0; ax<columnas[z];ax++)
        {
            aux+=pintar;
        }
        if(pintar=='B')
        {
            pintar='W';
        }
        else if(pintar == 'W'){
            pintar='B';
        }
    }
    for(int x=0; x<c; x++)
    {
        if(aux[x]=='B')
        {
            iaux+='W';
        }else{
            iaux+='B';
        }
    }
    int num=0;
    for(int x =0; x<a; x++)
    {
        for(int y=0; y<filas[x]; y++)
        {
            if(num==0)
            {
                cout<<aux<<endl;
            }else{
                cout<<iaux<<endl;
            }
        }
        if(num==0)
        {
            num=1;
        }else{
            num=0;
        }
    }
}