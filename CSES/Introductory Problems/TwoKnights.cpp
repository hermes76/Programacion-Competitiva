#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    unsigned long int valor=0;
    int error=0;
    cin>>n;
    for(int x =1; x<=n; x++)
    {
        valor=pow(x,2) * (pow(x,2)-1)/2;
        if(x>1)
        {
            error+=8*(x-2);
        }
        valor-=error;
        cout<<valor<<endl;
    }
}

