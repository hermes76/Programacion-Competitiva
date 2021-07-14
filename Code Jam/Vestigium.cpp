#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int m;
    int aux;
    int llave;
    int cont;
    int suma;
    int contcol;
    for(int x=0; x<n; x++)
    {
        cin>>m;
        int arr[m][m];
        bool ex[m];
        cont=0;
        for(int y=0; y<m; y++)
        {
            llave=0;
            for(int f=0; f<m; f++)
            {
                ex[f]=0;
            }
            for(int z =0; z<m; z++)
            {
                cin>>aux;
                arr[y][z]=aux;
                if(ex[aux-1]==1 and llave==0)
                {
                    cont++;
                    llave=1;
                }
                ex[aux-1]=1;

            }
        }
        suma=0;
        contcol=0;
            for(int y=0; y<m; y++)
            {
                llave=0;
                for(int f=0; f<m; f++)
                {
                    ex[f]=0;
                }
                suma+=arr[y][y];
                for(int z=0; z<m; z++)
                {
                    if(ex[arr[z][y]-1]==1 and llave==0)
                    {
                        contcol++;
                        llave=1;
                    }
                    ex[arr[z][y]-1]=1;
                }
            }
        cout<<"Case #"<<x+1<<": "<<suma<<" "<<cont<<" "<<contcol<<endl;
    }
}
