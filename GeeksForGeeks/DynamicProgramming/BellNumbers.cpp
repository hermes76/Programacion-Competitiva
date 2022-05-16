// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int bellNumber(int n)
    {
       // Code Here
      vector<vector<long long int>> dp(n+1, vector<long long int>(n+1, 0));
      dp[1][1]=1;
      long long int MOD= 1000000007;
      for(int x=2; x<=n; x++)
      {
          for(int y=1; y<=n; y++)
          {
              if(y==1)
                dp[x][y] = dp[x-1][x-1];
            else
                dp[x][y] = dp[x-1][y-1]+ dp[x][y-1];
            dp[x][y] %=MOD;
          }
      }
      return dp[n][n];
    }
};


// { Driver Code Starts.



int main()
{
    Solution obj;
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
