#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Datos{
    int valor;
    int posicion;
};
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int s;
    cin>>n>>s;
    vector <pair<int,int>>arr (n);
    for(int x =0; x<n; x++)
    {
        cin>>arr[x].first;
        arr[x].second=x+1;
    }
    sort(arr.begin(),arr.end());
    int inicio;
    int fin;
    int elemento;
    int medio;
    int indice;
    bool res=0;
    for(int x =0; x<n; x++)
    {
       /* while(arr[x].first==arr[x+1].first && x+1<n)
        {
            x++;
        }*/
         inicio=x+1;
         fin=n-1;
         medio;
        elemento=s-arr[x].first;
         while(inicio<=fin)
        {
            medio=(inicio+fin)/2;
            if(arr[medio].first==elemento)
            {
                if(medio!=x)
                {
                    indice=x;
                    res=1;
                    break;

                }
            }
            if(arr[medio].first>elemento)
            {
                fin=medio-1;
            }else if(arr[medio].first<elemento)
            {
                inicio=medio+1;
            }
        }
        if(res==1)
        {
            break;
        }
    }
    if(res)
    {
         cout<<arr[indice].second<<" "<<arr[medio].second;
    }else{
        cout<<"IMPOSSIBLE";
    }
}
