#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[3];
    int brr[3];
    int suma;
    int minix;
    while(n--)
    {
        suma=0;
        minix=0;
        for(int x =0; x<3; x++)cin>>arr[x];
        for(int x=0; x<3; x++)cin>>brr[x];
        //2 0
        minix=min(arr[2],brr[1]);
        arr[2]-=minix;
        brr[1]-=minix;
        suma+=2*minix;
        //0 2
        minix=min(arr[0],brr[2]);
        brr[2]-=minix;
        arr[0]-=minix;
        //2 2
        minix=min(arr[2],brr[2]);
        brr[2]-=minix;
        arr[2]-=minix;
        //1 1
        minix=min(arr[1],brr[1]);
        brr[1]-=minix;
        arr[1]-=minix;
        //1 2
        minix=min(arr[1],brr[2]);
        suma-=2*minix;
        cout<<suma<<endl;

    }
}
