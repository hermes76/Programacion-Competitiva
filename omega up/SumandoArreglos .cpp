#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int a;
    for(int x =0; x<n; x++)cin>>arr[x];
    for(int x=0; x<n; x++){cin>>a; cout<<a+arr[x]<<" ";}
}
