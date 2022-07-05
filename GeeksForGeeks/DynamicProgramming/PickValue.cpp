// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

#include<vector>
class Solution{   
public:
    int pickValues(int arr[], int n) {
        // code here
        vector<int> dp(n,0);
        for(int x=0; x<min(n,4); x++)
            dp[x]=arr[x];
        
        for(int x=4; x<n; x++)
            dp[x]=min(dp[x-4],min(dp[x-3],min(dp[x-2],dp[x-1]))) + arr[x];
        
        int res=1000000000;
        for(int x=n-1; x>=max(0,n-4); x--)
            res=min(res, dp[x]);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.pickValues(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


  // } Driver Code Ends
