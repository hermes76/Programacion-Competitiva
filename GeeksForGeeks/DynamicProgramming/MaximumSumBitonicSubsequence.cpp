// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}// } Driver Code Ends


int maxSumBS(int arr[] , int n )
{
    vector<int> down(n,0);
    vector<int> up(n,0);
    down[n-1]= arr[n-1];
    for(int x=n-2; x>=0; x--)
    {
        down[x]=arr[x];
        for(int y=x+1; y<n; y++)
        {
            if(arr[x]>arr[y])
                down[x]= max(down[x], down[y]+arr[x]);
        }
    }
    up[n-1]= arr[n-1];
    for(int x=n-2; x>=0; x--)
    {
        up[x]=down[x];
        for(int y=x+1; y<n; y++)
        {
            if(arr[x]<arr[y])
            {
                if(up[y]==0)
                {
                    up[x]=max(up[x], arr[x]+down[y]);
                }
                else
                up[x]= max(up[x], arr[x] + up[y]);
            }
        }
    }
    int res=0;
    for(int x=0; x<n; x++)
        res=max(res,max(down[x],up[x]));
    return res;
}
