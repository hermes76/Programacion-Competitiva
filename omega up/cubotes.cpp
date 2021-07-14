#include <iostream>
using namespace std;
#define MAX 1e15
unsigned long long int arr[6];
unsigned long long int mini(unsigned long long int a,unsigned long long int b)
{
    if(a<b)
        return a;
    else
        return b;
}
unsigned long long int maxi(unsigned long long int a,unsigned long long int b)
{
    if(a>b)
        return a;
    else
        return b;
}
unsigned long long int duplas(int cara)
{
    unsigned long long int minimo=MAX;
    for(int x=0; x<6; x++)
        if(cara!=x and x!=5-cara)
            minimo=mini(minimo,arr[cara]+arr[x]);
    return minimo;
}
unsigned long long int triples(int cara)
{
    unsigned long long int minimo=MAX;
    for(int x=0; x<6; x++)
    {
        if(x!=5-cara and cara!=x and x!=2 and x!= 3)
        {
            minimo=mini(minimo,arr[cara]+arr[x]+arr[2]);
            minimo=mini(minimo,arr[cara]+arr[x]+arr[3]);
        }
    }
    return minimo;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    unsigned long long int medios=MAX;
    unsigned long long int esquinas=MAX;
    unsigned long long int minimo=MAX;
    unsigned long long int solucion=0;
    unsigned long long int maximo=0;
    cin>>n;
    for(int x=0; x<6; x++) cin>>arr[x];
    for(int x=0; x<6; x++)minimo=mini(minimo,arr[x]);
    for(int x=0; x<6; x++)maximo=maxi(maximo,arr[x]);
    for(int x=0; x<6; x++)
    {
        medios=mini(medios,duplas(x));
        if(x!=2 and x!= 3)
        esquinas=mini(esquinas,triples(x));
    }
    solucion=esquinas*4+medios*4+((n-2)*medios*8);
    if(n>2)
    {
        solucion+=((n-2)*(n-1))*minimo*4;
        solucion+=(n-2)*(n-2)*minimo;
    }
    if(n==1)
    {
        solucion=0;
        for(int x=0; x<6; x++)solucion+=arr[x];
        solucion-=maximo;
    }
    if(n<=0)
    {
        solucion=0;
    }
    cout<<solucion;
}
