// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int x=0; x<n; x++)
            for(int y=0; y<m; y++)
            dp[x][y]=M[x][y];

        for(int x=m-2; x>=0; x--)
        {
            for(int y= 0; y<n; y++)
            {
                dp[y][x];
                int aux= dp[y][x+1];
                if(y-1>=0)
                    aux = max(aux,dp[y-1][x+1]);

                if(y+1<n)
                    aux= max(aux, dp[y+1][x+1]);

                dp[y][x]+=aux;
            }
        }
        int maximo=0;

        for(int x=0; x<n; x++)
        maximo= max(maximo, dp[x][0]);
        return maximo;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }

        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
