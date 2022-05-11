
// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
#define ll long long int
long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.

	vector<ll> knapsack = {3,5,10};
	// Your code here
    for(ll x=0; x<3; x++)
    {
        for(ll y=0; y<=n; y++)
        {
            if(y-knapsack[x]>=0)
            table[y]+=table[y-knapsack[x]];
        }
    }
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
