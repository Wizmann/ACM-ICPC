#include <cstdio>
#include <cstring>

unsigned char dp[20000];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t,temp;
	scanf("%d",&t);
	while(t--)
	{		
		memset(dp,0,sizeof(dp));
		int money,n;
		scanf("%d%d",&money,&n);
		
		dp[0]=1;
		while(n--)
		{
			scanf("%d",&temp);
			for(int i=money;i>=0;i--)
			{
				if(dp[i])
				{
					if(dp[i+temp]==0) dp[i+temp]=1+dp[i];
					else
					{
						if(dp[i+temp]>1+dp[i]) dp[i+temp]=1+dp[i];
					}
				}
			}
		}
		
		for(int i=money;;i++)
		{
			if(dp[i])
			{
				printf("%d %d\n",i,dp[i]-1);
				break;
			}
		}
	}
	return 0;
}
			
