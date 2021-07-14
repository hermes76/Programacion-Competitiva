#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    bool criba[100000];
    for(int x=0; x<100000; x++)criba[x]=0;
    int num;
    for(int x=2; x<=100000; x++)
    {
        if(criba[x])continue;
        for(int y=x*2; y<=100000; y+=x)
        {
            criba[y]=1;
        }
    }
    while(n--)
    {
        cin>>m;
        num=2;
        for(int x=2; x<100000;x++)
        {
            if(criba[x])
            {
                if(criba[(m-1)*(x)+1]==0)
                {
                    num=x;
                    break;
                }
            }
        }
        for(int x=0; x<m-1; x++)
        {
            for(int y=0; y<m-1; y++)
            {
                cout<<num<<" ";
            }
            cout<<1<<endl;
        }
        for(int x=0; x<m-1;x++)
        {
            cout<<1<<" ";
        }
        for(int x=2; x<100000;x++)
        {
            if(criba[x])
            {
                if(criba[(x)+(m-1)]==0)
                {
                    num=x;
                    break;
                }
            }
        }
        cout<<num<<endl;
    }
}
