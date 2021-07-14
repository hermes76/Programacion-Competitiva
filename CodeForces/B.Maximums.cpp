#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int ord[n];
    int maxi=0;
    int indice=0;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
        ord[x]=arr[x];
    }

    for(int x=0; x<n; x++)
    {
        arr[x]+=maxi;
        cout<<arr[x]<<" ";
        maxi=max(arr[x],maxi);
    }
}
