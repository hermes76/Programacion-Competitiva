#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long int b;
    cin>>n>>b;
    long long int arr[n];
    long long int minimo;
    long long int mayor;
    long long int mult;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    minimo=min(arr[n-1],arr[1]);
    mayor=max(arr[n-1],arr[1]);
    if((arr[n-1]<arr[0] and arr[1]>arr[0])or(arr[n-1]>arr[0] and arr[1]<arr[0]) or (arr[n-1]==arr[1] and arr[0]>arr[n-1]))
    arr[0]=minimo+1;
    else if(arr[0]> arr[n-1] and arr[0]> arr[1])
    arr[0]=mayor+1;
    for(int x =1; x+1<n; x++)
    {
        minimo=min(arr[x-1],arr[x+1]);
        mayor=max(arr[x-1],arr[x+1]);
         if((arr[x-1]<arr[x] and arr[x+1]>arr[x])or(arr[x-1]>arr[x] and arr[x+1]<arr[x])or (arr[x-1]==arr[x+1]and arr[x]>arr[x-1]))
        arr[x]=minimo+1;
         else if(arr[x]> arr[x-1] and arr[x]> arr[x+1])
        arr[x]=mayor+1;
    }
    minimo=min(arr[n-2],arr[0]);
    mayor=max(arr[n-2],arr[0]);
     if((arr[n-2]<arr[n-1] and arr[0]>arr[n-1])or(arr[n-2]>arr[n-1] and arr[0]<arr[n-1])or (arr[n-2]==arr[0] and arr[n-1]>arr[n-2]))
    arr[n-1]=minimo+1;
    else if(arr[n-1]> arr[n-2] and arr[n-1]> arr[0])
        arr[n-1]=mayor+1;
    for(int x=0; x<n-1; x++)
    {
        mult=arr[x]*b;
        cout<<mult<<" ";
    }
    mult=arr[n-1]*b;
    cout<<mult;
    cout<<endl;
}
