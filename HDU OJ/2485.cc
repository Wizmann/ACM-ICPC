//Result:2012-08-19 20:46:32	Accepted	2485	62MS	4488K	2695 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define EDGE (SIZE<<4)

const int INF=0x3f3f3f3f;

struct edge
{
	int dest,flow,next;
	edge(){}
	edge(int idest,int iflow,int inext)
	{
		dest=idest;
		flow=iflow;
		next=inext;
	}
};

int head[SIZE];
edge g[EDGE];
int ind;
int n,m,k;
int maze[SIZE][SIZE];

void add_edge(int st,int end,int flow)
{
	g[ind]=edge(end,flow,head[st]);
	head[st]=ind;
	ind++;

	g[ind]=edge(st,0,head[end]);
	head[end]=ind;
	ind++;
}

int sap()
{
	int pre[SIZE],cur[SIZE],dis[SIZE],gap[SIZE];
	int flow=0;
	int aug=INF;
	int SOURCE=1,SINK=n+n;
	for(int i=SOURCE;i<=SINK+1;i++)
	{
		cur[i]=head[i];
		gap[i]=dis[i]=0;
	}
	
	gap[SOURCE]=SINK+1;
	int u=pre[SOURCE]=SOURCE;
	
	while(dis[SOURCE]<=SINK)
	{
		bool flag=false;
		int pos=cur[u];
		while(pos!=-1)
		{
			int now=g[pos].dest;
			if(g[pos].flow>0 && dis[u]==dis[now]+1)
			{
				flag=true;
				if(g[pos].flow<aug) aug=g[pos].flow;
				pre[now]=u;
				u=now;
				if(u==SINK)
				{
					flow+=aug;
					while(u!=SOURCE)
					{
						u=pre[u];
						g[cur[u]].flow-=aug;
						g[cur[u]^1].flow+=aug;
					}
					aug=INF;
				}
				break;
			}
			cur[u]=pos=g[pos].next;
		}
		if(flag) continue;
		int mindis=SINK+1;
		for(int i=head[u];i!=-1;i=g[i].next)
		{
			int now=g[i].dest;
			if(g[i].flow>0 && dis[now]<mindis)
			{
				mindis=dis[now];
				cur[u]=i;
			}
		}
		gap[dis[u]]--;
		if(!gap[dis[u]]) break;
		dis[u]=mindis+1;
		gap[dis[u]]++;
		u=pre[u];
	}
	return flow;
}

void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(maze[j][i]<INF && maze[i][k]<INF)
				{
					maze[j][k]=min(maze[j][k],maze[j][i]+maze[i][k]);
				}
			}
		}
	}
}



int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d%d",&n,&m,&k)==3 && n+m+k)
	{
		ind=0;
		memset(head,-1,sizeof(head));
		memset(maze,0x3f,sizeof(maze));
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++) maze[i][j]=INF;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			maze[a][b]=1;
		}
		floyd();
		add_edge(1,1+n,INF);
		add_edge(n,n+n,INF);
		for(int i=2;i<n;i++)
		{
			if(maze[1][i]+maze[i][n]<=k)
			{
				add_edge(i,i+n,1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(maze[i][j]==1) add_edge(i+n,j,INF);
			}
		}
		int ans=sap();
		//if(ans>=INF) ans=0;
		print(ans);
	}
	return 0;
}


