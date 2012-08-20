//Result: wizmann	2029	Accepted	196K	0MS	C++	938B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SIZE 101

short field[SIZE][SIZE];
int n;
int w,h;
int dp[SIZE][SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	int ax,ay;
	while(scanf("%d",&n),n)
	{
		scanf("%d%d",&w,&h);
		memset(dp,0,sizeof(dp));
		memset(field,0,sizeof(field));
		while(n--)
		{
			scanf("%d%d",&a,&b);
			field[b][a]=1;
		}
		scanf("%d%d",&ax,&ay);
		
		int ans=-1;
		for(int i=w;i>=ax;i--)
		{
			for(int j=1;j<=h;j++)
			{
				for(int k=1;k<ax;k++)
				{
					field[j][i]+=field[j][i-k];
				}
			}
		}
		for(int i=ax;i<=w;i++)
		{
			for(int j=1;j<=ay;j++) dp[ay][i]+=field[j][i];
			ans=max(ans,dp[ay][i]);			
			for(int j=ay+1;j<=h;j++)
			{
				dp[j][i]=dp[j-1][i]-field[j-ay][i]+field[j][i];
				ans=max(ans,dp[j][i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
