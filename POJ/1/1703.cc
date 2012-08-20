#include <cstdio>
#include <cstdlib>
#include <cstring>

int g[100100];
int opp[100100];
int n;

inline void init()
{
	memset(opp,0,sizeof(opp));
	for(int i=0;i<=n;i++) g[i]=i;
}

int find(int x)
{
	if(g[x]==x) return x;
	else return g[x]=find(g[x]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,ask,a,b;
	char cmd[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&ask);
		init();
		while(ask--)
		{
			scanf("%s%d%d",cmd,&a,&b);
			if(*cmd=='A')
			{
				if(find(opp[a])==find(b)) puts("In different gangs.");
				else if(find(a)==find(b)) puts("In the same gang.");
				else puts("Not sure yet.");
			}
			else
			{
				if(!opp[a]) opp[a]=b;
				if(!opp[b]) opp[b]=a;
				
				g[find(g[b])]=find(opp[a]);
				g[find(g[a])]=find(opp[b]);
			}
		}
	}
	return 0;
}

