//Result:wizmann	2240	Accepted	396K	47MS	C++	1532B	2011-05-01 13:50:03
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct node
{
	char type[100];
	int nr;
	
	void setnode(int n)
	{
		nr=n;
		scanf("%s",type);
	}
}node;

typedef struct path
{
	int st,end;
	double w;
	
	void setpath(int a,int b,double c)
	{
		st=a;end=b;w=c;
	}
}path;

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;	
	return strcmp(ta->type,tb->type);
}

node name[30];
path g[10000];
double dis[10000];
int n,m;

int bf()
{
	memset(dis,0,sizeof(dis));
	dis[1]=1;
	bool flag=true;
	
	while(dis[1]<=1)
	{
		flag=true;
		for(int j=1;j<=m;j++)
		{
			if(dis[g[j].end]<dis[g[j].st]*g[j].w)
			{
				dis[g[j].end]=dis[g[j].st]*g[j].w;
				flag=false;
			}
		}
		if(flag) break;
	}

	return dis[1]>1;
}

int cas=1;

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	double c;
	node *p;
	bool flag=true;
	char input[100];
	while(scanf("%d",&n),n)
	{
		memset(g,0,sizeof(g));
		flag=true;
		printf("Case %d: ",cas++);
		for(int i=0;i<n;i++) name[i].setnode(i+1);
		qsort(name,n,sizeof(node),cmp);
		
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%s",input);
			p=(node*)bsearch(input,name,n,sizeof(node),cmp);
			a=p->nr;
			scanf("%lf",&c);
			scanf("%s",input);
			p=(node*)bsearch(input,name,n,sizeof(node),cmp);
			b=p->nr;
			g[i].setpath(a,b,c);
			if(a==b&&c>1) flag=false;			
		}
		
		if(!flag) puts("Yes");
		else
		{
			if(bf()) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
	
