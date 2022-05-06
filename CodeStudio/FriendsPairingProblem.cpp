
#define MOD 1000000007
int numberOfWays(int n)
{
    if(n==1)
    return 1;
	vector<vector<long>> dp(n+1,vector<long>(2,0));
	dp[0][0]=0;
	dp[0][1]=0;
	dp[1][0]=1;
	dp[1][1]=0;
	dp[2][0]=1;
	dp[2][1]=1;
	for(int x=3; x<=n; x++)
	{
		dp[x][0]=(dp[x-1][0] + dp[x-1][1])%MOD;
		dp[x][1]= dp[x-1][0] * (x-1);
		dp[x][1]%=MOD;
		dp[x][0]%=MOD;
	}
	return (dp[n][0] + dp[n][1])%MOD;
}
