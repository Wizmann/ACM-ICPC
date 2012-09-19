//Result:2012-09-17 15:32:59	Accepted	4289	31MS	1256K	2183 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define EDGE 151200
#define INF 0x3f3f3f3f

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

int n,m;
int source,sink;
int ind;
int head[SIZE];
edge g[EDGE];
int sz;



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
	int a,b;
	while(input(n>>m))
	{
		init();
		scanf("%d%d",&source,&sink);
		source--;sink--;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			addEdge(i*2,i*2+1,a);
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			addEdge(a*2+1,b*2,INF);
			addEdge(b*2+1,a*2,INF);
		}
		sz=n*2;
		print(sap(source*2,sink*2+1));
	}
	return 0;
}
			
		


