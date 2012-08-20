#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <climits>

#define MAX 500

using namespace std;

int n,np,nc,line;
int g[MAX][MAX];
char used[MAX];
int pre[MAX];

void EK()
{
	int flow=0;
	while(1)
	{
		memset(used,0,sizeof(used));
		memset(pre,-1,sizeof(pre));
		queue<int> q;
		while(!q.empty()) q.pop();
		q.push(0);//将源点压入
		used[0]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=1;i<=n+1;i++)
			{
				if(!used[i]&&g[now][i]>0)
				{
					used[i]=1;
					q.push(i);
					pre[i]=now;
				}
			}
		}
			
		if(pre[n+1]==-1) break;//如果sink点没能到达，则增广路查找完成
		
		int minc=INT_MAX;
		int pos=n+1;
		while(pos!=0)
		{
			int t=pre[pos];
			if(g[t][pos]<minc) minc=g[t][pos];
			pos=t;
		}
		
		flow+=minc;
		
		pos=n+1;
		while(pos!=0)
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
	while(scanf("%d%d%d%d",&n,&np,&nc,&line)==4)
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<line;i++)
		{
			while(getchar()!='(');
			scanf("%d,%d)%d",&a,&b,&c);
			g[a+1][b+1]=c;
		}
		
		for(int i=0;i<np;i++)
		{
			while(getchar()!='(');
			scanf("%d)%d",&a,&b);
			g[0][a+1]=b;//0点为源点
		}
		
		for(int i=0;i<nc;i++)
		{
			while(getchar()!='(');
			scanf("%d)%d",&a,&b);
			g[a+1][n+1]=b;//n+1点为sink
		}
		
		EK();
	}
	return 0;
}
