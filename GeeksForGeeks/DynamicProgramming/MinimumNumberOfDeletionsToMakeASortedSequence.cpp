// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int minDeletions(int arr[], int n)
	{
	    // Your code goes here
	    vector<int> dp(n,1);
	    dp[0] =1;
	    for(int x=1; x<n; x++)
	    {
	       for(int y=x-1; y>=0; y--)
	       {
	           if(arr[x]> arr[y])
	           {
	               dp[x] = max(dp[y]+1, dp[x]);
	           }
	       }
	    }
	    int ans=0;

	    for(int x=0; x<n; x++)
	    ans=max(ans, dp[x]);
	    return n-ans;
	    return dp[0];
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];



	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends
