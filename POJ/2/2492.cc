#include <cstdio>
#include <cstdlib>
#include <cstring>

int re[2010];
int ml[2010];

inline void init(int n)
{
	for(int i=0;i<=n;i++) re[i]=i;
	memset(ml,0,sizeof(ml));
}

int find(int x)
{
	if(re[x]==x) return x;
	else return re[x]=find(re[x]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,n,ask,a,b,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&ask);
		init(n);
		int res=0;
		while(ask--)
		{
			scanf("%d%d",&a,&b);
			if(find(a)==find(b)) res=1;
			if(res==0)
			{
				if(!ml[a]) ml[a]=b;				
				if(!ml[b]) ml[b]=a;
				
				re[find(ml[a])]=find(b);
				re[find(ml[b])]=find(a);
			}
			
		}
		printf("Scenario #%d:\n",cas++);
		if(res) puts("Suspicious bugs found!");
		else puts("No suspicious bugs found!");
		printf("\n");
	}
	return 0;
}


