#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    int cuenta=0;
    for(int x=0; x<n; x++){cin>>arr[x]; arr2[x]=arr[x];}
    sort(arr,arr+n);
    int indice1, indice2;
    indice1=0;
    indice2=0;
    for(int x=0; x<n; x++)
    {
        if(arr[indice1]!=arr2[indice2])
        {
            cuenta++;
            indice2++;
        }else{
            indice1++;
            indice2++;
        }
    }
    cout<<cuenta<<endl;

}
