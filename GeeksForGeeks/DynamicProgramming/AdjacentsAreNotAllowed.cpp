// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>> dp(2, vector<int>(N+1,0));

        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = mat[0][0];
        dp[1][1] = mat[1][0];

        for(int x=2; x<=N; x++)
        {
            dp[0][x] =max(dp[1][x-2] +mat[0][x-1],max(dp[0][x-2] + mat[0][x-1], dp[0][x-1]));
            dp[1][x] =max(dp[0][x-2] +mat[1][x-1],max(dp[1][x-2] + mat[1][x-1], dp[1][x-1]));
        }
        return max(dp[0][N], dp[1][N]);
    }

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }

        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
