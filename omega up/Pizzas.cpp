#include <iostream>
using namespace std;

int main()
{
    int p,g,c;
    cin>>p>>g>>c;
    int pizza=c;
    if(p>c)
        p-=c;
    else p=0;
    pizza+=g/2;
    g%=2;
    if(g==1)
    {
        pizza++;
        p-=2;
    }
    if(p>0)
    {
        pizza+=p/4;
        p%=4;
        if(p>0)
        pizza++;
    }
    cout<<pizza;
}
