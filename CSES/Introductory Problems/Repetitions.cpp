#include <iostream>
using namespace std;

int main()
{
    string adn;
    getline(cin,adn);
    int lens = adn.length();
    int mayor =0;
    int cuenta=0;
    char acido;
    acido=adn[0];
    for(int x =0; x<lens; x++)
    {
        if(acido != adn[x])
        {
            cuenta =1;
            acido=adn[x];
        }else{
            cuenta++;
        }
        if(cuenta>mayor)
        {
            mayor = cuenta;
        }
    }
    cout<<mayor;
}
