#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct point
{
	int x,y;
	
	point()
	{
		x=1<<20;
		y=1<<20;
	}
	
	void setpoint(int a,int b)
	{
		if(a<x)
		{
			x=a;y=b;
		}
		else if(a==x&&b<y) y=b;
	}
	
	void print()
	{
		printf("%d %d\n",x,y);
	}
}point;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		point ptr;
		int a,b;
		while(n--)
		{
			scanf("%d%d",&a,&b);
			ptr.setpoint(a,b);
		}
		ptr.print();
	}
	return 0;
}
	
	
