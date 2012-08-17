//Result:2012-08-15 10:46:57	Accepted	4360	218MS	724K	2765 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE (1500<<2)

typedef long long llint;

struct node
{
	int dest,cost;
	node(){}
	node(int idest,int icost)
	{
		dest=idest;
		cost=icost;
	}
};

inline int conv(char x)
{
	if(x=='L') return 0;
	else if(x=='O') return 1;
	else if(x=='V') return 2;
	else return 3;
}

vector<node> g[SIZE];
int n,m;
const int ROOT=0;
const llint INF=1LL<<58;

void spfa(int st,int end,llint &mincost,int &maxlove)
{
	llint dis[SIZE];
	int love[SIZE];
	fill(dis,dis+SIZE,INF);
	memset(love,0,sizeof(love));
	queue<int> q;
	bitset<SIZE> visit;
	q.push(st);
	dis[st]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;

		int gold=0;
		if(now%4==conv('E')) gold=1;

		for(int i=0;i<(int)g[now].size();i++)
		{
			node u=g[now][i];
			int next=u.dest;
			int cost=u.cost;

			if(dis[next]==dis[now]+cost)
			{
				if(love[next]<love[now]+gold)
				{
					love[next]=love[now]+gold;
					if(!visit[next])
					{
						visit[next]=1;
						q.push(next);
					}
				}
			}
			else if(dis[next]>dis[now]+cost)
			{
				dis[next]=dis[now]+cost;
				love[next]=love[now]+gold;
				if(!visit[next])
				{
					visit[next]=1;
					q.push(next);
				}
			}
		}
	}
	mincost=dis[end];
	maxlove=love[end];
}

inline void addEdge(int a,int b,int val)
{
	//print(a<<' '<<b<<' '<<val);
	g[a].push_back(node(b,val));
}

void show(llint mincost,int maxlove)
{
	if(mincost>=INF)
	{
		puts("Binbin you disappoint Sangsang again, damn it!");
	}
	else
	{
		printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",mincost,maxlove);
	}
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,a,b,c;
	char cmd[5];
	input(T);
	int cas=1;
	llint mindis[10];
	while(T--)
	{
		printf("Case %d: ",cas++);
		input(n>>m);
		fill(mindis,mindis+10,INF);
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%s",&a,&b,&c,cmd);
			int now=conv(*cmd);
			int pre=(now+3)%4;
			addEdge((a<<2)+pre,(b<<2)+now,c);
			addEdge((b<<2)+pre,(a<<2)+now,c);
			mindis[conv(*cmd)]=min(mindis[conv(*cmd)],(llint)c);
		}
		llint minCost;
		int maxLove;
		if(n==1)
		{
			minCost=0;
			for(int i=0;i<4;i++) minCost+=mindis[i];
			show(minCost,1);
		}
		else
		{
			addEdge(ROOT,(1<<2)+conv('E'),0);
			spfa(ROOT,(n<<2)+conv('E'),minCost,maxLove);
			show(minCost,maxLove);
		}		
	}
	return 0;
}
