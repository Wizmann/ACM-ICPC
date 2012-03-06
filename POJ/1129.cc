#include <cstdio>
#include <cstring>
#include <cstdlib>

char g[30][30];
int color[30];
char used[30];
int n;

void dfs(int k)
{
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++)
	{
		if(g[k][i]) used[color[i]]=1;
	}

	for(int i=1;i<30;i++)
	{
		if(!used[i])
		{
			color[k]=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(g[k][i]&&!color[i]) dfs(i);
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char cmd[30],*p;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",cmd);
			p=cmd+2;
			while(*p!='\0')
			{
				g[i][*p-'A'+1]=1;
				p++;
			}
		}
		//input over
		
		memset(color,0,sizeof(color));
		for(int i=1;i<=n;i++)
		{
			dfs(i);
		}
		
		int res=-1;
		for(int i=1;i<=n;i++)
		{
			if(color[i]>res) res=color[i];
		}
		for(int i=1;i<=n;i++) printf("%d ",color[i]);
		printf("\n");
		if(res==1) printf("1 channel needed.\n");
		else printf("%d channels needed.\n",res);
	}
	return 0;
}
