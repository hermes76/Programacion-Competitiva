#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    long long int fuerzas=0;
    for(int x=0; x<n; x++)cin>>arr[x];
    for(int x=0; x<n; x++)cin>>arr2[x];
    sort(arr,arr+n,greater<int>());
    sort(arr2,arr2+n,greater<int>());
    int y=0;
    for(int x=0; x<n; x++)
    {
        for(y; y<n; y++)if(arr[x]>arr2[y]){fuerzas+=arr[x]; break;}
        y++;
    }
    cout<<fuerzas;
}
