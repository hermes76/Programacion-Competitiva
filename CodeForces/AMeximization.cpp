#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll caso;
    int aux[100];
    int indice;
    while(n--)
    {
        cin>>caso;
        ll arr[caso];
        indice=0;
        for(int x=0; x<caso; x++)cin>>arr[x];
        sort(arr,arr+caso);
        for(int x=1; x<caso; x++)
            if(arr[x-1]!=arr[x])
                cout<<arr[x-1]<<" ";
            else
            {
                aux[indice]=arr[x-1];
                indice++;
            }
        if(arr[caso-2]!=arr[caso-1])
            cout<<arr[caso-1]<<" ";
        else
            {
                aux[indice]=arr[caso-1];
                indice++;
            }
        for(int x=0; x<indice; x++)
            cout<<aux[x]<<" ";
         cout<<"\n";
    }
}
