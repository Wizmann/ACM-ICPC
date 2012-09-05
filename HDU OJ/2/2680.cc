//Result:2012-07-06 10:25:28	Accepted	2680	312MS	1192K	1376 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define SOURCE 0
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

vector<node> g[SIZE];
int n,m,end;

int spfa()
{
	bitset<SIZE> visit;
	int dis[SIZE];
	queue<int> q;
	for(int i=0;i<=n;i++) dis[i]=INF;
	q.push(SOURCE);
	visit[SOURCE]=1;
	dis[SOURCE]=0;

	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].dest;
			int cost=g[now][i].cost;

			if(dis[next]>dis[now]+cost)
			{
				dis[next]=dis[now]+cost;
				if(!visit[next])
				{
					visit[next]=1;
					q.push(next);
				}
			}
		}
	}
	return dis[end]<INF?dis[end]:-1;
}


int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(scanf("%d%d%d",&n,&m,&end)==3)
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a].pb(node(b,c));
			//g[b].pb(node(a,c));
		}
		input(a);
		for(int i=0;i<a;i++)
		{
			input(b);
			g[SOURCE].pb(node(b,0));
		}
		print(spfa());
	}
	return 0;
}


