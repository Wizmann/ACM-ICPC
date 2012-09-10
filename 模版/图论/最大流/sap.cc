#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define EDGE 5120
#define SOURCE 0
#define SINK m+n+1
#define INF 1<<28

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
int n,m,p;

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

void init()
{
	memset(head,-1,sizeof(head));
	memset(g,0,sizeof(g));
	ind=0;
