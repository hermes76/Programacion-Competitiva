#include <iostream>
#include <algorithm>
using namespace std;
int cuenta=0;
int arr[4];
bool a[4];
void re(int posicion,int indice,int suma)
{
    if(posicion==3)
    {
        cuenta=max(cuenta,suma);
        return;
    }else{
        for(int x=0; x<4; x++)
        {
            if(a[x]==0)
            {
            suma+=arr[x];
            a[x]=1;
            re(posicion+1,indice+1,suma);
            suma-=arr[x];
            a[x]=0;
            }
        }
    }
}
int main()
{

    int h;
    for(int x =0; x<4; x++)
    {
        cin>>arr[x];
    }
    cin>>h;
    re(0,0,0);
    if(cuenta<h)
    {
        cout<<"AWW";
    }else{
        cout<<"WAW";
    }
}

