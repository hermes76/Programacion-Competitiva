#include <iostream>
#include <algorithm>
#define INF 10e8
using namespace std;
int Izquierda(int A, int B, int elemento, int arr[])
{
    int CalculoMedio;
    int ResMedio;
    int inicio=A;
    int fin=B;
    ResMedio=INF;
    while(inicio<=fin)
    {
        CalculoMedio = (inicio+fin)/2;
        if(arr[CalculoMedio]==elemento){ResMedio=min(ResMedio,CalculoMedio); fin=CalculoMedio-1;}
        else if(arr[CalculoMedio]<elemento)inicio=CalculoMedio+1;
        else if (arr[CalculoMedio]>=elemento){ResMedio=min(ResMedio,CalculoMedio);fin=CalculoMedio-1;}
    }
    if(ResMedio==INF)
        ResMedio=-1;
    return ResMedio;

}
int Derecha(int A, int B, int elemento, int arr[])
{
    int CalculoMedio;
    int ResMedio;
    int inicio=A;
    int fin=B;
    ResMedio=-1;
    while(inicio<=fin)
    {
        CalculoMedio = (inicio+fin)/2;
        if(arr[CalculoMedio]==elemento){ResMedio=max(ResMedio,CalculoMedio); inicio=CalculoMedio+1;}
        else if(arr[CalculoMedio]<elemento){ResMedio=max(ResMedio,CalculoMedio);inicio=CalculoMedio+1;}
        else if (arr[CalculoMedio]>=elemento)fin=CalculoMedio-1;
    }
    return ResMedio;

}
int main()
{
    int n,m,a,b;
    cin>>n;
    int arr[n];
    for(int x=0; x<n; x++)cin>>arr[x];
    cin>>m;
    sort(arr,arr+n);
    int solveA,solveB;
    while(m--)
    {
        cin>>a>>b;
        solveA=Derecha(0,n-1,b,arr);
        solveB=Izquierda(0,n-1,a,arr);
        if(solveB==-1 or solveA==-1)
            cout<<0<<endl;
        else
        cout<<Derecha(0,n-1,b,arr)+1-Izquierda(0,n-1,a,arr)<<endl;
    }
}
