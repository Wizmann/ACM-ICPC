#include <cstdio>
#include <cstdlib>
#include <cstring>

int yes=0,no=0;
int n;
int g[10050];

int find(int x)
{
	while(g[x]!=x) x=g[x];
	return x;
}

void connect(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if(x!=y) g[x]=y;
}

void del(int a)
{
	if(g[a]!=a)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=a&&g[i]==a) g[i]=g[a];
		}
		g[a]=a;
	}
	else
	{
		int t;
		for(t=1;t<=n;t++)
		{
			if(t!=a&&g[t]==a) break;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(g[i]==a) g[i]=t;
		}
		
		g[a]=a;
		g[t]=t;
	}
}
		

int main()
{
	freopen("input.txt","r",stdin);

	char cmd[5];
	while(scanf("%d",&n)!=EOF)
	{
		yes=0;
		no=0;
		for(int i=0;i<=n;i++) g[i]=i;
		scanf("%s",cmd);
		while(*cmd!='e')
		{
			int a,b;
			if(*cmd=='d')
			{
				scanf("%d",&a);
				del(a);
			}
			else
			{
				scanf("%d%d",&a,&b);
				if(*cmd=='c') connect(a,b);
				else if(*cmd=='q')
				{
					if(find(a)==find(b)) yes++;
					else no++;
				}
			}			
			scanf("%s",cmd);
		}
		printf("%d , %d\n",yes,no);	
	}
	return 0;
}
	
