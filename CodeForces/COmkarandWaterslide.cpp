#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,a;
    cin>>n;
    while(n--)
    {
        cin>>a;
        int mayor=0,menor;
        int arr[a];
        bool p=0;
        for(int x =0; x<a; x++)
        {
            cin>>arr[x];
            mayor=max(mayor,arr[x]);
        }
        menor=arr[a-1];
        for(int x =a-2; x>=0; x--)
        {
            if(mayor==arr[x])
            {
                break;
            }
            menor=min(menor,arr[x]);
        }
        cout<<mayor-menor<<endl;
    }
}
