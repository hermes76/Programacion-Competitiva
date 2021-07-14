#include <iostream>
#include <algorithm>
using namespace std;
int menor;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int p;
    while(n--)
    {
        menor=1000000000;
        p=0;
        cin>>a;
        int arr[a];
        int brr[a];
        int l;
        for(int x =0; x<a; x++)
        {
            cin>>l;
            arr[x]=l;
            brr[x]=l;
            menor=min(menor,l);
        }
        sort(arr,arr+a);
        for(int x =0; x<a; x++)
        {
            if(brr[x]!=arr[x])
            {
                if(brr[x]%menor!=0 or arr[x]%menor !=0)
                {
                    p=1;
                    break;
                }
            }
        }
        if(p)cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
}
