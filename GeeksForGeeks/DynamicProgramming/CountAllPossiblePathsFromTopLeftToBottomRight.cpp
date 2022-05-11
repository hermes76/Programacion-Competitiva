// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        long long int MOD= 1000000007;
        vector<vector<long long int>> dp(m,vector<long long int>(n,0));
        dp[0][0]=0;
        for(int x=1; x<n; x++)
        dp[0][x]=1;

        for(int x=1; x<m; x++)
        dp[x][0]=1;

        for(int x=1; x<m; x++)
        {
            for(int y=1; y<n; y++)
            {
            dp[x][y] += dp[x-1][y] + dp[x][y-1];
            dp[x][y]%=MOD;
            }
        }
        return dp[m-1][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
