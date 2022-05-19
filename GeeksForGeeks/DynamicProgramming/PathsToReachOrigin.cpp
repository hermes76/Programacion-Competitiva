// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        long long int MOD = 1000000007;
        int n=y;
        int m=x;
        n++;
        m++;
        vector<vector<long long int>> dp(n, vector<long long int>(m,0));
        for(int x=0; x<n; x++)
            dp[x][0]=1;
        for(int x=0; x<m; x++)
            dp[0][x]=1;
        
        for(int x=1; x<n; x++)
        {
            for(int y=1; y<m; y++)
            {
                dp[x][y] = dp[x-1][y]+ dp[x][y-1];
                dp[x][y]%=MOD;
            }
        }
        return dp[n-1][m-1];
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}
  // } Driver Code Ends