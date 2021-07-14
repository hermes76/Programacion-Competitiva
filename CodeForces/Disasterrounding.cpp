#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long cuenta=1;
    int indice=2;
    int posicion=1;
    while(posicion+indice<=n)
    {
        cuenta+=round(sqrt(posicion))*indice;
        cuenta%=1000000007;
        posicion+=indice;
        indice+=2;
    }
    if(n>posicion)
    {
        cuenta+=round(sqrt(n))*(n-posicion);
        cuenta%=1000000007;
    }
    cout<<cuenta;
}
