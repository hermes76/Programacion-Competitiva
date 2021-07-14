#include <iostream>
using namespace std;
int busqueda(int n, int arr[],int elemento)
{
    int inicio=0;
    int fin=n-1;
    int medio=0;
    while(inicio<=fin)
    {
        medio=(inicio+fin)/2;
        if(arr[medio]==elemento)
        {
            return medio;
        }
        if(arr[medio]>elemento)
        {
            fin=medio-1;
        }else if(arr[medio]<elemento)
        {
            inicio=medio+1;
        }
    }
    return medio;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int sumas[m];
    int res;
    int proc;
    int pos;
    int aux;
    cin>>sumas[0];
    for(int x =1; x<m; x++)
    {
        cin>>sumas[x];
        sumas[x]+=sumas[x-1];
    }
    for(int x=0; x<n; x++)
    {
        cin>>res;
        pos=busqueda(m,sumas,res);
        proc=res-sumas[pos];
        if(pos>0)
        {
            aux=res-sumas[pos-1];
            if(proc<aux && 0>proc)
            {
                pos--;
                proc=aux;
            }
        }
        cout<<pos+1<<" "<<proc<<"\n";
    }
}