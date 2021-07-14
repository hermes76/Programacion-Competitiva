#include <iostream>
using namespace std;

int main()
{
    int mayor;
    for(int x =0; x<5; x++)
    {
        int a;
        cin>>a;
        if(x==0)
        {
            mayor = a;
        }
        if(mayor<a and (a%2==1 or a%2==-1))
        {
            mayor = a;
        }
    }
    cout<<mayor;
}
