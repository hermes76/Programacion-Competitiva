#include <iostream>
using namespace std;

int main()
{
    long long int m,n,p,a,res,mult,linea,col;
    cin>>m>>n>>p;
    mult=n*m-(n-1);
    for(int x=0; x<p; x++)
        {
            cin>>a;
            col=((a-1)%(m))*n;
            linea=(a-1)/(m);
            if(linea<0)
                linea=0;
            res=mult+linea-col;
            cout<<res<<' ';
        }

}
