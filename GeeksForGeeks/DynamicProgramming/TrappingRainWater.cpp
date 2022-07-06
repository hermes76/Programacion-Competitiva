// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
#include <vector>
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<long long> left(n,0);
        vector<long long> right(n,0);
        left[0]=arr[0];
        for(int x=1; x<n; x++)
            left[x]=max(left[x-1],(long long)arr[x]);
        
        right[n-1]=arr[n-1];
        
        for(int x=n-2; x>=0; x--)
            right[x]=max((long long)arr[x],right[x+1]);
            
        
        long long wata=0;
        for(int x=0; x<n; x++)
        {
            if(arr[x]<min(left[x],right[x]))
                wata+=min(left[x], right[x])-arr[x];
        }
        return wata;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
