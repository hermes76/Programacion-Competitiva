// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int cuts(string s);

int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
       cin>>s;
    cout<<cuts(s)<<endl;

   }


    return 0;
}
// } Driver Code Ends

#include <vector>
int cuts(string s){
    //code
    int n= s.length();
    vector<vector<int>> dp(s.size(), vector<int> (s.size(), 1000000000));
    vector<long long int> powFive;
    long long int five=1;
    powFive.push_back(1);
    while(five<1125899907000000){
        five*=5;
        powFive.push_back(five);
    }
    for(int x=n-1; x>=0; x--)
    {
        long long int sum=0;
        for(int y=n-1; y>=0; y--)
        {
            sum+= (s[y]-'0')*pow(2,x-y);
            bool flag=false;
            if(s[y]=='1')
            {
                for(int z=0; z<powFive.size(); z++)
                {
                    if(sum==powFive[z])
                        flag=true;
                    if(sum<powFive[z])
                        break;
                }
            }
            if(flag)
            {
                
                if(x==n-1)
                {
                    dp[y][x]=1;
                    dp[y][n-1]= min(dp[y][n-1],dp[y][x]);
                }
                else
                {
                    dp[y][x]=1;
                    dp[y][n-1]= min(dp[y][n-1],dp[y][x]+dp[x+1][n-1]);
                }
            }
        }
    }
     if(dp[0][n-1]>=1000000000)
     return -1;
    return dp[0][n-1];
}
