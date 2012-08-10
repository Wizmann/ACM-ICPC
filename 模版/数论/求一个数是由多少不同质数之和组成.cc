llint dp[SIZE+10][SIZE+10];
llint ans[SIZE+10];

llint dfs(int x,int t)
{
	if(dp[x][t]!=-1) return dp[x][t];
	else
	{
		if(prime[t]>x)
		{
			return dp[x][t]=1;
		}
		dp[x][t]=dfs(x,t+1);
		int k=prime[t];
		while(k<=x)
		{
			dp[x][t]+=dfs(x-k,t+1);
			k*=prime[t];
		}
		return dp[x][t];
	}
}
	
