// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<bool> subcad;
	int n;
	vector<int> dp;
	int minimal(int pos)
	{
	    if(pos<=0)
	        return 0; 
	    if(dp[pos]!=1000000000)
	        return dp[pos];
	   int minix=1000000000;
	    if(pos%2==0 &&subcad[pos/2]==true)
	    {
	       minix=minimal(pos/2)+1;
	    }
	    minix=min(minix,minimal(pos-1)+1);
	    dp[pos]=minix;
	    return dp[pos];
	    
	}
	int minSteps(string S)
	{
	    n= S.length();
	   subcad.clear();
	   subcad.resize(n+1,false);
	   dp.clear();
	   dp.resize(n+1,1000000000);
	   string cad;
	   for(int x=0; x<n; x++)
	   {
	       cad+=S[x];
	       bool acept=true;
	       for(int y=0; y<cad.length(); y++)
	       {
	           if(y+x+1<=n && cad[y] != S[x+y+1])
	           {
	            
	             acept=false;
	             break;
	           }
	       }
	       subcad[x+1]=acept;
	   }
	   
    return minimal(n);
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
        Solution ob;
   		cout << ob.minSteps(s);

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends