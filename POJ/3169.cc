//Result:wizmann	3169	Accepted	1348K	704MS	G++	1387B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define INF 1<<30
#define pb push_back

struct node
{
	int dest,cost;

	node(){}
	node(int i_dest,int i_cost)
	{
		dest=i_dest;cost=i_cost;
	}
};

deque<node> g[SIZE];
int n,ml,md;//make love?

int spfa()
{
	int dis[SIZE],inque[SIZE];
	bitset<SIZE> visit;
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	dis[1]=0;
	visit[1]=1;
	
	memset(inque,0,sizeof(inque));
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int dest=g[now][i].dest;
			int cost=g[now][i].cost;

			if(dis[dest]>dis[now]+cost)
			{
				dis[dest]=dis[now]+cost;
				if(!visit[dest])
				{
					visit[dest]=1;
					q.push(dest);
					inque[dest]++;
					if(inque[dest]>n+2) return -1;
				}
			}
		}
	}
	return dis[n]<INF?dis[n]:-2;
}

int main()
{
	freopen("b.txt","r",stdin);
	int a,b,c;
	input(n>>ml>>md);
	for(int i=1;i<n;i++)
	{
		g[i+1].pb(node(i,0));
	}
	for(int i=0;i<ml;i++)
	{
		input(a>>b>>c);
		g[a].pb(node(b,c));
	}
	for(int i=0;i<md;i++)
	{
		input(a>>b>>c);
		g[b].pb(node(a,-c));
	}
	print(spfa());
	return 0;
}


