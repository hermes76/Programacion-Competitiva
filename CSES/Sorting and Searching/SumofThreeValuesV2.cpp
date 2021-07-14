#include <iostream>
using namespace std;
struct Datos{
    int valor;
    int posicion;
};
int busqueda(int init,int n, Datos arr[],int elemento)
{
    int inicio=init;
    int fin=n-1;
    int medio;
    while(inicio<=fin)
    {
        medio=(inicio+fin)/2;
        if(arr[medio].valor==elemento)
        {
            return medio;
        }
        if(arr[medio].valor>elemento)
        {
            fin=medio-1;
        }else if(arr[medio].valor<elemento)
        {
            inicio=medio+1;
        }
    }
    return -1;
}
void QuickSort(Datos arr[],int inicio, int fin)
{
    int i=inicio-1;
    int j=inicio;
    while(j<fin)
    {
        if(arr[j].valor<=arr[fin].valor)
        {
            i++;
            swap(arr[i].valor,arr[j].valor);
            swap(arr[i].posicion,arr[j].posicion);
        }
        j++;
        if(j==fin)
        {
            swap(arr[i+1].valor,arr[fin].valor);
            swap(arr[i+1].posicion,arr[fin].posicion);
            QuickSort(arr,i+1,fin);
            QuickSort(arr,inicio,i);
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,s;
    cin>>n>>s;
    Datos arr[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x].valor;
        arr[x].posicion=x;
    }
    QuickSort(arr,0,n-1);
    int indice=0;
    int indice2;
    int p;
    for(int x =0; x<n && arr[x].valor<=s/4; x++)
    {
        indice=x+1;
        while(arr[x].valor<=(s-arr[indice].valor)/2)
        {
            indice2=indice+1;
            while(arr[x].valor+arr[indice].valor<s-arr[indice2].valor)
            {
                p= busqueda(indice2+1,n,arr,s-(arr[x].valor+arr[indice].valor+arr[indice2].valor));
                if(p>indice2)
                {
                    cout<<arr[x].posicion+1<<" "<<arr[indice].posicion+1<<" "<<arr[indice2].posicion+1<<" "<<arr[p].posicion+1;
                    return 0;
                }
                indice2++;
            }
            indice++;
        }

    }
cout<<"IMPOSSIBLE";
}
