#include <iostream>
using namespace std;
int arr[100000];
int BinarySearch(int inicio, int fin, int elemento)
{
    int res=0;
    int medio2;
    while(inicio<=fin)
    {
        medio2=(inicio+fin)/2;
        if(arr[medio2]==elemento){res=max(res,medio2+1); inicio=medio2+1;}
        if(arr[medio2]>elemento){fin=medio2-1;}
        else if(arr[medio2]<elemento){inicio=medio2+1; res=max(res,medio2+1);}
    }
    return res;
}
int main()
{
    int n,m; cin>>n>>m;
    int a;
    for(int x =0; x<n; x++)cin>>arr[x];
    while(m--)
    {
        cin>>a;
        cout<<BinarySearch(0,n-1,a)<<endl;
    }
}
