#include <iostream>
using namespace std;

int main()
{
    int arr[4];
    int aux;
    for(int x=0; x<4; x++)
    {
        cin>>arr[x];
    }
    for(int x =0; x<4; x++)
    {
        for(int y =0; y<4; y++)
        {
            if(arr[x]<arr[y])
            {
                aux= arr[x];
                arr[x]= arr[y];
                arr[y]=aux;
            }
        }
    }
    for(int x =0; x<4; x++)
    {
        cout<<arr[x]<<" ";
    }
}