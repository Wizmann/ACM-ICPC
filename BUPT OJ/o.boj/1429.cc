#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 310
#define INF 1<<20

typedef struct node
{
	int value;
	int nr;
	
	void setnode(int n)
	{
		nr=n;
		scanf("%d",&value);
	}
}node;

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a;
	node *tb=(node*)b;
	
	return tb->value-ta->value;
}

int g[N][N];
node v[N];

inline void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) g[i][j]=INF;
		g[i][i]=0;
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,ask,day;
		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));
		
		scanf("%d%d%d",&n,&ask,&day);
		init(n);		
		int a,b,l;
		while(ask--)
		{
			scanf("%d%d%d",&a,&b,&l);
			g[a][b]=l;
			g[b][a]=l;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(g[j][k]>g[j][i]+g[i][k])
					{
						g[j][k]=g[j][i]+g[i][k];
					}
				}
			}
		}
		
		for(int i=1;i<=n;i++) v[i-1].setnode(i);
		qsort(v,n,sizeof(node),cmp);
		
		int ans=-1;
		int min=INF;
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=0;j<day;j++) sum+=g[i][v[j].nr];
			if(sum<min)
			{
				min=sum;
				ans=i;
			} 
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
