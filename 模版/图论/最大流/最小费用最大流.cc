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

