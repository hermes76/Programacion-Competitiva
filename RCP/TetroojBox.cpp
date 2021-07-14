#include <iostream>
using namespace std;
bool arr[5000][100];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;

    int a,b,c;
    int res=0;
    int guar[m][3];
    bool r;

    for(int x=0; x<m; x++)
    {
        cin>>guar[x][0];
        cin>>guar[x][1];
        cin>>guar[x][2];
    }
    for(int x =0; x<m; x++)
    {
        a=guar[x][0];
        b=guar[x][1];
        c=guar[x][2];
        c--;
        int y=0;
        r=0;
        for(y; y<5000; y++)
        {
            for(int z=c; z<a+c; z++)
            {
                if(arr[y][z]){r=1;break;}
            }
            if(r)break;
        }
        y--;
        for(int h=0; h<b;h++)
        {
            for(int z=c; z<a+c; z++)
            {
                arr[y-h][z]=1;
            }
        }

    }
    for(int y=0; y<5000; y++)
    {
        for(int x=0; x<n; x++)
        {
            if(arr[y][x])
            {
                cout<<5000-y<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;

}
