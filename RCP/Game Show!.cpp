#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int saldo=100;
    int arr[n];
    for(int x=0; x<n; x++)cin>>arr[x];
    long long int res=100;
    for(int x=0; x<n; x++)
    {
        saldo+=arr[x];
        if(res<saldo)
            res=saldo;
    }
    cout<<res<<endl;
}
