#include <iostream>
#include <cstdio>

using namespace std;

#define N 200+10

int sum[N];
int dp[N][N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n)
	{
		int temp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			sum[i]=temp+sum[i-1];
		}
		
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int min=1<<30;
				for(int k=0;k<i;k++)
				{	
					temp=dp[j][j+k]+dp[j+k+1][j+i]+(sum[j+i]-sum[j-1]);
					if(temp<min) min=temp;
				}
				dp[j][j+i]=min;
			}
		}
		//for(int i=1;i<=n;i++)
		//{
		//	for(int j=1;j<=n;j++) printf("%d ",dp[i][j]);
		//	printf("\n");
		//}
		printf("%d\n",dp[1][n]);
		scanf("%d",&n);
	}
	return 0;
}