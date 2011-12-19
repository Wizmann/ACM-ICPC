#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1025

int baum[MAX][MAX];
int n;

inline int lowbit(int x)
{
	return x&(-x);
}

void ins(int x,int y,int c)
{
	int t=y;
	while(x<MAX)
	{
		y=t;
		while(y<MAX)
		{
			baum[y][x]+=c;
			y+=lowbit(y);
		}
		x+=lowbit(x);
	}
}

int getsum(int x,int y)
{
	int res=0,t=y;
	while(x>0)
	{
		y=t;
		while(y>0)
		{
			res+=baum[y][x];
			y-=lowbit(y);
		}
		x-=lowbit(x);
	}
	return res;
}

int sum(int x1,int y1,int x2,int y2)
{
	return getsum(x2,y2)+getsum(x1-1,y1-1)-getsum(x2,y1-1)-getsum(x1-1,y2);
}

int main()
{
	freopen("input.txt","r",stdin);
	int cmd;
	int a,b,c,d;
	while(1)
	{
		scanf("%d",&cmd);
		if(cmd==0) scanf("%d",&n);
		else if(cmd==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			ins(a+1,b+1,c);
		}
		else if(cmd==2)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int res=sum(a+1,b+1,c+1,d+1);
			printf("%d\n",res);
		}
		else break;
	}
	return 0;
}
