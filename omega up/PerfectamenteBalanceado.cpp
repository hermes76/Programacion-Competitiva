#include <iostream>
#define INF 1e11
#define ll long long int
using namespace std;
int n;
void cambiar(ll arr[], ll arrcopia[])
{
    for(int x=0; x<n; x++)
    {
        arr[x]=arrcopia[x];
    }
}
ll suma(ll arr[])
{
    ll diferencia =arr[1]-(arr[0]+1);
    ll operaciones=1;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll sumaV2(ll arr[])
{
    arr[1]++;
    ll diferencia =(arr[1])-arr[0];
    ll operaciones=1;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll sumaV3(ll arr[])
{
     arr[1]++;
     arr[0]++;
    ll diferencia =(arr[1])-arr[0];
    ll operaciones=2;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll sumaV4(ll arr[])
{
     arr[1]--;
     arr[0]++;
    ll diferencia =(arr[1])-arr[0];
    ll operaciones=2;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll resta(ll arr[])
{
    ll diferencia =arr[1]-(arr[0]-1);
    ll operaciones=1;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll restaV2(ll arr[])
{
    arr[1]--;
    ll diferencia =(arr[1])-arr[0];
    ll operaciones=1;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll restaV3(ll arr[])
{
    arr[0]--;
    arr[1]--;
    ll diferencia =(arr[1])-arr[0];
    ll operaciones=2;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll restaV4(ll arr[])
{
    arr[1]++;
    arr[0]--;
    ll diferencia =(arr[1])-arr[0];
    ll operaciones=2;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
ll neutral(ll arr[])
{
    ll diferencia =arr[1]-(arr[0]);
    ll operaciones=0;
    for(int x=2; x<n; x++)
    {
        if(arr[x]-arr[x-1]-1> diferencia or arr[x]-arr[x-1]+1<diferencia)
            return -1;
        else if(arr[x]-arr[x-1]> diferencia)
        {
            operaciones++;
            arr[x]--;
        }
        else if (arr[x]-arr[x-1]< diferencia)
        {
            operaciones++;
            arr[x]++;
        }

    }
    return operaciones;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll arr[n];
    ll arrcopia[n];
    ll operaciones;
    ll solucion=INF;
    for(int x=0; x<n; x++)
    {
        cin>>arr[x];
        arrcopia[x]=arr[x];
    }
    operaciones=neutral(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones=suma(arr);
    if( operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones= resta(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones= sumaV2(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones= restaV2(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);


    operaciones=sumaV3(arr);
    if( operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones= restaV3(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones= sumaV4(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);
    cambiar(arr,arrcopia);
    operaciones= restaV4(arr);
    if(operaciones!=-1)
        solucion=min(solucion,operaciones);
    if(solucion==INF)
        cout<<-1;
    else cout<<solucion;
}
