#include <iostream>
using namespace std;
 int arr[100000];
bool BinarySearch(int inicio, int fin, int elemento)
{
    int medio;
    while(inicio<=fin)
    {
        medio=(inicio+fin)/2;
        if(arr[medio]==elemento)return 1;
        if(arr[medio]>elemento)fin=medio-1;
        else inicio=medio+1;
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a;
    for(int x=0; x<n; x++)cin>>arr[x];
    while(m--)
    {
        cin>>a;
        if(BinarySearch(0,n-1,a))cout<<"YES\n";
        else cout<<"NO\n";
    }
}
