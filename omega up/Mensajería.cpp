#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   int n,k;
   cin>>n>>k;
   int arr[n];
   int res=0;
   int p=n-1;
   for(int x=n-1; x>=0; x--)cin>>arr[x];
   for(int x=n-1; x>=0; x--)
        if(arr[p]<arr[x])
            p=x;
   res+=k;
   for(int x=n-1; x>=0; x--)
   {
       if(p==x)continue;
       else if(arr[x]>=k)res+=k;
       else res+=arr[x];
   }
   cout<<res;
}
