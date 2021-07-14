#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int x =0; x<n; x++)cin>>arr[x];
    int a;
    cin>>a;
    int b;
    while(a--){cin>>b; cout<<arr[b-1]<<" ";}
}
