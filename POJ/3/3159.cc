//Result:wizmann	3159	Accepted	2536K	657MS	C++	1365B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 150000
#define N 30005
#define INF 0x3f3f3f3f

struct node
{
	int dest,cost;
	int next;

	node(){}
	node(int i_dest,int i_cost,int i_next)
	{
		dest=i_dest;cost=i_cost;
		next=i_next;
	}
};


int n,m,ind;
char visit[N];

int spfa(int *head,node *g,int x,int y)
{
	int dis[N];
	deque<int> q;
	for(int i=0;i<N;i++) dis[i]=INF;
	q.push_back(x);
	dis[x]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop_front();
		visit[now]=0;
		int ptr=head[now];
		while(ptr!=-1)
		{
			int dest=g[ptr].dest;
			int cost=g[ptr].cost;
			int next=g[ptr].next;

			if(dis[dest]>dis[now]+cost)
			{
				dis[dest]=dis[now]+cost;
				if(!visit[dest])
				{
					visit[dest]=1;
					q.push_front(dest);
				}
			}
			ptr=next;
		}
	}
	return dis[y];
}

int main()
{
	freopen("c.txt","r",stdin);
	int a,b,c;
	int head[N];
	node g[SIZE];
	ind=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		int ptr=head[a];
		g[ind]=node(b,c,ptr);
		head[a]=ind;
		ind++;
	}
	printf("%d\n",spfa(head,g,1,n));
	//print(max(spfa(1,n),spfa(n,1)));
	return 0;
}
