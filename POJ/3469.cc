//Result:wizmann	3469	Accepted	19888K	2875MS	G++	2156B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20010
#define EDGE 200010
#define SOURCE 0
#define SINK n+1
#define INF 1<<25

struct edge
{
	int dest,flow,next;

	edge(){}
	edge(int i_dest,int i_flow,int i_next)
	{
		dest=i_dest;
		flow=i_flow;
		next=i_next;
	}
};

int header[SIZE];
edge g[EDGE<<2];
int ind;
int n,m;

void addEdge(int st,int end,int flow)
{
	g[ind]=edge(end,flow,header[st]);
	header[st]=ind;
	ind++;
	g[ind]=edge(st,0,header[end]);
	header[end]=ind;
	ind++;
}

int sap()
{
	int pre[SIZE],cur[SIZE],dis[SIZE],gap[SIZE];
	int flow=0;
	int aug=INF;
	for(int i=SOURCE;i<=SINK+1;i++)
	{
		cur[i]=header[i];
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
		for(int i=header[u];i!=-1;i=g[i].next)
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

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ind=0;
		memset(header,-1,sizeof(header));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			addEdge(SOURCE,i,a);
			addEdge(i,SINK,b);
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		print(sap());
	}
	return 0;
}
