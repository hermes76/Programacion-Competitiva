// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
		int countWays(int n, int m)
	{
	    // Code here.
	    vector<long long int> dp(n+1,0);
	    dp[0]=1;
	    for(int x=1; x<=n; x++)
	    {
	        if(x-m>=0)
	        {
	            dp[x]+= dp[x-m];
	              dp[x]%=1000000007;
	        }
	        dp[x]+=dp[x-1];
	        dp[x]%=1000000007;
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
