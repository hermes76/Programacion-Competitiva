// { Driver Code Starts
#include <iostream>
#include<algorithm>
#include<cstdio>
//#include<Windows.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are requried to complete this method */
    int max_Books(int a[], int n, int k)
    {
        // Your code here
        int res=0;
        for(int x=0; x<n; x++)
        {
            int sum=0;
            while(x<n && a[x]<=k)
            {
                sum+=a[x];
                res= max(sum,res);
                x++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  	int n,k;
  	cin>>n>>k;
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>ar[i];
  	}
  	Solution ob;
  	cout<<ob.max_Books(ar,n,k)<<endl;

  }
  return 0;
}

  // } Driver Code Ends
