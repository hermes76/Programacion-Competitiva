// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



#include <vector>
class Solution
{
	public:
	int minInsertions(int arr[], int N) 
	{ 
	    // Your code goes here
	    vector<int> bigger(N,1);
	    
	    for(int x=N-2; x>=0; x--)
	    {
	        for(int y=x+1; y<N; y++)
	        {
	            if(arr[x]<=arr[y])
	                 bigger[x]=max(bigger[x], bigger[y]+1);
	        }
	    }
	int res=0;
	for(int x=0; x<N; x++)
	{
	    res=max(res,bigger[x]);
	}
	    
	  return N-res;
	}
};


// { Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	   

	    Solution ob;
	    cout << ob.minInsertions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
