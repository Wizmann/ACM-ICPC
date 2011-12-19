#include <cstdio>
#include <cstring>
#include <cstdlib>

int dp[10010];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,ans;
	while(scanf("%d",&n),n)
	{
		memset(dp,0,sizeof(dp));
		ans=0;
		int t,a,sum,pre;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&t,&a);
			sum=0;
			for(int j=0;j<a;j++)
			{
				scanf("%d",&pre);
				if(dp[pre]>sum) sum=dp[pre];
			}
			dp[i]=sum+t;
			if(dp[i]>ans) ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
		
