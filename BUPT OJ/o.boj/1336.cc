#include <stdio.h>

short dp[2001][2001];
short ans[2010];

inline void init()
{
	for(int i=1;i<=2000;i++)
	{
		dp[i][i]=1;
		dp[1][i]=1;
	}
	for(int i=1;i<=2000;i++)
	{
		for(int j=2;j<i;j++) dp[j][i]+=(int)(dp[j-1][i-1]+dp[j][i-1]*j)%10000;
		for(int j=1;j<=i;j++)
		{
			ans[i]+=dp[j][i]%10000;
			ans[i]%=10000;
		}		
	}
}

int main()
{
	init();
	int n;
	scanf("%d",&n);
	int temp;
	while(n--)
	{
		scanf("%d",&temp);
		printf("%d\n",ans[temp]);
	}
	return 0;
}