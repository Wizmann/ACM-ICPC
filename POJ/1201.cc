#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct node
{
	int from,to,weight;
	
	void setnode(int a,int b,int c)
	{
		from=a;
		to=b;
		weight=c;
	}
}node;

node g[50010];
int dis[50010];

int n,max=-1,min=1<<20,ans=0;

void bellman_ford()
{
	for(int i=min;i<=max;i++) dis[i]=-1<<20;
	dis[min]=0;
	bool over;
	for(int i=0;i<=max-min;i++)
	{
		over=true;
		for(int k=min;k<max;k++)
		{
			if(dis[k]!=-1<<20&&dis[k]>dis[k+1])
			{
				dis[k+1]=dis[k];
				over=false;
			}
		}
		for(int k=max;k>min;k--)
		{
			if(dis[k]!=-1<<20&&dis[k]-1>dis[k-1])
			{
				dis[k-1]=dis[k]-1;
				over=false;
			}
		}
		for(int k=0;k<n;k++)
		{
			if(dis[g[k].from]+g[k].weight>dis[g[k].to])
			{
				dis[g[k].to]=dis[g[k].from]+g[k].weight;
				over=false;
			}
		}
		if(over) break;
	}
	ans=dis[max];
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		g[i].setnode(a,++b,c);
		if(b>max) max=b;
		if(a<min) min=a;
	}	
	bellman_ford();
	printf("%d\n",ans);
	return 0;
}
