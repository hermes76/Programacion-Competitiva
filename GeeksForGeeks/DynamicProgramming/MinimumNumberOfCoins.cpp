// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
        vector<pair<int,int>> dp(N+1);
        vector<int> res;
        dp[0]={1,0};
        for(int x=1; x<=N; x++)
        {
            dp[x].first=1000000000;
            for(int y=0; y<coins.size(); y++)
                if(x-coins[y]>=0)
                {
                    if(dp[x].first>dp[x-coins[y]].first)
                    {
                        dp[x].first= dp[x-coins[y]].first+1;
                        dp[x].second= coins[y];
                    }
                }
        }

        int index=N;
        while(index>0)
        {
            res.push_back(dp[index].second);
            index-=dp[index].second;
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
