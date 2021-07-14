#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int x=0; x<n; x++)
    {
        int a;
        cin>>a;
        int r=a;
        long long int arr[a];
        long long int suma;
        for(int y=0; y<a; y++)cin>>arr[y];
        for(int y=1; y<a-1; y++)
        {
            if(arr[y-1]!=arr[y]){ r--; arr[y]+=arr[y-1];}
            else{
                suma=0;
                    int z=y;
                for(z; z<a; z++)
                {
                    if(arr[y]!=arr[z])
                    {
                        arr[y]=suma;
                        r-=z-y;
                        break;
                    }else{
                        suma+=arr[z];
                    }
                }
                y=z;
            }
        }
        if(arr[a-1]!=arr[a-2] and r>1)
        {
            r--;
        }
        cout<<r<<endl;
    }
}
