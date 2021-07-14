#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a;
    int res;
    //int indice1=0;
     int cuenta=0;
    //int indice2=0;
    for(int x=0; x<n; x++)
    {
        cuenta=0;
        cin>>a;
        cuenta=round(a/2.0);
        if(a%2==0)
        {
            cuenta=a/2+1;
        }
        cout<<cuenta<<endl;
    }
}
