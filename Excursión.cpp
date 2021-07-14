#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    int a;
    for(int x=0; x<n; x++)cin>>arr[x];
    for(int x=0; x<m; x++){cin>>a;cout<<arr[a-1]<<endl;}
}
