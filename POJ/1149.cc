#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

#define SIZE 105
#define SOURCE 0
#define SINK n+1
#define INF 1<<20

typedef struct node
{
	int sum;
	int flag;
	int cust[SIZE];
	
	void setnode()
	{
		scanf("%d",&sum);
		flag=0;
		memset(cust,0,sizeof(cust));
	}
}node;

node pig[1010];
int m,n;
int want[SIZE];
int g[SIZE][SIZE];
int pre[SIZE];
char used[SIZE];

int EK()
{
	int flow=0;
	while(1)
	{
		memset(pre,-1,sizeof(pre));
		memset(used,0,sizeof(used));
		queue<int> q;
		q.push(SOURCE);
		used[SOURCE]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=0;i<=SINK;i++)
			{
				if(!used[i]&&g[now][i]>0)
				{
					used[i]=1;
					pre[i]=now;
					q.push(i);
				}
			}
		}
		
		if(pre[SINK]==-1) break;
		int minc=INF;
		int p=SINK;
		while(p!=SOURCE)
		{
			int t=pre[p];
			if(minc>g[t][p]) minc=g[t][p];
			p=t;
		}
		flow+=minc;
		
		p=SINK;
		while(p!=SOURCE)
		{
			int t=pre[p];
			g[t][p]-=minc;
			g[p][t]+=minc;
			p=t;
		}
	}
	return flow;
}		

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&m,&n)==2)
	{
		for(int i=1;i<=m;i++) pig[i].setnode();
		
		for(int i=1;i<=n;i++)
		{
			int k,t;
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&t);
				pig[t].cust[pig[t].flag++]=i;
			}
			scanf("%d",&want[i]);
		}
		
		for(int i=1;i<=m;i++)
		{
			if(pig[i].flag>0)
			{
				int first=pig[i].cust[0];
				g[SOURCE][first]+=pig[i].sum;
				for(int j=1;j<=pig[i].flag;j++)
				{
					int sec=pig[i].cust[j];
					g[first][sec]=INF;
				}
			}
		}
		
		for(int i=1;i<=n;i++) g[i][SINK]=want[i];
		printf("%d\n",EK());
	}
	return 0;
}
		
		
