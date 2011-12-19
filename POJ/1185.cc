//Result:wizmann	1185	Accepted	6304K	344MS	G++	1170B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>

//N行M列，N<=100,M<=10

#define M 15
#define N 105
#define max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) ((x)&(-x))

int status[120],sum[120],mem[N][120][120];
int g[N];
int n,m,pad;

void init_status()
{	
	pad=0;
	
	for(int i=0;i<(1<<m);i++)
	{
		if(!((i<<1)&i) && !((i<<2)&i) && !((i>>1)&i) && !((i>>2)&i))
		{
			status[pad]=i;

			for(int j=i;j>0;j-=lowbit(j)) sum[pad]++;
			pad++;
		}
	}
}

int dp(int pos,int now,int last)
{
	int ans=0;
	int t=(status[now]|status[last]);
	if(mem[pos][now][last]!=-1) return mem[pos][now][last];

	if(pos==1) return mem[pos][now][last]=sum[now];

	for(int i=0;i<pad;i++)
	{
		if(!(status[i]&t || g[pos-2]&status[i]))
		{
			int k=dp(pos-1,last,i);
			ans=max(ans,k);
		}
	}
	return mem[pos][now][last]=ans+sum[now];
}

int main()
{
	freopen("input.txt","r",stdin);
	char ch[M];
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	memset(mem,-1,sizeof(mem));
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		for(int j=0;j<m;j++)
		{
			if(ch[j]=='H') g[i]+=(1<<j);
		}
	}

	init_status();
	printf("%d\n",dp(n+2,0,0));
	return 0;
}
