//Result:wizmann	1947	Accepted	800K	32MS	G++	1143B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,ask;
int father[155];
int dp[155][155];
vector<int> g[155];

#define pb push_back
#define INF 1<<20
#define ROOT 1
#define print(x) cout<<x<<endl

int dfs(int x)
{
	int sz=g[x].size();
	for(int i=0;i<sz;i++) dfs(g[x][i]);
	dp[x][1]=sz;
	for(int i=0;i<sz;i++)
	{
		for(int j=ask-1;j>0;j--)
		{
			if(dp[x][j]!=INF)
			{
				for(int k=1;j+k<=ask;k++) dp[x][j+k]=min(dp[x][j]+dp[g[x][i]][k]-1,dp[x][j+k]);
			}
		}
	}
	//类似于0/1背包，每一个子树都是一个“重物”
	return dp[x][ask];
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&ask)!=EOF)
	{	
		for(int i=0;i<=n;i++) g[i].clear();
		memset(father,0,sizeof(father));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=ask;j++) dp[i][j]=INF;
		}
		int a,b;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			father[b]=a;
			g[a].pb(b);
		}
		int root=ROOT;
		while(father[root]!=0) root=father[root];
		int ans=dfs(root);

		for(int i=1;i<=n;i++)
		{
			if(i!=root && dp[i][ask]<ans) ans=dp[i][ask]+1;
		}

		print(ans);
	}
	return 0;
}

