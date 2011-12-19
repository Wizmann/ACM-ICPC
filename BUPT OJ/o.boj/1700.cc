#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

#define SIZE 10010
#define pb push_back

using std::vector;

int n,m,sum;
int money[SIZE];
vector<int> g[SIZE];
char visit[SIZE];

void init()
{
	for(int i=0;i<n;i++) g[i].clear();
	memset(money,0,sizeof(money));
	memset(visit,0,sizeof(visit));
}

void dfs(int p)
{
	sum+=money[p];
	visit[p]=1;
	for(int i=0;i<(int)g[p].size();i++)
	{
		if(!visit[g[p][i]]) dfs(g[p][i]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<n;i++) scanf("%d",&money[i]);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			g[a].pb(b);
			g[b].pb(a);
		}
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			sum=0;
			if(!visit[i]) dfs(i);
			
			if(sum)
			{
				flag=false;
				break;
			}
		}
		if(flag) puts("POSSIBLE");
		else puts("IMPOSSIBLE");
	}
	return 0;
}
