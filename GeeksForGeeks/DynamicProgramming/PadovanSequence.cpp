// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include <vector>
class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       vector<long long int> dp(n+1,0);
       dp[0]=dp[1]=dp[2]=1;
       
       for(int x=3; x<=n; x++)
        dp[x]=(dp[x-2]+dp[x-3])%1000000007;
        return (int)dp[n];
        
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
