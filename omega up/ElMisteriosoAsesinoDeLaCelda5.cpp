#include <iostream>
using namespace std;
bool arr[100][100];
int main()
{
    int filas,columnas;
    cin>>filas>>columnas;
    int c;
    cin>>c;
    int fi,co;
    int res=0;
    for(int x=0; x<c; x++)
    {
        cin>>fi>>co;
        arr[fi-1][co-1]=1;
    }
    for(int x=0; x<filas-1; x++)
    {
        for(int y=0;y<columnas-1; y++)
        {
            if(arr[x][y]==0 and arr[x+1][y]==0 and arr[x+1][y+1]==0 and arr[x][y+1]==0)
            {
                res++;
            }
        }
    }
    cout<<res;
}
