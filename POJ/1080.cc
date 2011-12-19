//Result:wizmann	1080	Accepted	428K	0MS	G++	1169B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

char a[105],b[105];
int dp[105][105];
const int mat[5][5]={
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,0}};
int la,lb;

int conv(char ch)
{
	switch(ch)
	{
		case 'A':return 0;break;
		case 'C':return 1;break;
		case 'G':return 2;break;
		case 'T':return 3;break;
		case '-':return 4;break;
		default:
		{
			printf("ERROR:%c\n",ch);
			return -1;
		}break;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&la,a+1);
		scanf("%d%s",&lb,b+1);
		memset(dp,0,sizeof(dp));

		dp[0][0]=0;
		for(int i=1;i<=la;i++)
		{
			dp[i][0]=dp[i-1][0]+mat[conv(a[i])][conv('-')];
		}
		for(int i=1;i<=lb;i++)
		{
			dp[0][i]=dp[0][i-1]+mat[conv('-')][conv(b[i])];
		}
		for(int i=1;i<=la;i++)
		{
			for(int j=1;j<=lb;j++)
			{
				dp[i][j]=max(dp[i-1][j-1]+mat[conv(a[i])][conv(b[j])],
						max(dp[i][j-1]+mat[conv(b[j])][conv('-')],
							dp[i-1][j]+mat[conv('-')][conv(a[i])]));
			}
		}
		printf("%d\n",dp[la][lb]);
	}
	return 0;
}

