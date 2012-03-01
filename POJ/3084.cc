//Result:3084	Accepted	724K	16MS	G++	1685B	2012-02-29 20:34:28
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 24+2
#define SOURCE 24
#define SINK 25
#define INF 1<<25

char g[SIZE][SIZE];
int flow[SIZE][SIZE];
int pre[SIZE];
bitset<SIZE> visit;
int ans;

void EK()
{
	ans=0;
	while(1)
	{
		visit.reset();
		memset(pre,-1,sizeof(pre));
		queue<int> q;//EK算法使用queue，FF算法使用stack，在某些SPJ里可以尝试一下不同算法
		q.push(SOURCE);
		while(!q.empty())
		{
			int now=q.front();
			q.pop();			
			for(int i=0;i<=SINK;i++)
			{
				if(flow[now][i]>0 && !visit[i])//在整数流量时用flow>0就足够了
				{
					q.push(i);
					visit[i]=1;
					pre[i]=now;
				}
			}
		}
			
		if(pre[SINK]==-1) break;
		
		int now=SINK;
		int minf=INF;
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
//传回全局变量ans即为答案
	

int n,k;

int main()
{
	int T;
	input(T);
	char cmd[5];
	while(T--)
	{
		input(n>>k);
		memset(g,0,sizeof(g));
		memset(flow,0,sizeof(flow));
		for(int i=0;i<n;i++)
		{
			int t,a;
			scanf("%s",cmd);
			if(*cmd=='I')
			{
				g[SOURCE][i]=1;
				flow[SOURCE][i]=INF;
			}
			input(t);
			while(t--)
			{
				input(a);
				g[i][a]=g[a][i]=1;
				flow[i][a]=INF;
				flow[a][i]+=1;
			}
		}
		g[k][SINK]=1;
		flow[k][SINK]=INF;
		EK();
		if(ans>=INF) print("PANIC ROOM BREACH");
		else print(ans);
	}
	return 0;
}
