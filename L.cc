#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 1<<28

struct CPoint
{
	int x,y,val;
	CPoint(){}
	CPoint(int ix,int iy,int ival)
	{
		x=ix;y=iy;val=ival;
	}
};

struct CEdge
{
	int dest,flow,cost,next;
	CEdge(){}
	CEdge(int idest,int iflow,int icost,int inext)
	{
		dest=idest;flow=iflow;cost=icost;next=inext;
	}
};

inline int pntDis(const CPoint &a,const CPoint &b)
{
	return abs(a.x-b.x)+abs(a.y-b.y)+1;
}

CPoint hause[SIZE],shell[SIZE];
int n,m;
int head[SIZE];
CEdge g[SIZE*SIZE*3];
int ind;
int pre[SIZE];

void _addEdge(int u,int v,int flow,int cost)
{
	g[ind]=CEdge(v,flow,cost,head[u]);
	head[u]=ind++;
}

void addEdge(int u,int v,int flow,int cost)
{
	_addEdge(u,v,flow,cost);
	_addEdge(v,u,0,-cost);
}

int spfa(int source,int sink)
{
	queue<int> q;
	int dis[SIZE];
	char visit[SIZE]={0};
	fill(dis,dis+SIZE,INF);
	dis[source]=0;
	q.push(source);
	pre[source]=-1;
	visit[source]=-1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].next;
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

int MinCostMaxFlow(int source,int sink)
{
	int flow;
	int maxflow=0,mincost=0;

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
	return mincost;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(input(n>>m))
	{
		memset(head,-1,sizeof(head));
		ind=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			hause[i]=CPoint(a,b,c);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			shell[i]=CPoint(a,b,c);
		}

		for(int i=0;i<n;i++)
		{
			addEdge(0,i+1,hause[i].val,0);
			for(int j=0;j<m;j++)
			{
				addEdge(i+1,n+j+1,INF,pntDis(hause[i],shell[j]));
			}
		}

		for(int i=0;i<m;i++)
		{
			addEdge(n+i+1,n+m+1,shell[i].val,0);
		}

		int sum=MinCostMaxFlow(0,n+m+1);
		print(sum);
	}
	return 0;
}




