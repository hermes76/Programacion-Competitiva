#include <iostream>
using namespace std;

int main()
{
    int a;
    cin>> a;
    int arr[a];
    int pos[a+1];
    for(int x =0; x<a-1; x++)
    {
        cin>>arr[x];
        pos[arr[x]-1] = arr[x];
    }
    for(int x=0; x<a; x++)
    {
        if(pos[x] !=x+1)
        {
            cout<<x+1;
        }
    }
}
