#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int indice3=0;
    //unordered_map <int,int> mapa;
    for(int x =0; x<n; x++)
    {
        cin>>a;
        int arr[a];
        for(int x =0; x<a; x++)
        {
            cin>>arr[x];
        }
        indice3=0;
        sort(arr,arr+a);
        for(int x =1; x<a; x++)
        {
            if(abs(arr[x-1]-arr[x])<=1)
            {
                indice3++;
            }
        }
        if(a-indice3==1)
        {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
