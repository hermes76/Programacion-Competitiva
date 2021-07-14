#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        int arr[m];
        int mayor=0;
        int mayor2=0;
        int res=0;
        for(int x=0; x<m; x++)cin>>arr[x];
        for(int z=0; z<m; z++)
        {
            mayor=0;
            mayor2=0;
            for(int x=z; x<m; x+=2)mayor+=arr[x];
            for(int x=z+1; x<m; x+=2)mayor2+=arr[x];
            res=max(res,max(mayor,mayor2));
        }
        cout<<res<<endl;
    }
}
