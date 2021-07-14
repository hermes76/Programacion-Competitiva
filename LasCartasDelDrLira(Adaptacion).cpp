#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    for(int x =0; x<n; x++)cin>>arr[x];
    for(int x =0; x<n; x++)arr2[x]=arr[x];
    int mejor=10000000;
    int res=0;
    for(int x=0; x<n; x++)if(arr[x]==0 and x%2==0)res++; else if(arr[x]==1 and x%2==1)res++;
    mejor=res;
    res=0;
    for(int x =0; x<n; x++)arr2[x]=arr[x];
    for(int x=0; x<n; x++)if(arr[x]==0 and x%2==1)res++; else if(arr[x]==1 and x%2==0)res++;
    mejor=min(mejor,res);
    cout<<mejor;

}
