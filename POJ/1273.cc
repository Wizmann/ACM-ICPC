#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int n,edge;
int g[210][210];
char visit[210];
int pre[210];

void EK()
{
	int flow=0;
	while(1)
	{
		memset(visit,0,sizeof(visit));
		memset(pre,0,sizeof(pre));		
		queue<int> q;
		q.push(1);
		visit[1]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			
			for(int i=1;i<=n;i++)
			{
				if(g[now][i]>0&&!visit[i])
				{
					q.push(i);
					visit[i]=1;
					pre[i]=now;
				}
			}
		}
		if(pre[n]==0) break;
		
		int minc=1<<20;
		int pos=n;
		while(pos!=1)
		{
			int t=pre[pos];
			if(minc>g[t][pos]) minc=g[t][pos];
			pos=t;
		}
		
		flow+=minc;
		pos=n;
		while(pos!=1)
		{
			int t=pre[pos];
			g[t][pos]-=minc;
			g[pos][t]+=minc;
			pos=t;
		}
	}
	
	printf("%d\n",flow);
}	

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(scanf("%d%d",&edge,&n)!=EOF)
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<edge;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a][b]+=c;
		}
		EK();
	}
	return 0;
}
	
