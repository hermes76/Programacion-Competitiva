#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    int minimo;
    while(n--)
    {
        cin>>m;
        int arr[m];
        for(int x=0; x<m; x++)cin>>arr[x];
        sort(arr,arr+m);
        minimo=arr[1]-arr[0];
        for(int x=1; x<m; x++)
        {
            minimo=min(arr[x]-arr[x-1],minimo);
        }
        cout<<minimo<<endl;
    }
}
