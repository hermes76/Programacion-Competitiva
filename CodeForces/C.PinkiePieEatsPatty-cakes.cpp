#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a;
    int b;
    int mayor;
    int indice1;
    int indice2;
    int res;
    while(n--)
    {
        cin>>a;
        int arr[a];
        unordered_map<int,int> mapa;
        mayor=0;
        for(int x=0; x<a; x++)
        {
            cin>>b;
            mapa[b]++;
            mayor=max(mayor,mapa[b]);
        }
        res=a-2;
        if(mayor>2)
        {
            res=floor(a/mayor);
        }
        cout<<res<<endl;
    }
}
