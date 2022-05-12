// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){

        // your code here
        int n= s.length();
        long long int MOD= 1000000007;
        vector<long long int > powers(n+1,0);
        powers[0]=0;

        long long int power=1;
        for(int x=1; x<=n; x++)
        {
            powers[x]= powers[x-1] + power;
            power*=10;
            power%=MOD;
            powers[x]%=MOD;
        }
        long long int res=0;
        for(int x=0; x<n; x++)
        {
            res+= (s[x]-'0')*powers[n-x]* (x+1);
            res%=MOD;
        }
        return res;
}
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;

    }
    return 0;
}
  // } Driver Code Ends
