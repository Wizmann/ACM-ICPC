//Result:4766	Gold Mines	Accepted	C++	4.056	2012-10-13 04:57:14
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 1024
#define EDGE 500000
#define INF 0x3f3f3f3f

struct edge
{
	int dest,flow,next,cost;
	edge(){}
	edge(int idest,int iflow,int icost,int inext)
	{
		dest=idest;flow=iflow;
		cost=icost;next=inext;
	}
};

edge g[EDGE];
int ind;
int head[NODE],pre[NODE];
int dis[NODE];
char visit[NODE];
int n,m;


inline void _addEdge(int st,int end,int flow,int cost)
{
	g[ind]=edge(end,flow,cost,head[st]);
	head[st]=ind++;
}

inline void addEdge(int st,int end,int flow,int cost)
{
	_addEdge(st,end,flow,cost);
	_addEdge(end,st,0,-cost);
}

void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
}

int spfa(int source,int sink)
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	memset(visit,0,sizeof(visit));
	pre[source]=-1;
	q.push(source);
	visit[source]=1;
	dis[source]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].dest;
			int cost=g[i].cost;
			int flow=g[i].flow;

			if(flow>0 && dis[next]>dis[now]+cost)
			{
				dis[next]=dis[now]+cost;
				if(!visit[next])
				{
					q.push(next);
					visit[next]=1;
				}
				pre[next]=i;
			}
		}
	}
	return dis[sink];
}

void MinCostMaxFlow(int source,int sink,int &maxflow,int &mincost)
{
	int flow;
	maxflow=0;mincost=0;
	while(1)
	{
		int cost=spfa(source,sink);
		if(cost>=INF) break;
		flow=INF;
		int now=sink;
		while(now!=source)
		{
			flow=min(flow,g[pre[now]].flow);
			now=g[pre[now]^1].dest;
		}
		maxflow+=flow;
		mincost+=flow*cost;
		now=sink;
		while(now!=source)
		{
			g[pre[now]].flow-=flow;
			g[pre[now]^1].flow+=flow;
			now=g[pre[now]^1].dest;
		}
	}
}

pair<int,int> cnc[NODE*NODE];
int land[NODE],price[NODE];

int check(int x,int K)
{
	int sum=0;
	for(int i=0;i<2*K;i++) sum+=x&(1<<i)?1:0;
	return sum==K;
}

void makeG(int x,int K,int source,int sink)
{
	init();
	for(int i=0;i<m;i++)
	{
		int a=cnc[i].first;
		int b=cnc[i].second;
		addEdge(a*2+1,b*2,INF,0);
		addEdge(b*2+1,a*2,INF,0);
	}
	for(int i=0;i<n;i++)
	{
		addEdge(i*2,i*2+1,1,price[i]);
	}
	for(int i=0;i<K*2;i++)
	{
		if(x&(1<<i)) addEdge(source,land[i]*2,1,0);
		else addEdge(land[i]*2+1,sink,1,0);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b,K;
	input(T);
	while(T--)
	{
		input(n>>m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			cnc[i]=make_pair(a,b);
		}
		scanf("%d",&K);
		int all4one=0;
		for(int i=0;i<2*K;i++)
		{
			scanf("%d",land+i);
			all4one|=(1<<i);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",price+i);
		}
		int ans=INF;
		int maxflow,mincost;
		int source=2*n+2,sink=2*n+3;
		char ok[1<<8];
		memset(ok,0,sizeof(ok));
		for(int i=0;i<(1<<(2*K));i++)
		{
			if(!ok[i] && !check(i,K)) continue;
			ok[i]=ok[i^all4one]=1;
			makeG(i,K,source,sink);
			MinCostMaxFlow(source,sink,maxflow,mincost);
			if(maxflow==K) ans=min(ans,mincost);
		}
		if(ans>=INF) puts("-1");
		else
		{
			ans=-ans;
			for(int i=0;i<n;i++) ans+=price[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}

