// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        //Write your code here
        vector<int> dp(n+4,0);
        if(n<4)
        {
            int res=1000000000;
             for(int x=0; x<n; x++)
                res=min(res, arr[x]);
            return res;
        }
        dp[n]=0;
        dp[n+1]=0;
        dp[n+2]=0;
        dp[n+3]=0;
        for(int x=n-1; x>=0; x--)
            dp[x]= min(dp[x+1],min(dp[x+2],min( dp[x+3], dp[x+4]))) + arr[x];

        int res=1000000000;
        for(int x=0; x<4; x++)
            res=min(res, dp[x]);
        return res;
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
