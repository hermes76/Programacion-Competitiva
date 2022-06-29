/ { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long countWays(int N) {
        // code here
        vector<long long int> dp(N+1,0);
        vector<long long int> sums={1,3,4};
        dp[0]=1;
        for(long long int x=1; x<=N; x++)
        {
            for(long long int y=0; y<3; y++)
            {
                if(x-sums[y]>=0)
                {
                    dp[x]+= dp[x-sums[y]]%1000000007;
                    dp[x]%=1000000007;
                }
            }
        }
        return dp[N];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
