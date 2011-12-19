//Result: Wizmann	2948	Accepted	3112K	610MS	C++	887B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 501
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int r,c;
int y[SIZE][SIZE],b[SIZE][SIZE],dp[SIZE][SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		memset(y,0,sizeof(y));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&r,&c);
		if(r+c==0) break;

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++) scanf("%d",&y[i][j]);
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++) scanf("%d",&b[i][j]);
		}

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++) y[i][j]+=y[i][j-1];
		}
		for(int i=1;i<=c;i++)
		{
			for(int j=1;j<=r;j++) b[j][i]+=b[j-1][i];
		}
		
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				dp[i][j]=max(dp[i-1][j]+y[i][j],dp[i][j-1]+b[i][j]);
			}
		}
		
		printf("%d\n",dp[r][c]);
	}
	return 0;
}
