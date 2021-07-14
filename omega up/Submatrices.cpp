#include <iostream>

using namespace std;

int main()
{
    int ren,col,r,c;
    bool salir;
    cin>>ren>>col;
    int arr[ren][col];
    bool arrbool[ren][col];
    for(int x=0; x<ren; x++)
    {
        for(int y=0; y<col; y++)
        {
            cin>>arr[x][y];
            arrbool[x][y]=0;
        }
    }
    cin>>r>>c;
    int m[r][c];
    for(int x=0; x<r; x++)
    {
        for(int y=0; y<c; y++)
        {
            cin>>m[x][y];
        }
    }
    for(int x=0; x<ren; x++)
    {
        for(int y=0; y<col; y++)
        {
            salir=0;
            if(x+r<=ren and y+c<= col)
            {
                for(int z=0; z<r and salir!=1; z++)
                {
                    for(int a=0; a<c and salir!=1; a++)
                    {
                        if(m[z][a]!=arr[x+z][y+a])
                            salir=1;
                    }
                }
                if(!salir)
                {
                    for(int z=0; z<r; z++)
                    {
                        for(int a=0; a<c; a++)
                        {
                            arrbool[x+z][y+a]=1;
                        }
                    }
                }
            }
        }
    }
    for(int z=0; z<ren; z++)
    {
        for(int a=0; a<col; a++)
        {
            cout<<arrbool[z][a]<<" ";
        }
        cout<<"\n";
    }
}
