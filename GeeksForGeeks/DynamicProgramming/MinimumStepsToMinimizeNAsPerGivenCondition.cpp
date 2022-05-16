// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minSteps(int N)
	{
	    // Your code goes here
	    vector<int> dp(N+1, 1000000000);
	    dp[0]=0;
	    dp[1]=0;
	    for(int x=2; x<=N; x++)
	    {
	        if(x%2==0)
	            dp[x]= min(dp[x], dp[x/2]+1);
	       if(x%3==0)
	            dp[x]=min(dp[x], dp[x/3]+1);
	       dp[x] = min(dp[x],dp[x-1]+1);
	    }
	    return dp[N];
	}
};


// { Driver Code Starts.
int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;



	    Solution ob;
	    cout << ob.minSteps(n) << "\n";

    }
    return 0;
}

  // } Driver Code Ends
