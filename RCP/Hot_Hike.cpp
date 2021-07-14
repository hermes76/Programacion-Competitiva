#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    int m;
    int indice=0;
    int maximo;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    m=arr[0];
    for(int x =0; x<n-2; x++)
    {
        m=max(arr[x],arr[x+2]);
        if(m<maximo)
        {
            maximo=m;
            indice=x;
        }
    }
    cout<<indice+1<<" "<<maximo<<endl;
}