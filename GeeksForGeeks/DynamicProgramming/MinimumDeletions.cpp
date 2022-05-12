// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  string cad;
  vector<vector<int>> dp;
  int minimal(int a, int b)
  {
      if(a>=b)
      return 0;
      if(dp[a][b]!=-1)
      return dp[a][b];
      if(cad[a] == cad[b])
        dp[a][b] = minimal(a+1, b-1);
        else
        dp[a][b] =min( minimal(a+1, b)+1, minimal(a, b-1)+1);
    return dp[a][b];
  }
    int minimumNumberOfDeletions(string S) {
        // code here
        cad= S;
        dp.clear();
        dp.resize(S.length(),vector<int>( S.length(),-1));
        return minimal(0,S.length()-1);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}  // } Driver Code Ends
