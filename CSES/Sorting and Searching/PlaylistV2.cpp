#include <iostream>
#include <map>
using namespace std;
map <int, int> fr;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int cuenta=0;
    int maximo=0;
    int indice=0;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
        fr[arr[x]]=0;
    }
    for(int x =0; x<n; x++)
    {
        fr[arr[x]]+=1;
        if(fr[arr[x]]==2)
        {
            cuenta=x-indice;
             maximo=max(cuenta,maximo);
            fr[arr[x]]=1;
            while(arr[indice]!=arr[x] &&indice<n)
            {
                fr[arr[indice]]=0;
                indice++;
            }
            indice++;
        }

    }
   if(maximo<n-indice)
   {
       maximo=n-indice;
   }
    cout<<maximo;
    return 0;
}
