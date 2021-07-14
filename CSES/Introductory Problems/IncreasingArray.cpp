#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int contador=0;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    for(int x =1; x<n; x++)
    {
        if(arr[x-1]>arr[x])
        {
            contador+= arr[x-1]-arr[x];
            arr[x] = arr[x-1];
        }
    }
    cout<<contador;
}
