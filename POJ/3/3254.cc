//Result:wizmann	3254	Accepted	412K	0MS	G++	1036B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SIZE 15
#define MOD 100000000
#define lowbit(x) ((x)&(-x))

//(1 ≤ M ≤ 12; 1 ≤ N ≤ 12),M rows,N cols

int g[SIZE],m,n;
int pad;
int s[400],sum[400];
int dp[SIZE][400];

void init()
{
	pad=0;
	for(int i=0;i<(1<<n);i++)
	{
		if(!((i<<1)&i) && !((i>>1)&i))
		{
			s[pad]=i;
			for(int j=i;j>0;j-=lowbit(j)) sum[pad]++;
			pad++;
		}
	}
}

int dfs(int pos,int pre)
{
	int ans=0;
	if(dp[pos][pre]!=-1) return dp[pos][pre];
	if(pos==1) return dp[pos][pre]=1;

	for(int i=0;i<pad;i++)
	{
		if( !(g[pos-1]&s[i] || s[i]&s[pre]) )
		{
			int k=dfs(pos-1,i);
			ans=(ans+k)%MOD;
		}
	}
	return dp[pos][pre]=ans%MOD;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		int t;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&t);
			if(!t) g[i]|=(1<<j);
		}
	}
	init();
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(m+1,0)%MOD);
	return 0;
}
