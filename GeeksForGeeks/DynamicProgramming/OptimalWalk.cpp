// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include <vector>
class Solution{
public:
    long long optimalWalk(long long N, long long A, long long B)
    {
        // code here
        vector<long long int> dp(N+1);
        dp[0]=0;
        for(int x=1; x<=N; x++)
        {
            dp[x]=dp[x-1]+A;
            if(x%2==0)
                dp[x]= min(dp[x],dp[x/2]+B);
            else
                 dp[x]=min(dp[x], dp[(x+1)/2]+B+A);
        }
        return dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N, A, B;
        cin>>N>>A>>B;
        
        Solution ob;
        cout<<ob.optimalWalk(N, A, B)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
