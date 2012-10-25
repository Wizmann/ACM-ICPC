#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
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
int ind=0;
int head[SIZE];

edge g[SIZE<<2];

void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
}

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
	for(int i=1;i<=n+1;i++)
	{
		cur[i]=head[i];
		gap[i]=dis[i]=0;
	}
	gap[st]=n+1;
	int u=pre[st]=st;

	while(dis[st]<n)
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
		int mindis=n+1;
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


int main()
{
	freopen("input.txt","r",stdin);
	int T;
	int a,b,c;
	input(T);
	while(T--)
	{
		init();
		input(n>>m);
		int lptr=INF,rptr=-INF;
		int st,end;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a<=lptr)
			{
				st=i;
				lptr=a;
			}
			if(a>=rptr)
			{
				end=i;
				rptr=b;
			}
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		print(sap(st,end));
	}
	return 0;
}



