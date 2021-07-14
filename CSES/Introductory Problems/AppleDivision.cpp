#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    long long int cuenta=0;
    long long res=0;
    long long int mitad=0;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
        mitad+=arr[x];
    }
    for(int x =0; x<(1<<n); x++)
    {
        cuenta=0;
        for(int y=0; y<n; y++)
        {
            if(x&(1<<y))
            {
                cuenta+=arr[y];
            }
        }
        if(cuenta<=(mitad/2)) res=max(res,cuenta);
    }
    cout<<mitad-2*res;
}
