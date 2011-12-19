#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000

int dp[N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int temp;
		int max=0;
		while(n--)
		{
			scanf("%d",&temp);
			
			for(int i=max;i>=0;i--)
			{
				if(dp[i]) dp[i+temp]+=dp[i];
			}
			max+=temp;
		}
		
		char print[30];
		int res=0;
		for(int i=max;i>=0;i--)
		{
			if(dp[i])
			{
				sprintf(print,"%d",i);
				if(strstr(print,"23"))
				{
					res+=dp[i];
				}
			}
		}
		
		printf("%d\n",res);
		scanf("%d",&n);
	}
	return 0;
}
			
