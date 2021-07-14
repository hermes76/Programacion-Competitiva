#include <iostream>
using namespace std;

int main()
{
    int equipos, dinero;
    cin>>equipos>>dinero;
    int problemas[equipos];
    int total=0;
    for(int x=0; x<equipos; x++)
    {
        cin>>problemas[x];
        total += problemas[x];
    }
    int particion = dinero/total;
    for(int x  =0; x<equipos; x++)
    {
        cout<<problemas[x]*particion<<endl;
    }
}
