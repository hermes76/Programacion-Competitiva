#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int x =0; x<n; x++)cin>>arr[x];
    for(int x =0; x<n/2; x++)cout<<arr[x]+arr[n-1-x]<<" ";
}
