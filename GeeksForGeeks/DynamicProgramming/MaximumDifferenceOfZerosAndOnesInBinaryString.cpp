// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int maxSubstring(string S)
	{
	    int n= S.length();
	    vector<int> dp(n+1,-1);
	    int best=-1;
	    for(int x=1; x<=n; x++)
	    {
	        if(S[x-1]=='0')
	            dp[x] = max(dp[x-1]+1, 1);
	       if(S[x-1]=='1')
	            dp[x]= dp[x-1]-1;
	       best= max(best,dp[x]);
	    }
	    return best;
	    // Your code goes here
	}
};

// { Driver Code Starts.

int main()
{


   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
