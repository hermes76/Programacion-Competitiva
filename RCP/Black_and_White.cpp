#include <iostream>
using namespace std;
char arr[24][24];
int comprobar(int n)
{
    int blancos=0;
    int negros=0;
    int ncon=0;
    int bcon=0;
    for(int x=0; x<n; x++)
    {
        for(int y =0; y<n; y++)
        {
            if(arr[x][y]=='B')
            {
                negros++;
                for(int z=1; z<=2 and y+z<n; z++)
                {
                   if(arr[x][y+z]=='B')
                   {
                       ncon++;
                   }
                }
                if(ncon==2)
                {
                    return 0;
                }
                ncon=0;
            }else if(arr[x][y]=='W')
            {
                blancos++;
                for(int z=1; z<=2 and y+z<n; z++)
                {
                   if(arr[x][y+z]=='W')
                   {
                       bcon++;
                   }
                }
                if(bcon==2)
                {
                    return 0;
                }
                bcon=0;
            }
            if(arr[y][x]=='B')
            { negros++;
            for(int z=1; z<=2 and y+z<n; z++)
                {
                   if(arr[y+z][x]=='B')
                   {
                       ncon++;
                   }
                }
                if(ncon==2)
                {
                    return 0;
                }
                ncon=0;}
            else if(arr[y][x]=='W')
            {
                blancos++;
                 for(int z=1; z<=2 and y+z<n; z++)
                {
                   if(arr[y+z][x]=='W')
                   {
                       bcon++;
                   }
                }
                if(bcon==2)
                {
                    return 0;
                }
                bcon=0;
            }
        }
        if(negros!=blancos)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int x =0; x<n; x++)
    {
        for(int y =0; y<n; y++)
        {
            cin>>arr[x][y];
        }
    }
    cout<<comprobar(n)<<endl;
}