#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int m;
    int mina;
    int minb;
    long long int cuenta=0;
    for(int x=0; x<n; x++)
    {
        cin>>m;
        int a[m];
        int b[m];
        mina=1000000000;
        minb=1000000000;
        for(int y=0; y<m; y++)
        {
            cin>>a[y];
            mina=min(a[y],mina);
        }
        for(int y=0; y<m; y++)
        {
            cin>>b[y];
            minb=min(b[y],minb);
        }
        cuenta=0;
        int aux;
        for(int y=0; y<m; y++)
        {
            if(a[y]>mina and b[y]>minb)
            {
                aux=min(a[y]-mina,b[y]-minb);
                cuenta+=min(a[y]-mina,b[y]-minb);
                a[y]-=aux;
                b[y]-=aux;
            }

            if(a[y]>mina)
            {
                cuenta+=a[y]-mina;
                a[y]-=mina;
            }
            if(b[y]>minb)
            {
                cuenta+=b[y]-minb;
                b[y]-=minb;
            }
        }
        cout<<cuenta<<endl;

    }
}
