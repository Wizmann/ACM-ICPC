#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 55

int dp[N][N];

void init()
{
	for(int i=0;i<N;i++) dp[i][1]=i;
	
	for(int i=3;i<N;i++)
	{
		for(int j=2;j<N&&j<i;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-2][j-1];
		}
	}
}

int main()
{
	init();
	
	int a,b;
	while(scanf("%d%d",&a,&b),a,b)
	{
		printf("%d\n",dp[a][b]);
	}
	return 0;
}