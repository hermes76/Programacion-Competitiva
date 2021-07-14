#include <iostream>
#include <algorithm>
using namespace std;
bool comp(pair< int ,int > a, pair< int , int > b)
{
    if(a.first < b.first)
        return 1;
    return 0;
}
int main()
{
    int n;
    int tam;
    cin>>n;
    int indice;
    while(n--)
    {
        cin>>tam;
        pair<int,int> arr[tam];
        int original[tam];
        for(int x=0; x<tam; x++){cin>>arr[x].first; original[x]=arr[x].first; arr[x].second=x;}
        sort(arr,arr+tam,comp);
        indice=tam;
        for(int x=tam-1; x>=0; x--)
        {
            if(indice>arr[x].second)
            {
                for(int y=arr[x].second; y<indice; y++)
                    cout<<original[y]<<" ";
                indice=arr[x].second;
            }
        }
        cout<<endl;
    }
}
