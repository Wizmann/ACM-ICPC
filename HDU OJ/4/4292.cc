//Result:2012-09-17 15:34:56	Accepted	4292	140MS	2428K	2474 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define EDGE 180000
#define INF 0x3f3f3f3f
#define SOURCE 0
#define SINK (f+n*2+d+1)

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

int n,f,d;
int sz,ind;
int head[SIZE];
edge g[EDGE];


void addEdge(int st,int end,int flow)
{
	g[ind]=edge(end,flow,head[st]);
	head[st]=ind++;

	g[ind]=edge(st,0,head[end]);
	head[end]=ind++;
}

int sap(int st,int end)
{
	int pre[SIZE],cur[SIZE],dis[SIZE],gap[SIZE];
	int flow=0;
	int aug=INF;
	for(int i=0;i<SIZE;i++)
	{
		cur[i]=head[i];
		gap[i]=dis[i]=0;
	}
	gap[st]=sz+1;
	int u=pre[st]=st;

	while(dis[st]<sz)
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
				if(u==end)
				{
					flow+=aug;
					while(u!=st)
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
		int mindis=sz+1;
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


void init()
{
	ind=0;
	memset(head,-1,sizeof(head));
}



int main()
{
	freopen("input.txt","r",stdin);	
	char cmd[256];
	int a;
	while(input(n>>f>>d))
	{
		init();
		for(int i=1;i<=f;i++)
		{
			scanf("%d",&a);
			addEdge(SOURCE,i,a);
		}
		for(int i=1;i<=d;i++)
		{
			scanf("%d",&a);
			addEdge(f+n*2+i,SINK,a);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++)
			{
				if(cmd[j]=='Y')
				{
					addEdge(j+1,f+(i*2)-1,1);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			addEdge(f+i*2-1,f+i*2,1);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++)
			{
				if(cmd[j]=='Y')
				{
					addEdge(f+(i*2),f+2*n+j+1,1);
				}
			}
		}
		sz=SINK+1;
		print(sap(SOURCE,SINK));
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////
//Dinic算法

//Result:2012-09-17 16:05:11	Accepted	4292	125MS	3080K	3398 B	G++	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 1024
#define EDGE 180000
#define INF 0x3f3f3f3f
#define SOURCE 0
#define SINK (f+n*2+d+1)

struct node
{
    int st,end,flow,next;
    node(){}
    node(int ist,int iend,int iflow,int inext)
    {
		st=ist;end=iend;flow=iflow;next=inext;
	}
};

node edge[EDGE];
int head[NODE];
int ind;
int source,sink;

void addEdge(int s,int e,int f)
{
    edge[ind]=node(s,e,f,head[s]);
    head[s] = ind ++;
    
    edge[ind]=node(e,s,0,head[e]);
    head[e] = ind ++;
}

namespace dinic
{
	int level[NODE],cur_head[NODE];
	int edge_stack[(NODE<<2)+(EDGE<<2)];
	int stack_top;
	
	int BFS()
	{
		memset(level,-1,sizeof(level));
		queue<int> q;
		q.push(source);
		level[source] = 0;
		while(!q.empty())
		{
			int cur =q.front();
			q.pop();
			for(int e=head[cur]; e!=-1; e=edge[e].next)
			{
				int next = edge[e].end;
				if(edge[e].flow && level[next] == -1 ){
					q.push(next);
					level[next] = level[cur] + 1;
				}
			}
		}
		return level[sink] != -1;
	}

	int DFS()
	{
		int index,min_limit,e;
		int res = 0;

		memcpy(cur_head,head,sizeof(head));                          
		int cur = source;                                                   

		stack_top = 0;
		while(stack_top>=0)
		{            
			if(cur==sink)
			{                                       
				min_limit = INF;
				for(int i=stack_top-1;i>=0;i--)
				{
					e=edge_stack[i];
					if(edge[e].flow<=min_limit)
					{
						min_limit = edge[e].flow;
						index = i;
					}
				}
				res+=min_limit;                                   

				for(int i=stack_top-1;i>=0;i--)
				{               
					e = edge_stack[i];
					edge[e].flow -= min_limit;
					edge[e^1].flow += min_limit;
				}
				stack_top = index;                                    
				cur = edge[edge_stack[stack_top]].st;          
			}
			for(e =cur_head[cur]; e!=-1; e=edge[e].next)
			{  
				cur_head[cur] = e;
				int next = edge[e].end;
				if( edge[e].flow && level[next] == level[cur] + 1 )
				{
					edge_stack[stack_top ++]  = e;
					cur = next;
					break;
				}
			}
			if(e==-1)
			{                                           
				stack_top--;
				level[cur]=-2;                                    
				cur=edge[edge_stack[stack_top]].st;               
			}
		}
		return res;
	}
}

void init()
{
	ind=0;
	memset(head,-1,sizeof(head));
}


int main()
{
	freopen("input.txt","r",stdin);	
	char cmd[256];
	int a,n,f,d;
	while(input(n>>f>>d))
	{
		init();
		for(int i=1;i<=f;i++)
		{
			scanf("%d",&a);
			addEdge(SOURCE,i,a);
		}
		for(int i=1;i<=d;i++)
		{
			scanf("%d",&a);
			addEdge(f+n*2+i,SINK,a);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++) if(cmd[j]=='Y')
			{
				addEdge(j+1,f+(i*2)-1,1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			addEdge(f+i*2-1,f+i*2,1);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			for(int j=0;cmd[j];j++) if(cmd[j]=='Y')
			{
				addEdge(f+(i*2),f+2*n+j+1,1);
			}
		}
		source=SOURCE;
		sink=SINK;
		int res = 0;
        while(dinic::BFS()) res+=dinic::DFS();
        printf("%d\n",res);
	}
	return 0;
}


