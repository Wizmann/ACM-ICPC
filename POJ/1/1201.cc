#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010
#define INF 1<<25

struct node
{
	int dest,cost;
	int next;

	node(){}
	node(int i_dest,int i_cost,int i_next)
	{
		dest=i_dest;
		cost=i_cost;
		next=i_next;
	}
};

node g[SIZE<<2];
int head[SIZE];
int n,ind;
int START,END;
int dis[SIZE];

void addEdge(int st,int end,int cost)
{
	g[ind]=node(end,cost,head[st]);
	head[st]=ind++;
}

int SPFA()
{
	bitset<SIZE> visit;
	queue<int> q;
	visit.reset();
	q.push(START);
	for(int i=START;i<=END;i++) dis[i]=-INF;
	visit[START]=1;
	dis[START]=0;

	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;

		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int v=g[i].dest;
			if(dis[v]<dis[now]+g[i].cost)
			{
				dis[v]=dis[now]+g[i].cost;

				if(!visit[v])
				{
					visit[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[END];
}

int main()
{
	int a,b,c;
	while(input(n))
	{
		memset(head,-1,sizeof(head));
		ind=0;
		START=INF;END=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b+1,c);
			START=min(START,a);
			END=max(END,b+1);
		}
		for(int i=START;i<=END;i++)
		{
			addEdge(i,i+1,0);
			addEdge(i+1,i,-1);
		}

		print(SPFA());
	}
	return 0;
}
