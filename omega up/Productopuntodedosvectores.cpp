#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    long long int cuenta=0;
    int a;
    for(int x=0;x<n; x++)cin>>arr[x];
    for(int x =0; x<n; x++){cin>>a; cuenta+=a*arr[x];}
    cout<<cuenta;
}
