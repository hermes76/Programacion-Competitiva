#include <iostream>
#include <math.h>
using namespace std;
long long int arr[64];
int main()
{
    long long int n,res;
    cin>>n;
    arr[0]=1;
    int pot=0;
    for(int n; n; x++)
    {
        if(n&(1<<x))pot =x;
    }
    cout<<pot<<endl;
    for(int x =1; x<pot; x++)
    {
        for(int y=x-1; y>=0; y--)
        {
            arr[x]+=arr[y];
        }
        arr[x]+=(pow(2,x));
        cout<<arr[x]<<endl;
    }

}
