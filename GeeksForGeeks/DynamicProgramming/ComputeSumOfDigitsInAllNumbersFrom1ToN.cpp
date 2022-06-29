/ { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <vector>
class Solution{
public:
    int sumOfDigits(int N){
        //code here
       vector<int> dp(N+1);
       
       for(int x=0; x<=min(9,N); x++)
            dp[x]=x;
        
        if(N<10)
            return N*(N+1)/2;
        
        int res=45;
        int index=10;
        for(int x=10; x<=N; x++)
        {   
            if(x==index+10)
                index+=10;
            
            dp[x]= dp[x%index] + dp[x/10];
            res+= dp[x];
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.sumOfDigits(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
