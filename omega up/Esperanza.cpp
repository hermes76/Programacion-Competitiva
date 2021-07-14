#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arriba=0;
    int abajo=0;
    int derecha=0;
    int izquierda=0;
    char c;
    for(int x=0; x<n; x++)
    {
        cin>>c;
        if(c=='U')
        {
            arriba++;
        }
        if(c=='L')
        {
            izquierda++;
        }
        if(c=='R')
        {
            derecha++;
        }
        if(c=='D')
        {
            abajo++;
        }
    }
    if((abajo-arriba)*(izquierda-derecha)<0)
    {
        cout<<"S";
    }
    else if((arriba-abajo)*(izquierda-derecha)<0)
    {
        cout<<"S";
    }else{
        cout<<"N";
    }
}