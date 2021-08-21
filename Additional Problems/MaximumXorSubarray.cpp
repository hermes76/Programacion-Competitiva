#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int x=0; x<n; x++)cin>>arr[x];
    int A,R,B,C,p;
    B=0;
    A=0;
    R=0;
    for(int x =0; x<n; x++)
    {
        A=min(arr[x],arr[x]^A);
        B=max(arr[x],arr[x]^B);
    }
    //5 1 5 9
    cout<<R;

}
