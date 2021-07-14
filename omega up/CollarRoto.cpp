#include <iostream>
using namespace std;
int n,m;
string cad;
int solve()
{
    m*=2;
    char l;
    int cuenta;
    int res=0;
    int y;
    for(int x=0; x<m; x++)
    {
        l='.';
        y=x;
        cuenta=0;
        for(y; y<m; y++)
        {
            if(l=='.')
            {
                if(cad[y]!='w')
                    l=cad[y];
            }
            if(cad[y]==l or cad[y]=='w')cuenta++;
            else break;
        }
        if(l=='b')
            l='r';
        else l='b';
        for(y; y<m; y++)
        {
            if(cad[y]==l or cad[y]=='w')cuenta++;
            else break;
        }
        res=max(res,cuenta);
    }
    return res;
}
int main()
{
    cin>>n;
    int p[n];
    for(int x=0;x<n; x++)
    {
        cin>>m;
        cin>>cad;
        cad+=cad;
        p[x]=solve();
    }
    for(int x=0; x<n; x++)cout<<p[x]<<" ";

}
