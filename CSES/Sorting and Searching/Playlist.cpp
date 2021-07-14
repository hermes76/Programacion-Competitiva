#include <iostream>
#include <algorithm>
using namespace std;
struct Dato
{
    int valor;
    short int  activado=0;
};
int busqueda(int n, Dato arr[],int elemento, int *pos)
{
    int inicio=0;
    int fin=n-1;
    int medio;
    while(inicio<=fin)
    {
        medio=(inicio+fin)/2;
        if(arr[medio].valor==elemento)
        {
            *pos=medio;
            return 1;
        }
        if(arr[medio].valor>elemento)
        {
            fin=medio-1;
        }else if(arr[medio].valor<elemento)
        {
            inicio=medio+1;
        }
    }
    return 0;
}
void QuickSort(Dato arr[],int inicio, int fin)
{
    int i=inicio-1;
    int j=inicio;
    while(j<fin)
    {
        if(arr[j].valor<=arr[fin].valor)
        {
            i++;
            swap(arr[i].valor,arr[j].valor);
           // swap(arr[i].pos,arr[j].pos);
        }
        j++;
        if(j==fin)
        {
            swap(arr[i+1].valor,arr[fin].valor);
           // swap(arr[i+1].pos,arr[fin].pos);
            QuickSort(arr,i+1,fin);
            QuickSort(arr,inicio,i);
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    Dato aux[n];
    int pos=0;
    int cuenta=0;
    int mayor=0;
    int indice=0;
    int mator=0;
    for(int x=0; x<n; x++)
    {
        cin>>arr[x];
        if(arr[x]>mator)
        {
            mator=arr[x];
        }
        aux[x].valor=arr[x];
      // aux[x].pos=x;
    }
    if(mator<1000000)
    {
        short int poder[1000000];
        for(int x=0; x< 1000000; x++)
        {
            poder[x]=0;
        }
        for(int x =0; x<n; x++)
        {
            poder[arr[x]-1]++;
            if(poder[arr[x]-1]==2)
            {
                cuenta=x-indice;
                poder[arr[x]-1]=1;
                while(arr[indice]!=arr[x])
                {
                    poder[arr[indice]-1]=0;
                    indice++;
                 }
                 indice++;
                 if(cuenta>mayor)
                {
                    mayor=cuenta;
                }
            }
        }
    }else{
         QuickSort(aux,0,n-1);
        for(int x =0; x<n; x++)
        {
            busqueda(n,aux,arr[x],&pos);
            aux[pos].activado++;
            if(aux[pos].activado==2)
            {
                cuenta=x-indice;
                aux[pos].activado=1;
                while(arr[indice]!=arr[x]&&indice <n)
                {
                    busqueda(n,aux,arr[indice],&pos);
                    aux[pos].activado=0;
                    indice++;
                 }
                 indice++;
                 if(cuenta>mayor)
                {
                    mayor=cuenta;
                }
            }
        }
    }
    if(mayor<n-indice)
    {
        mayor=n-indice;
    }
    cout<<mayor;
}

