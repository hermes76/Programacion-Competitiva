#include <iostream>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,a;
    cin>>n>>a;
    int arr[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    long long int suma=0;
    long long int vertex[n];
    for(int x =0; x<n; x++)
    {
        suma+=arr[x];
        vertex[x]=suma;
    }
    int b,c;
    for(int x=0; x<a; x++)
    {

        cin>>b>>c;
        if(b<=1)
        {
            cout<<vertex[c-1];
        }else{
            cout<<vertex[c-1]-vertex[b-2];
        }
        cout<<endl;
    }
}
