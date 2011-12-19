//Result:wizmann	3280	Accepted	14016K	32MS	C++	684B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SIZE 2010
#define ALPHA 30

char str[SIZE];
int dp[SIZE][SIZE];
short cost[ALPHA];
int n,len;

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&len);
	scanf("%s",str);
	char tmp[3];
	for(int i=0;i<n;i++)
	{
		scanf("%s",tmp);
		int a,b;
		scanf("%d%d",&a,&b);
		cost[*tmp-'a']=min(a,b);
	}

	for(int i=0;i<len;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			dp[i][j]=min(dp[i][j+1]+cost[str[j]-'a'],dp[i-1][j]+cost[str[i]-'a']);
			if(str[i]==str[j]) dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
		}
	}
	printf("%d\n",dp[len-1][0]);
	return 0;
}
