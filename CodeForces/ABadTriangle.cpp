#include <iostream>
using namespace std;
int arr[50000];
int a,n;
bool D()
{
    for(int x =0; x<a-2; x++)
        {
            if(arr[x]+arr[x+1]<=arr[a-1])
            {
                cout<<x+1<<" "<<x+2<<" "<<a<<endl;
                return 0;
            }
        }
        return 1;
}
int main()
{
    cin>>n;
    bool p;
    while(n--)
    {
        cin>>a;
        for(int x =0; x<a; x++) cin>>arr[x];
        p=D();
        if(p)cout<<"-1"<<endl;
    }
}
