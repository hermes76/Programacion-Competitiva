// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int A[], int B[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(n+1, vector<int>(m+1,0));
		for(int x=1; x<=(n-(m-1)); x++)
		{
		    for(int y=1; y<=m; y++)
		    {
		        dp[x][y] = max(dp[x][y-1] + A[x-2+y]*B[y-1], dp[x-1][y]);
		    }
		}
		return dp[n-(m-1)][m];
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends