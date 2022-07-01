// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<vector>
class Solution{   
public:
    int LCIS(int arr1[], int m, int arr2[], int n) {
        // code here
        
        vector<int> dp(n,0);
        
        for(int x=0; x<m; x++)
        {
            int index=0;
            for(int y=0; y<n; y++)
            {
                if(arr1[x]==arr2[y])
                    dp[y]=max(dp[y], index+1);
                
                if(arr1[x]>arr2[y])
                    index=max(index, dp[y]);
            }
        }
        int res=0;
        for(int x=0; x<n; x++)
            res=max(res, dp[x]);
            
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m;
        int arr1[m];
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        cin >> n;
        int arr2[n];
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        cout << ob.LCIS(arr1, m, arr2, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends
