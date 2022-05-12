ver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    vector<long long int> dp(n+1);
		    dp[0]=1;
		    dp[1]=1;

		    for(int x=2; x<=n; x++)
		    {
		       for(int y=1; y<=2; y++)
		       {
		            dp[x] += dp[x-y];
		            dp[x]%=1000000007;
		       }

		    }
		  return dp[n];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
