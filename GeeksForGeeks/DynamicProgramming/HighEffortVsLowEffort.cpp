// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
class Solution
{
   
    public:
        int maxAmt(int n , int hi[] , int li[])
        {
            //code here.    
            vector<int> dp(n+1,0);
            dp[0]=0;
            dp[1] = max(hi[0], li[0]);
            for(int x=2; x<=n; x++)
            {
                dp[x]= max(dp[x-2] + hi[x-1], dp[x-1] + li[x-1]);
            }
            return dp[n];
        }
};
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int n;
            cin>>n;
            int hi[n] , li[n];
            for(int i = 0 ;i<n;i++)
                cin>>hi[i];
            for(int i = 0 ;i<n;i++)
                cin>>li[i];
            Solution ob;
            cout<<ob.maxAmt(n,hi,li)<<endl;    
        }
}  // } Driver Code Ends