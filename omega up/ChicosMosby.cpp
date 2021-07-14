#include <iostream>
using namespace std;

int main()
{
    int n,m;
    int solucion=0;
    cin>>n>>m;
    while(n>0 and m>0)
    {
        if(min(m,n)==m)
        {
            solucion+=n/m;
            n%=m;
        }else
        {
            solucion+=m/n;
            m%=n;
        }
    }
    cout<<solucion;
}
