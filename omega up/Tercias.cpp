#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,tercias;
    cin>>n;
    int arr[n];
    tercias=0;
    for(int x=0; x<n; x++)cin>>arr[x];
    for(int x=n-2; x>=1; x--)
    {
        for(int y=x+1; y<n and arr[y]<=(arr[x]<<1); y++)
        {
            if(binary_search(arr,arr+n, arr[x]-(arr[y]-arr[x])))
                tercias++;
        }
    }
    cout<<tercias;
}
