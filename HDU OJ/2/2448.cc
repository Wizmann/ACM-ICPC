//Result:2012-09-03 11:56:58	Accepted	2448	343MS	1908K	2629 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 1<<25
#define pb push_back

struct node
{
	int next,cost;

	node(){}
	node(int inext,int icost)
	{
		next=inext;cost=icost;
	}
};

int n,m,k,p;
int ship[SIZE];
int dis[SIZE];

vector<node> g[SIZE];

void spfa(int st)
{
	queue<int> q;
	bitset<SIZE> visit;
	q.push(st);
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	dis[st]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].next;
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
}

inline void addEdge(int a,int b,int c)
{
	g[a].pb(node(b,c));
}


int slack;
int visx[SIZE],visy[SIZE];
int linky[SIZE];
int lx[SIZE],ly[SIZE];
int mp[SIZE][SIZE];

bool dfs(int x)
{
	visx[x]=1;
    for(int y=1;y<=n;y++)
    {
        if(visy[y]) continue;
        int t=lx[x]+ly[y]-mp[x][y];
        if(!t)
        {
            visy[y] = 1;
            if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y] = x;
				return 1;
			}
		}
		else if(t<slack)  slack=t;
	}
	return 0;
}



int km()
{
	memset(linky,-1,sizeof(linky));
	memset(ly,0,sizeof(ly));
	memset(lx,0,sizeof(lx));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			lx[i]=max(mp[i][j],lx[i]);
		}
	}

	for(int i=1;i<=n;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(dfs(i)) break;
			for(int j=1;j<=n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=1;j<=n;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(linky[i]>-1)
		{
			res+=mp[linky[i]][i];
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(input(n>>m>>k>>p))
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",ship+i);
		}
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		for(int i=0;i<p;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(b,a+m,c);
		}
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
		{
			spfa(ship[i]);
			for(int j=m+1;j<=m+p;j++)
			{
				mp[i][j-m]=-dis[j];
			}
		}
		print(-km());
	}
	return 0;
}
