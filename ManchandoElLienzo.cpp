#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int lienzo[n][n];
     for(int x =0; x<n; x++)
    {
        for(int y =0; y<n; y++)
        {
        lienzo[x][y]=0;
        }
    }
    int posx[4] = {1,0,-1,0};
     int posy[4] = {0,1,0,-1};
    for(int x =0; x<m; x++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        lienzo[b][a] = c;
        for(int y=0; y<4; y++)
        {
            int dx =a+posx[y];
            int dy= b+posy[y];
            if(dx>=0 and dx <n and dy <n and dy>=0)
            {
                lienzo[dy][dx] = c;
            }
        }
    }
    for(int x =0; x<n; x++)
    {
        for(int y =0; y<n; y++)
        {
            cout<<lienzo[x][y]<<" ";
        }
        cout<<endl;
    }

}
