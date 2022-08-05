//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int countStrings(int n, int k)
    {
        vector<vector<vector<long long int>>> dp(n+1, vector<vector<long long int>>(k+1,vector<long long int>(2,0)));
        dp[1][0][1]=1;
        dp[1][0][0]=1;
        for(int x=2; x<=n; x++)
        {
            for(int y=0; y<=k; y++)
            {
                dp[x][y][0]+= dp[x-1][y][1] + dp[x-1][y][0];
                dp[x][y][0]%=1000000007;
                dp[x][y][1]+=  dp[x-1][y][0];
    
                if(y-1>=0)
                    dp[x][y][1]+= dp[x-1][y-1][1];
                dp[x][y][1]%=1000000007;
            }
        }
        return (dp[n][k][0]+dp[n][k][1])%1000000007;
    }
 
 
 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.countStrings(n,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends