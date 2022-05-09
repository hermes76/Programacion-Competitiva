// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long int
#define vll vector<ll>
class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        set<pair<ll,ll>> processed;
        vll dp(N,0);
        processed.insert({A[0],-1});
        dp[0]=1;
        for(ll x=1; x<N; x++)
        {
            auto it=processed.lower_bound({A[x]+1,-10000000000});
            auto et=processed.lower_bound({A[x]-1,-10000000000});
            if(it!=processed.end())
            {
                if(it->first == A[x]+1)
                {
                    dp[x]= max(dp[x], (-1*it->second));
                }
            }
             if(et!=processed.end())
            {
                if(et->first == A[x]-1)
                {
                    dp[x]= max(dp[x], (-1*et->second));
                }
            }
            dp[x]++;
            processed.insert({A[x], -dp[x]});
            dp[x]=max(dp[x-1],dp[x]);
        }
        //for(ll x=0; x<N; x++)cout<<dp[x]<<" ";
        return dp[N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
