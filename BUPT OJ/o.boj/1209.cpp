#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 105


int max(int a,int b,int c)
{
	int m=a;
	if(m<b) m=b;
	if(m<c) m=c;
	
	return m;
}


int main()
{
	
	freopen("input.txt","r",stdin);
	
	int y,x;
	int pos[N][N];
	int dp[N][N];
	while(scanf("%d%d",&y,&x)!=-1)
	{
		memset(pos,0,sizeof(pos));
		memset(dp,0,sizeof(dp));
		
		for(int i=0;i<y;i++)
		{
			for(int k=0;k<x;k++) scanf("%d",&pos[i][k]);
		}
		
		for(int i=0;i<y;i++)
		{
			dp[i][0]=pos[i][0];
		}
		
		
		for(int k=1;k<x;k++)
		{
			for(int i=0;i<y;i++)
			{
				int a=-1,b=-1,c=-1;
				if(i-1>=0&&k-1>=0) a=dp[i-1][k-1];
				b=dp[i][k-1];
				if(i+1<y&&k-1>=0) c=dp[i+1][k-1];
				
				dp[i][k]=pos[i][k]+max(a,b,c);
			}
		}
		
		int res=0;
		for(int i=0;i<y;i++)
		{
			if(dp[i][x-1]>res) res=dp[i][x-1];
		}
		printf("%d\n",res);
	}
	return 0;
}