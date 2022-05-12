// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int n,m;
string cad,cad2;
vector<vector<int>> dp;
    int rep(int x, int y)
    {
        if(y>=m)
        return 1;
        if(x>=n)
        return 0;
        if(dp[x][y]!=-1)
        return dp[x][y];
        int sum=0;
        if(cad[x] == cad2[y]) sum+= rep(x+1, y+1);
        sum+= rep(x+1, y);
        dp[x][y] = sum;
        return sum;

    }
    int countWays(string S1, string S2){
        // code here
        n= S1.length();
        m= S2.length();
        dp.clear();
        dp.resize(n,vector<int>(m,-1));
        cad=S1;
        cad2= S2;
        return rep(0,0);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends
