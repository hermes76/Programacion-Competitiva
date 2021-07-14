#include <iostream>
#include <iomanip>
using namespace std;
bool ropes(int n, int k, int arr[], double pos)
{
    int suma=0;
    for(int x=0; x<n; x++)
    {
        suma += arr[x]/pos;
    }
    if(suma>=k)
        return 1;
    return 0;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int x=0; x<n; x++)cin>>arr[x];
    double res=0;
    for(double x=1e8; x>=0.0000001; x/=2)
    {
        while(ropes(n,k,arr,res+x))res+=x;
    }
    cout<<setprecision(9)<<res;
}
