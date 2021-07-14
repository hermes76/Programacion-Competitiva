#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int n;
    int indice,ini=0;
    cin>>n;
    int arr[n];
    for(int x =0; x<n; x++)cin>>arr[x];
    sort(arr,arr+n,greater<int>());
    indice=arr[0]-arr[1];
    ini=0;
    for(int x =0; x<n-1; x++)
    {
        if(abs(arr[x]-arr[x+1])<indice)
        {
            swap(arr[ini],arr[x+2]);
            ini=x+2;
        }
    }
    for(int x =0; x<n; x++) cout<<arr[x];
}
