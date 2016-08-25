int slove(int st,int end,int need)
{
	queue<john> pq;
	int dp[SIZE][55];
	char visit[SIZE][55];
	memset(dp,0x3f,sizeof(dp));
	memset(visit,0,sizeof(visit));
	pq.push(john(st,0));
	dp[st][0]=0;
	while(!pq.empty())
	{
		john jnow=pq.front();
		pq.pop();
		int now=jnow.now;
		int wood=jnow.wood;
		visit[now][wood]=0;

		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].dest;
			int cost=g[i].cost;

			int next_wood=wood+1;
			if(next_wood>=need) next_wood=need;
			if(dp[next][next_wood]>dp[now][wood]+cost)
			{
				dp[next][next_wood]=dp[now][wood]+cost;
				if(!visit[next][next_wood])
				{
					visit[next][next_wood]=1;
					pq.push(john(next,next_wood));
				}
			}
		}
	}
	int ans=INF;
	for(int i=50;i>=need;i--)
	{
		ans=min(ans,dp[end][i]);
	}
	return ans;
}
