#include <stdio.h>
#include <string.h>

#define N 300

unsigned char dp[N][N];

inline int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	char a[N],b[N];
	int la,lb;
	while(scanf("%s%s",a,b)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		la=strlen(a);
		lb=strlen(b);
		
		int ans=0;
		
		for(int i=1;i<=la;i++)
		{
			for(int j=1;j<=lb;j++)
			{
				if(a[i-1]==b[j-1])
				{
						dp[i][j]=dp[i-1][j-1]+1;
						if(dp[i][j]>ans) ans=dp[i][j];
				}
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}