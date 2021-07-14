#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int arr[n];
    long long int suma=0;
    long long int res;
    for(int x=0; x<n; x++){cin>>arr[x];suma+=arr[x];}
    sort(arr,arr+n,greater<int>());
    if(suma%2==1)
    {
        res=suma;
        suma=-1;
    }
    else
    {
        for(int x=n-1; x>=0; x--)
        {
            if(arr[x]%2==1)
            {
                res=suma-arr[x];
                suma=-1;
                break;
            }
        }
    }
    if(suma==-1)
        cout<<res;
    else
        cout<<0;

}
