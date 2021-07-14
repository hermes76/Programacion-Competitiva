#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long int arr[n];
    int botellas=0;
    for(int x=0; x<n; x++)cin>>arr[x];
    sort(arr,arr+n);
    for(int x=0; x<n; x++)
    {
        if(arr[x]<= arr[n/2] and arr[x]+k>= arr[n/2])
            botellas++;
    }
    cout<<botellas<<" "<<arr[n/2];
}
