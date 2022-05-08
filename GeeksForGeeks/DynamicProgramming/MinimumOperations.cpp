
/ { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        vector<int> dp(n+1,0);

        for(int x=n-1; x>=0; x--)
        {

            dp[x]=dp[x+1]+1;
            if(x*2<=n)
            dp[x]=min(dp[x],dp[x*2]+1);

        }
         return dp[0];
    }

};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends
