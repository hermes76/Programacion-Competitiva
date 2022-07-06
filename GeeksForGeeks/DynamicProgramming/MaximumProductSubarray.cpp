// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
#define ll long long 
#include <vector> 
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    vector<int> ceros;
	    ceros.push_back(-1);
	    for(int x=0; x<n; x++)
	        if(arr[x]==0)
	            ceros.push_back(x);
	   
	      ceros.push_back(n);
	      
	     ll ans=-1000000000;
	     for(ll x=1; x<ceros.size(); x++)
	     {
	         if(ceros[x-1]+1>=n)
	            break;
	         ll res=arr[ceros[x-1]+1];
	            ans=max(res,ans);
	         for(ll y= ceros[x-1]+2; y<ceros[x]; y++)
	         {
	            res*=arr[y];
	            ans=max(res,ans);
	         }
	        // cout<<res<<endl;
	         ans=max(res,ans);
            
            res=arr[ceros[x]-1];
               ans=max(res,ans);
            for(ll y=ceros[x]-2; y>=ceros[x-1]+1; y--)
                {
                    res*=arr[y];
                    ans=max(res,ans);
                }
              //  cout<<res<<endl;
            ans=max(res,ans);
	     }
	     return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
