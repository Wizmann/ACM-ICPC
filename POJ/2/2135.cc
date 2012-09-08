//Result:wizmann	2135	Accepted	1476K	219MS	G++	1944B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 1024
#define SIZE 60000
#define SOURCE 0
#define SINK (n+1)
#define INF 1<<30

struct node
{
	int st,dest;
	int flow,cost;
	int next;

	node(){}
	node(int i_st,int i_dest,int i_flow,int i_cost,int i_next)
	{
		st=i_st;dest=i_dest;
		flow=i_flow;cost=i_cost;
		next=i_next;
	}
};

node array[SIZE];
int head[N];
int pre[N];
int dis[N];

int n,m;
int ind;

void addEdge(int st,int end,int flow,int cost)
{
	array[ind]=node(st,end,flow,cost,head[st]);
	head[st]=ind++;

	array[ind]=node(end,st,0,-cost,head[end]);
	head[end]=ind++;
}


bool spfa()
{
	bitset<N> visit;
	memset(pre,-1,sizeof(pre));
	queue<int> q;
	visit.reset();
	
	q.push(SOURCE);
	for(int i=0;i<N;i++) dis[i]=INF;
	visit[SOURCE]=1;
	dis[SOURCE]=0;

	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=false;
		for(int i=head[now];i!=-1;i=array[i].next)
		{
			int v=array[i].dest;
			if(array[i].flow!=0 && dis[v]>dis[now]+array[i].cost)
			{
				dis[v]=dis[now]+array[i].cost;
				pre[v]=i;

				if(!visit[v])
				{
					visit[v]=true;
					q.push(v);
				}
			}
		}
	}
	if(pre[SINK]==-1) return false;
	else return true;
}
int MinCostMaxFlow()
{
	int cost=0;
	int minflow;
	while(spfa())
	{
		minflow=INF;
		int now=pre[SINK];
		while(now!=-1)
		{
			minflow=min(minflow,array[now].flow);
			now=pre[array[now].st];
		}
		now=pre[SINK];
		while(now!=-1)
		{
			array[now].flow-=minflow;
			array[now^1].flow+=minflow;
			cost+=array[now].cost*minflow;
			now=pre[array[now].st];

		}
	}
	return cost;
}
	

int main()
{
	int a,b,c;
	while(input(n>>m))
	{
		ind=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
		{
			input(a>>b>>c);
			addEdge(a,b,1,c);
			addEdge(b,a,1,c);
		}
		addEdge(SOURCE,1,2,0);
		addEdge(n,SINK,2,0);

		printf("%d\n",MinCostMaxFlow());
	}
	return 0;
}
