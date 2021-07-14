#include <iostream>
using namespace std;
int n,m;
int arr[1002];
int dp[1000002];
int main()
{
    cin>>n>>m;
    for(int x=0; x<n; x++)cin>>arr[x];
    dp[0]=1;
    for(int x =1; x<=m; x++)
    {
        for(int y =0; y<n; y++)
        {
           if(x-arr[y]>=0)
           {
               dp[x]+=dp[x-arr[y]];
               dp[x]%=1000000007;
           }
        }
    }
    cout<<dp[m];
}
