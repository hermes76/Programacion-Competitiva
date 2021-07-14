#include <iostream>
#include <algorithm>
using namespace std;
int cuenta=0;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
        arr2[x]=arr[x];
    }
    sort(arr,arr+n);
    for(int x=0; x<n; x++)
    {
        for(int y=x; y<n; y++)
        {
            if((arr[x]==arr2[y]) &&(x!=y) )
            {
                swap(arr2[x],arr2[y]);
                cuenta++;
            }
        }
    }
    cout<<cuenta;


}
