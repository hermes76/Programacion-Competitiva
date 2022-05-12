// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1,0);
            dp[0]=0;
            dp[1]=1;
            for(int x=2; x<=n; x++)
            {
                dp[x]= max(dp[x/2], x/2) + max(dp[x/3], x/3) + max(dp[x/4], x/4);
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
