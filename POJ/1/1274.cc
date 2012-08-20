//Result:wizmann	1274	Accepted	8008K	157MS	C++	1601B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

#define SOURCE 0
#define SINK cow+room+1

using namespace std;
int cow,room;
int g[1000][1000];
int flow[1000][1000];
int ans;

void pb(int a,int b)
{
	g[a][0]++;
	g[a][g[a][0]]=b;
}

void EK()
{
	char visit[1000];
	int pre[1000];
	while(1)
	{
		memset(visit,0,sizeof(visit));
		memset(pre,-1,sizeof(pre));
		queue<int> q;
		q.push(SOURCE);
		visit[SOURCE]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();			
			for(int i=1;i<=g[now][0];i++)
			{
				int t=g[now][i];
				if(flow[now][t]>0&&!visit[t])
				{
					q.push(t);
					visit[t]=1;
					pre[t]=now;
				}
			}
		}
			
		if(pre[SINK]==-1) break;
		
		int now=SINK;
		int minf=1<<20;
		while(now!=SOURCE)
		{
			int p=pre[now];
			minf=min(minf,flow[p][now]);
			now=p;
		}
		now=SINK;
		ans+=minf;
		while(now!=SOURCE)
		{
			int p=pre[now];
			flow[p][now]-=minf;
			flow[now][p]+=minf;
			now=p;
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&cow,&room)==2)
	{
		ans=0;
		memset(flow,0,sizeof(flow));
		memset(g,0,sizeof(g));
		for(int i=1;i<=cow;i++)
		{
			int a,t;
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&a);
				pb(i,a+cow);pb(a+cow,i);
				flow[i][a+cow]=1;				
			}
		}
		for(int i=1;i<=cow;i++)
		{
			pb(SOURCE,i);
			pb(i,SOURCE);
			flow[SOURCE][i]=1;
		}
		for(int i=1;i<=room;i++)
		{
			pb(SINK,i+cow);
			pb(i+cow,SINK);
			flow[i+cow][SINK]=1;
		}
		EK();
		printf("%d\n",ans);
	}
	return 0;
}
				
		
