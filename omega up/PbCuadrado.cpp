#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n][n];
    for(int x =0; x<n; x++)for(int y =0; y<n; y++)cin>>arr[x][y];
    for(int x =0; x<n; x++)
    {
        for(int y =0; y<n; y++)
        {
            cout<<arr[n-1-y][x]<<" ";
        }
        cout<<endl;
    }
}
