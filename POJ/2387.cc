//Result:wizmann    2387	Accepted	344K	32MS	C++	1291B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 1024;
const int INF = 0x3f3f3f3f;

struct node
{
    int dest,cost;
	node(){}
	node(int idest,int icost)
	{
		dest = idest;
		cost = icost;
	}
};

int dis[SIZE];
char visit[SIZE];
vector<node> g[SIZE];
int n,m;

void init()
{
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(dis,INF,sizeof(dis));
	memset(visit,0,sizeof(visit));
}

void add_path(int a,int b,int c)
{
	g[a].push_back(node(b,c));
	g[b].push_back(node(a,c));
}

int spfa()
{
	queue<int> q;
	dis[n]=0;
	q.push(n);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		visit[now]=0;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next= g[now][i].dest;
			int cost= g[now][i].cost;
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
	return dis[1];
}

int main()
{
	int a,b,c;
	while(input(m>>n))
	{
		init();
		for(int i=0;i<m;i++)
		{
			input(a>>b>>c);
			add_path(a,b,c);
		}
		print(spfa());
	}
	return 0;
}
