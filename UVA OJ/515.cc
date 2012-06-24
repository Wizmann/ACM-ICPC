//Result:515	King	Accepted	C++	0.108	2012-06-22 13:29:36
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 1<<30

struct node
{
	int dest,cost;
	
	node(){}
	node(int i_dest,int i_cost)
	{
		dest=i_dest;
		cost=i_cost;
	}
};


vector<node> g[SIZE];
int n,m;
int dis[SIZE],num[SIZE];

bool spfa()
{
	queue<int> q;
	bitset<SIZE> visit;
	
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	dis[0]=0;
	q.push(0);
	visit[0]=1;
	memset(num,0,sizeof(num));
	num[0]++;
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
					q.push(next);
					num[next]++;
					if(num[next]>n+2) return 0;
					visit[next]=1;
				}
			}
		}
	}
	return 1;
}
int main()
{
	freopen("j.txt","r",stdin);
	int a,b,c;
	char cmd[5];
	while(scanf("%d",&n)!=EOF && n)
	{
		n++;
		scanf("%d",&m);
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%s%d",&a,&b,cmd,&c);
			if(*cmd=='g') g[a+b+1].push_back(node(a,-1-c));
			else g[a].push_back(node(a+b+1,c-1));
		}
		for(int i=1;i<=n;i++) g[0].push_back(node(i,0));
		
		if(spfa()) puts("lamentable kingdom");
		else puts("successful conspiracy");
	}
	return 0;
}
			
	
