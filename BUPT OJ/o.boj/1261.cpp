#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int set[1200][1200];
int dp[1200][1200];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<=i;k++) scanf("%d",&set[i][k]);
	}
	
	dp[0][0]=set[0][0];
	
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<=i;k++)
		{
			if(dp[i][k]+set[i+1][k]>dp[i+1][k]) dp[i+1][k]=dp[i][k]+set[i+1][k];
			if(dp[i][k]+set[i+1][k+1]>dp[i+1][k+1]) dp[i+1][k+1]=dp[i][k]+set[i+1][k+1];
		}
	}
	
	
	int max=0;
	for(int i=0;i<n;i++) if(max<dp[n-1][i]) max=dp[n-1][i];
	
	printf("%d\n",max);
	return 0;
}