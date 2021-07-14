#include <iostream>
using namespace std;
int main()
{
    string cad;
    getline(cin,cad);
    int suma=0;
    for(int x =0; x<cad.length(); x++)
    {
        suma+=cad[x]-48;
    }
    cout<<suma;
}