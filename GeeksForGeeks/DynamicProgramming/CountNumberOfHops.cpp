// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<long long> dp(n+1,0);
        dp[n]=1;
        int MOD = 1000000007;
        vector<int> jumps = {1,2,3};
        for(int x=n-1; x>=0; x--)
        {
            for(int y=0; y<3; y++)
            {
                if(x+jumps[y]<=n)
                    dp[x] += dp[x+jumps[y]];
                dp[x]%=MOD;
            }
        }

        return dp[0];
        // your code here

    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;

	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}

    return 0;

}
  // } Driver Code Ends
