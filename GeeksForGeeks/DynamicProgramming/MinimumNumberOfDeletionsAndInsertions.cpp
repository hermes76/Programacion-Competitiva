// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int minOperations(string str1, string str2)
	{
	    int n,m;
	    n= str1.length();
	    m = str2.length();
	    vector<vector<int>> dp(n+1, vector<int>(m+1 ,0));
	     for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
            // If characters match and indexes are
            // not same
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] =  1 + dp[i-1][j-1];
            }

            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
	    int calc= dp[n][m];
	    int res = (n-calc) + (m-calc);
	    return res;

	}
};

// { Driver Code Starts.
int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";

    }
    return 0;
}

  // } Driver Code Ends
