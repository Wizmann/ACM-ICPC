//Result:1205 	Accepted	38MS	388K	G++	2836B	2011-10-24 12:00:27	Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define mul(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define elif else if

#define INF 1<<30
#define SIZE 3000
#define SOURCE 0
#define SINK (m+n+1)

typedef struct edge
{
	int v,flow,cost,next;
}edge;

edge array[SIZE];
int pre[SIZE];
int tot,m,n;
int start[SIZE];

void add(int u,int v,int flow,int cost)
{
	array[tot].v=v;
	array[tot].flow=flow;
	array[tot].cost=cost;
	array[tot].next=start[u];
	start[u]=tot++;
}
void addEdge(int u,int v,int flow,int cost)
{
	add(u,v,flow,cost);
	add(v,u,0,-cost);
}


void init()
{
	memset(start,-1,sizeof(start));
	tot = 0;
}


int spfa()
{
	queue<int> q;
	int dis[SIZE],cost;
	bitset<SIZE> visit;
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	dis[SOURCE]=0;
	q.push(SOURCE);
	pre[SOURCE]=-1;
	visit[SOURCE]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		visit[u]=0;
		for(int i=start[u];i!=-1;i=array[i].next)
		{
			int v;
			cost=array[i].cost;
			v=array[i].v;
			if(array[i].flow>0 && dis[v]>dis[u]+cost)
			{
				dis[v]=dis[u]+cost;
				if(!visit[v])
				{
					q.push(v);
					visit[v]=1;
				}
				pre[v]=i;
			}
		}
	}
	return dis[SINK];
}
int ek()
{
	int flow,cost;	
	int maxflow=0,mincost=0;
	while(1)
	{
		cost=spfa();
		if(cost>=INF) break;
		flow=INF;
		int now=SINK;
		while(now!=SOURCE)
		{
			flow=min(flow,array[pre[now]].flow);
			now=array[pre[now]^1].v;
		}
		maxflow+=flow;
		mincost+=flow*cost;
		now=SINK;
		while(now!=SOURCE)
		{
			array[pre[now]].flow-=flow;
			array[pre[now]^1].flow+=flow;
			now=array[pre[now]^1].v;
		}
	}
	if(maxflow<m) return -1;
	return mincost;
}

int main()
{
	freopen("input.txt","r",stdin);
	int cost[1024];
	char buffer[512];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(cost,0,sizeof(cost));
		memset(array,0,sizeof(array));
		memset(pre,-1,sizeof(pre));
		init();
		for(int i=1;i<=n;i++)
		{
			input(buffer);
			for(int j=1;j<=m;j++)
			{
				if(buffer[j-1]=='Y') addEdge(i,n+j,1,0);
			}
		}
		for(int i=1;i<=m;i++) addEdge(n+i,n+m+1,1,0);
		for(int i=1;i<=n;i++) input(cost[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) addEdge(SOURCE,i,1,cost[i]*(j*j-(j-1)*(j-1)));
			//第一条边是1*1 第二条边是2*2-1*1  流量都为1
			//所以流量的Cost总和就是n^2
		}
		int ans=ek();
		print(ans);
	}
	return 0;
}
