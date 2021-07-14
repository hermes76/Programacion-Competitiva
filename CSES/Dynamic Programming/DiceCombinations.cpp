#include <iostream>
using namespace std;
int arr[1000000];
int n;
int main()
{
    cin>>n;
    arr[0]=1;
    for(int x =1; x<=n; x++)
    {
        for(int y=1; y<=6; y++)
        {
            if(x-y>=0)
            {
                arr[x]+=arr[x-y];
                arr[x]%=1000000007;
            }
        }
    }
    cout<<arr[n];
}
