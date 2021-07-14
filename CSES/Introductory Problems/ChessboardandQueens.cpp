#include <iostream>
using namespace std;
char a[8][8];
int c=0;
int ejex[8]={1,1,0,-1,-1,-1,0,1};
int ejey[8]={0,1,1,1,0,-1,-1,-1};
bool D(int y,int x)
{
    if(a[y][x]!='.')
    {
        return 0;
    }
    for(int z=0; z<8; z++)
    {
        int ab=x;
        int b=y;
        ab+=ejex[z];
        b+=ejey[z];
        while(ab>=0 && ab<8 && b>=0 && b<8)
        {
           if(a[b][ab]=='R')
           {
               return 0;
           }

           ab+=ejex[z];
            b+=ejey[z];
        }
    }
    return 1;
}
void b(int x)
{
    if(x==8)
    {
        c++;
        return;
    }
    for(int z=0; z<8; z++)
    {
        if(D(z,x))
        {
            a[z][x]='R';
            b(x+1);
            a[z][x]='.';
        }
    }
}
int main()
{
    for(int x =0; x<8; x++)
    {
        for(int y =0; y<8; y++)
        {
            cin>>a[x][y];
        }
    }
    b(0);
    cout<<c;
}
