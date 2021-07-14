#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int indice=1;
    int bajar=0;
    for(int x =0; x<n; x++)
    {
        cout<<indice<<" ";
        if(bajar==0)
        {
            indice++;
        }
        else
        {
            indice--;
        }
        if(indice==5)
        {
            bajar=1;
        }
        if(indice==1)
        {
            bajar=0;
        }
        
    }
}