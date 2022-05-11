// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;

		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/
string a;
vector<vector<int>> dp;
int minimum(int x, int y)
{
    if(x>=y)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(a[x]==a[y])
        dp[x][y]= minimum(x+1, y-1);
    else
        dp[x][y]= min(minimum(x+1, y), minimum(x,y-1))+1;
    return dp[x][y];
}
bool is_k_palin(string s,int k)
{
//Your code here
    a=s;
    int n= s.length();
    dp.clear();
    dp.resize(n, vector<int>(n,-1));
   return (minimum(0,s.length()-1)<=k);

}
