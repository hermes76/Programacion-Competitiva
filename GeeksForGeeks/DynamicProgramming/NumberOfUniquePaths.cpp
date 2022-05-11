
// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        long long int MOD= 1000000007;
        int m =a;
        int n= b;
        vector<vector<long long int>> dp(m,vector<long long int>(n,0));
        dp[0][0]=1;
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
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends
