#include <cstdio>
#include <cstdlib>
#include <cstring>

long long dp[15][70];

void init()
{
	for(int i=1;i<65;i++) dp[0][i]=1;
	for(int i=1;i<10;i++) dp[i][1]=i+1;
	for(int i=2;i<65;i++)
	{
		for(int j=1;j<10;j++) dp[j][i]=(dp[j-1][i]+dp[j][i-1]);
	}
}

int main()
{
	int t;
	init();
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d %lld\n",a,dp[9][b]);
	}
	return 0;
}
