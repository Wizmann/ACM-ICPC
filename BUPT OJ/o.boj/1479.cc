#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int dp[100010];
int array[100010];

int main()
{	
	freopen("input.txt","r",stdin);
	
	int n;
	int smin,smax;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++) scanf("%d",&array[i]);

		scanf("%d%d",&smax,&smin);
		
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			int temp=-1;
			for(int j=smin;j<=smax;j++)
			{
				if(i-j>=0&&dp[i-j]>temp)
				{
					temp=dp[i-j];
				}
				if(temp>=0) dp[i]=temp+array[i];
			}
		}
		
		printf("%d\n",dp[n]);
	}
	return 0;
}
					
