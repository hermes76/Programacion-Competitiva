// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int cost_x;
	int cost_y;
	string cad,cad2;
	vector<vector<int>> dp;
	int minimal(int x, int y)
	{
	    if(x>= cad.length() && y>= cad2.length())
	        return 0;
	   if(x>= cad.length() && y< cad2.length())
	    {
	       dp[x][y] = minimal(x,y+1) + cost_y;
	    }
	   else if( x<cad.length() && y>= cad2.length())
	   {
	       dp[x][y] = minimal(x+1,y)+cost_x;
	   }
	   if(dp[x][y]!=1000000007)
	        return dp[x][y];

	   if(cad[x] == cad2[y])
	    dp[x][y] = minimal(x+1, y+1);
	   else
	    dp[x][y] = min(minimal(x+1,y)+cost_x, minimal(x, y+1)+cost_y);

	   return dp[x][y];

	}
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes
	    cad  = X;
	    cad2 = Y;
	    cost_x= costX;
	    cost_y= costY;
	    dp.clear();
	    dp.resize(X.length()+1, vector<int>(Y.length()+1,1000000007));
	    return minimal(0, 0);

	}


};


// { Driver Code Starts.
int main()
{

   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;

       	int costX, costY;
       	cin >> costX >> costY;



        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";

    }
    return 0;
}

  // } Driver Code Ends
