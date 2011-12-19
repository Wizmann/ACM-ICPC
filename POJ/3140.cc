//Result:wizmann	3140	Accepted	7728K	735MS	G++	1091B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back
#define SIZE 100010
#define abs(x) ((x)>0?(x):-(x))

long long n,c;
long long all;
vector<long long> g[SIZE];
long long ans;
long long dp[SIZE];
char visit[SIZE];

void baumDP(int pos)
{
	visit[pos]=1;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int t=g[pos][i];
		if(!visit[t])
		{
			baumDP(t);
			dp[pos]+=dp[t];
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	long long a,b;
	while(scanf("%lld%lld",&n,&c)==2)
	{
		all=0;
		if(n+c==0) break;
		memset(visit,0,sizeof(visit));
		memset(dp,0,sizeof(dp));
		ans=0x7ffffffffffffll;
		for(int i=1;i<=n;i++) g[i].clear();
		printf("Case %d: ",cas++);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",dp+i);
			all+=*(dp+i);
		}
		while(c--)
		{
			scanf("%lld%lld",&a,&b);
			g[a].pb(b);
			g[b].pb(a);
		}
		baumDP(1);
		for(int i=1;i<=n;i++) ans=min(ans,abs(all-2*dp[i]));
		printf("%lld\n",ans);
	}
	return 0;
}


