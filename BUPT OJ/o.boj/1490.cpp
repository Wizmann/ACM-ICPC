#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 15000

char dp[N];

int main()
{
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		int money;
		scanf("%d",&money);
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		int temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			for(int i=N;i>0;i--)
			{
				if(dp[i])
				{
					if(i+temp<=12000)
					{
						if(dp[i]+1<dp[i+temp]||dp[i+temp]==0) dp[i+temp]=dp[i]+1;
					}
				}
			}
			dp[temp]=1;
		}
		
		for(int i=money;i<N;i++)
		{
			if(dp[i])
			{
				printf("%d %d\n",i,dp[i]);
				break;
			}
		}
	}
	return 0;
}
