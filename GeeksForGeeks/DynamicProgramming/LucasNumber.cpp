// { Driver Code Starts
#include <iostream>
using namespace std;

 // } Driver Code Ends
#include <vector> 
class Solution
{
    
    public:
        long long lucas(int n)
        {
            //code here
            vector<int> lucas(n+1,0);
            lucas[0]=2;
            lucas[1]=1;
            for(int x=2; x<=n; x++)
                lucas[x]=(lucas[x-1]+lucas[x-2])%1000000007;
            return lucas[n];
        }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.lucas(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
