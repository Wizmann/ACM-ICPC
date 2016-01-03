#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define SIZE (222*222*10)
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SOURCE 0
#define SINK (n*m*2+1)
#define INF 1<<30
#define SINKNODE sz-2

typedef long long llint;

typedef struct node
{
	int from,dest,cost;
	int flow,next;
	
	inline void setnode(int f,int a,int b,int c,int d)
	{
		from=f;dest=a;cost=b;flow=c;next=d;
	}
}node;

node g[SIZE];
int header[SIZE];
int n,m;
int sz;
int dis[SIZE],pre[SIZE];

void addedge(int from,int to,int flow,int cost)
{
	g[sz].setnode(from,to,cost,flow,header[from]);
	header[from]=sz;
	sz++;
	g[sz].setnode(to,from,-cost,0,header[to]);
	header[to]=sz;
	sz++;
}

bool bellman_ford()//Bellman_ford找最大费用增广路
{
	memset(pre,-1,sizeof(pre));
	memset(dis,-1,sizeof(dis));
	dis[SOURCE]=0;
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=SOURCE;i<=SINK;i++)
		{
			if(dis[i]<0) continue;
			else
			{
				int pos=header[i];
				while(pos!=-1)
				{
					if(g[pos].flow>0 && dis[i]+g[pos].cost>dis[g[pos].dest])
					{
						dis[g[pos].dest]=dis[i]+g[pos].cost;
						pre[g[pos].dest]=pos;
						flag=true;
					}
					pos=g[pos].next;
				}
			}
		}
	}
	return dis[SINK]!=-1;
}


int maxCostFlow()//最大费用流
{
	int now=SINK,c=0,minflow=INF;
	while(bellman_ford())
	{
		now=pre[SINK];
		while(now!=-1)
		{
			minflow=min(minflow,g[now].flow);
			now=pre[g[now].from];
		}
		now=pre[SINK];
		while(now!=-1)
		{
			g[now].flow-=minflow;
			g[now^1].flow+=minflow;
			c+=minflow*g[now].cost;
			now=pre[g[now].from];
		}
		//print(c);
	}
	return c;
}

int main()
{
	int t;
	while(input(m>>n))
	{
		memset(g,-1,sizeof(g));
		memset(header,-1,sizeof(header));
		sz=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				input(t);
				int u=(i-1)*m+j;
				int v=u+n*m;   
				addedge(u,v,1,t);
				addedge(u,v,2,0);
				
				if(i<n) addedge(v,u+m,2,0);
				if(j<m) addedge(v,u+1,2,0);
			}
		}
		addedge(SOURCE,1,2,0);            
		addedge(2*n*m,SINK,2,0);
		print(maxCostFlow());
	}
	return 0;
}
