#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int suma=0;
    for(int x =0; x<n; x++)
    {
        suma+=n/pow(2,x);
    }
    cout<<suma;
}