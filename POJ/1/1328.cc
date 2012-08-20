//Result:wizmann	1328	Accepted	420K	32MS	G++	1079B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

typedef struct point
{
	double x,y;
}point;

typedef struct segment
{
	double st,end;
	
	void setseg(double a,double b)
	{
		st=a<b?a:b;end=a<b?b:a;
	}
}segment;	

int cmp(const void *a,const void *b)
{
	segment ta=*(segment*)a,tb=*(segment*)b;
	return ta.st>tb.st?1:-1;
}

double r;
int n;
segment sg[1001];
int cas=1;

int main()
{
	freopen("input.txt","r",stdin);
	point p;
	while(1)
	{
		bool flag=true;
		scanf("%d%lf",&n,&r);
		if(!n) break;
		printf("Case %d: ",cas++);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&p.x,&p.y);
			if(p.y>r||p.y<0) flag=false;
			else
			{
				double t=sqrt(1.0*r*r-p.y*p.y);
				sg[i].setseg(p.x-t,p.x+t);
			}
		}
		if(!flag) puts("-1");
		else
		{
			qsort(sg,n,sizeof(segment),cmp);
			int ans=0;
			for(int i=0;i<n;)
			{
				ans++;
				double now=sg[i].end;
				i++;	
				while(i<n&&now>=sg[i].st)
				{
					if(sg[i].end<now) now=sg[i].end;
					i++;
				}
			}
			
			printf("%d\n",ans);
		}
	}
	return 0;
}
			
