// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        long long int MOD = 1000000007;
        vector<long long int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int x=2; x<n; x++)
            dp[x]=(dp[x-1] + dp[x-2])%MOD;
        return dp[n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
