//Result:wizmann	2155	Accepted	4804K	547MS	G++	1519B	2012-08-10 14:45:28
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

inline int lowbit(int x)
{
	return x&(-x);
}

struct SegBIT
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x>0)
		{
			baum[x]+=val;
			x-=lowbit(x);
		}
	}
	void addseg(int a,int b,int val)
	{
		add(a-1,-val);
		add(b,val);
	}
	int sum(int x)
	{
		int res=0;
		while(x<SIZE)
		{
			res+=baum[x];
			x+=lowbit(x);
		}
		return res;
	}
};

struct SegBIT_2D
{
	SegBIT baum[SIZE];
	inline void init()
	{
		for(int i=0;i<SIZE;i++) baum[i].init();
	}
	void add(int y,int x1,int x2,int val)
	{
		while(y>0)
		{
			baum[y].addseg(x1,x2,val);
			y-=lowbit(y);
		}
	}
	void addseg(int y1,int x1,int y2,int x2,int val)
	{
		add(y1-1,x1,x2,-val);
		add(y2,x1,x2,val);
	}
	int sum(int y,int x)
	{
		int res=0;
		while(y<SIZE)
		{
			res+=baum[y].sum(x);
			y+=lowbit(y);
		}
		return res;
	}
};

int main()
{
	freopen("input.txt","r",stdin);
	int T,n,q;
	int a,b,c,d;
	char cmd[4];
	input(T);
	SegBIT_2D sb2;
	while(T--)
	{
		sb2.init();
		input(n>>q);
		while(q--)
		{
			scanf("%s",cmd);
			if(*cmd=='C')
			{
				scanf("%d%d%d%d",&a,&b,&c,&d);
				sb2.addseg(a,b,c,d,1);
			}
			else
			{
				scanf("%d%d",&a,&b);
				printf("%d\n",sb2.sum(a,b)&1);
			}
		}
		puts("");
	}
	return 0;
}
