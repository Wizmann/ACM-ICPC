//Result:2012-07-30 14:35:05	 Accepted	3626	C++	40	284	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 110
#define DAY 220
#define pb push_back

struct node
{
	int dest,cost;
	node(){}
	node(int idest,int icost)
	{
		dest=idest;
		cost=icost;
	}
};

int gold[SIZE];
vector<node> g[SIZE];
int dp[SIZE][DAY];
int n,k,m;
int tmp[DAY];

void dfs(int now=k,int father=-1)
{
	dp[now][0]=gold[now];
	for(int i=0;i<(int)g[now].size();i++)
	{
		int next=g[now][i].dest;
		int cost=g[now][i].cost;
		if(next!=father) dfs(next,now);
		else continue;
		
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=m;i++)
		{
			for(int j=0;i+j+2*cost<=m;j++)
			{
				int val=i+j+2*cost;
				tmp[val]=max(tmp[val],dp[now][i]+dp[next][j]);
			}
		}
		for(int i=0;i<=m;i++) dp[now][i]=max(dp[now][i],tmp[i]);
	}
}

int main()
{
	freopen("e.txt","r",stdin);
	int a,b,c;
	while(input(n))
	{
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<n;i++) scanf("%d",gold+i);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			a--;b--;
			g[a].pb(node(b,c));
			g[b].pb(node(a,c));
		}
		scanf("%d%d",&k,&m);
		k--;
		dfs();
		int ans=-1;
		for(int i=0;i<=m;i++)
		{
			ans=max(ans,dp[k][i]);
		}
		print(ans);			
	}
	return 0;
}
