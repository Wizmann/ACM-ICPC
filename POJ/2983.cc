#include <cstdio>
#include <cstdlib>
#include <cstring>

int n,ask,num;

typedef struct node
{
	int from,to,weight;
	
	void setnode(int a,int b,int c)
	{
		from=a;to=b;weight=c;
	}
}node;

node g[200010];
int dis[1010];
int min,max;

bool bellman_ford()
{
	for(int i=min;i<=max;i++) dis[i]=1<<20;
	dis[min]=0;
	bool over;
	for(int i=0;i<=max-min;i++)
	{
		over=true;
		for(int k=0;k<num;k++)
		{
			if(dis[g[k].from]+g[k].weight>dis[g[k].to])
			{
				dis[g[k].to]=dis[g[k].from]+g[k].weight;
				over=false;
			}
		}
		if(over) break;
	}
	
	for(int i=0;i<num;i++)
	{
		if(dis[g[i].from]+g[i].weight>dis[g[i].to]) return false;
	}
	return true;
}		

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	char cmd[3];
	while(scanf("%d%d",&n,&ask)!=EOF)
	{
		min=1<<20;max=-1;
		memset(g,0,sizeof(g));
		memset(dis,0,sizeof(dis));
		num=0;
		for(int i=0;i<ask;i++)
		{
			scanf("%s",cmd);
			if(*cmd=='P')
			{
				scanf("%d%d%d",&a,&b,&c);
				g[num++].setnode(a,b,c);
				g[num++].setnode(b,a,-c);
			}
			else
			{
				scanf("%d%d",&a,&b);
				g[num++].setnode(a,b,1);
			}
			if(a>max) max=a;
			if(a<min) min=a;
			if(b>max) max=b;
			if(b<min) min=b;
		}
		if(bellman_ford()) puts("Reliable");
		else puts("Unreliable");
	}
	return 0;
}
				
