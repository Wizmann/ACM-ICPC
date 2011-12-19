#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct node
{
	int from,to;
	double weight,com;
	
	void setnode(int a,int b,double c,double d)
	{
		from=a;to=b;weight=c;com=d;
	}
}node;

const double eps=1e-8;

int pos,n,ask,have;
double value,dis[1010];
node g[1010];

bool bf()
{
	memset(dis,0,sizeof(dis));
	dis[have]=value;
	bool over;
	
	for(int i=1;i<=n;i++)
	{
		over=true;
		
		for(int j=0;j<pos;j++)
		{
			if(dis[g[j].from]>0&&(dis[g[j].from]-g[j].com)*g[j].weight>dis[g[j].to]+eps)
			{
				dis[g[j].to]=(dis[g[j].from]-g[j].com)*g[j].weight;
				over=false;
			}
		}
		if(over) return false;
	}
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d%d%d%lf",&n,&ask,&have,&value);
	
	pos=0;		
	double rab, cab, rba, cba;
	int a,b;
	for(int i=0;i<ask;i++)
	{
		scanf("%d%d",&a,&b);
		scanf("%lf%lf%lf%lf",&rab, &cab, &rba, &cba);
		
		g[pos++].setnode(a,b,rab,cab);
		g[pos++].setnode(b,a,rba,cba);
	}
	
	if(bf()) puts("YES");
	else puts("NO");
	
	return 0;
}
