//Result:wizmann	1515	Accepted	1376K	141MS	C++	1821B	2012-09-20 16:21:21
//给你一个无向公路网，让你改造一些道路为单向，使改造后的公路网成为一个强连通分量
//并输出公路网的结构

//首先使用边双连通分量，求出图中的桥，桥必须为双向的
//然后用DFS，求出最后的结果

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

vector<int> g[SIZE];
int n,m;
int dfn[SIZE],low[SIZE];
stack<int> st;
int bio[SIZE];
int lv,sum;
set<pair<int,int> > road;
char visit[SIZE];
char inst[SIZE][SIZE];

void init()
{
	lv=sum=0;
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	st=stack<int>();
	memset(bio,0,sizeof(bio));
	memset(visit,0,sizeof(visit));
	memset(inst,0,sizeof(inst));
}

void dfs(int x,int fa)
{
	for(int i=0;i<(int)g[x].size();i++) if(g[x][i]!=fa)
	{
		if(bio[x]==bio[g[x][i]] && !inst[x][g[x][i]])
		{
			printf("%d %d\n",g[x][i],x);
		}
		else if(!inst[x][g[x][i]])
		{
			printf("%d %d\n",x,g[x][i]);
			printf("%d %d\n",g[x][i],x);
		}
		inst[x][g[x][i]]=inst[g[x][i]][x]=1;
		if(!visit[g[x][i]])
		{
			visit[g[x][i]]=1;
			dfs(g[x][i],x);
		}
	}
}
			
void tarjan(int v,int pre)
{
	dfn[v]=low[v]=++lv;
	st.push(v);
	for(int i=0;i<(int)g[v].size();i++)
	{
		int u=g[v][i];
		if(u==pre) continue;
		if(!dfn[u])
		{
			tarjan(u,v);
			low[v]=min(low[v],low[u]);
		}
		else low[v]=min(low[v],dfn[u]);
	}

	if(low[v]==dfn[v])
	{
		int t;
		sum++;
		do
		{
			t=st.top();
			st.pop();
			bio[t]=sum;
		}while(t!=v);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int a,b,cas=1;
	while(input(n>>m) && n+m)//n为点数，m为边数,点的编号为[1..n]
	{
		printf("%d\n\n",cas++);
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i,-1);
		}
		dfs(1,-1);//输出强连通分量中需要连的边
		puts("#");
	}
	return 0;
}


