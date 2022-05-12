// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        int sum=0;
        sort(arr, arr+N);

        for(int x=N-2; x>=0;)
        {
            //cout<<arr[x]<<endl;
            if(arr[x+1]-arr[x]<K)
            {
                sum+= arr[x+1]+arr[x];
                x-=2;
            }
            else
                x--;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
