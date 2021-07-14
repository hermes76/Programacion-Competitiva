#include <iostream>
using namespace std;
int arr[100000];
int BinarySearch(int inicio,  int fin, int elemento)
{
    int medio;
    int res=fin+2;
    while(inicio<=fin)
    {
        medio=(inicio+fin)/2;
        if(arr[medio]== elemento){fin=medio-1;res=min(res,medio+1);}
        if(arr[medio]>elemento){fin=medio-1; res=min(res,medio+1);}
        if(arr[medio]<elemento){inicio=medio+1;}
    }
    if(res==0)res+1;
    return res;
}
int main()
{
    int n,m; cin>>n>>m;
    int a;
    for(int x=0; x<n; x++)cin>>arr[x];
    while(m--)
    {
        cin>>a;
        cout<<BinarySearch(0,n-1,a)<<endl;

    }

}
