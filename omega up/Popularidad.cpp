#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[1002];
    int b;
    int mayor=0;
    for(int x =0; x<1002; x++)
    {
        a[x] =0;
    }
    for(int x =0; x<n; x++)
    {
        cin>>b;
        a[b]++;
        if(mayor <a[b])
        {
            mayor= a[b];
        }
        cin>>b;
        a[b]++;
        if(mayor <a[b])
        {
            mayor= a[b];
        }
    }
    for(int x = 0; x<1002; x++ )
    {
        if(a[x] == mayor)
        {
            cout<<x<<endl;
        }
    }
}
