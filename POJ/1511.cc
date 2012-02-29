//Result:wizmann	1511	Accepted	36112K	1829MS	G++	1787B
//SPFA
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define SIZE 1000001
#define START 1

typedef long long llint;

struct node
{
	int dest,w;
	int next;

	node(){}
	node(int i_dest,int i_w,int i_next)
	{
		dest=i_dest;
		w=i_w;
		next=i_next;
	}
};

int dis[SIZE];
node g[SIZE];
node revg[SIZE];
int list[SIZE];
int revlist[SIZE];

queue<int> q;
bitset<SIZE> visit;

int n,m;
int ind,revind;

void SPFA(node *graph,int* header)
{
	while(!q.empty()) q.pop();
	visit.reset();
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	q.push(START);
	dis[START]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int t=header[now];
		while(t!=-1)
		{
			int dest=graph[t].dest;
			if(dis[now]<INF && dis[now]+graph[t].w<dis[dest])
			{
				dis[dest]=dis[now]+graph[t].w;
				if(!visit[dest])
				{
					q.push(dest);
					visit[dest]=1;
				}
			}
			t=graph[t].next;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		ind=revind=0;
		memset(g,0,sizeof(g));
		memset(revg,0,sizeof(revg));
		memset(list,-1,sizeof(list));
		memset(revlist,-1,sizeof(revlist));
		while(!q.empty()) q.pop();
		visit.reset();
		input(n>>m);
		int from,to,cost;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&from,&to,&cost);
			g[ind]=node(to,cost,list[from]);
			list[from]=ind++;

			revg[revind]=node(from,cost,revlist[to]);
			revlist[to]=revind++;
		}
		llint ans=0;
		SPFA(g,list);
		for(int i=2;i<=n;i++) ans+=dis[i];
		SPFA(revg,revlist);
		for(int i=2;i<=n;i++) ans+=dis[i];
		print(ans);
	}
	return 0;
}
