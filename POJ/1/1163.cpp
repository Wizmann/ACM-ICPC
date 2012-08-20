#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[100][100];
int tri[100][100];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(tri,0,sizeof(tri));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++) scanf("%d",&dp[i][j]);
		}
		
		tri[0][0]=dp[0][0];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j-1>=0) if( tri[i][j]<dp[i][j]+tri[i-1][j-1] ) tri[i][j]=dp[i][j]+tri[i-1][j-1];
				if(j<i) if( tri[i][j]<dp[i][j]+tri[i-1][j] ) tri[i][j]=dp[i][j]+tri[i-1][j];
			}
		}
		
		int max=(int)-2e30;
		for(int i=0;i<n;i++) if(tri[n-1][i]>max) max=tri[n-1][i];
		printf("%d\n",max);
	}
	return 0;
}