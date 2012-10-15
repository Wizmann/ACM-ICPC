//Result:2012-10-05 18:38:42	Accepted	4417	109MS	2448K	1825 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100

typedef long long llint;

inline int lowbit(int x)
{
	return x&(-x);
}

struct BIT
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x<SIZE)
		{
			baum[x]+=val;
			x+=lowbit(x);
		}
	}
	int sum(int x)
	{
		int res=0;
		while(x>0)
		{
			res+=baum[x];
			x-=lowbit(x);
		}
		return res;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

struct road
{
	int height;
	int pos;

	road(){}
	road(int ih,int ip)
	{
		height=ih;pos=ip;
	}
	friend bool operator < (const road &a,const road &b)
	{
		return a.height<b.height;
	}
};

struct query
{
	int ll,rr,hh,pos;
	query(){}
	query(int il,int ir,int ih,int ipos)
	{
		ll=il;rr=ir;hh=ih;pos=ipos;
	}
	friend bool operator < (const query& a,const query& b)
	{
		return a.hh<b.hh;
	}
};

int n,q;
road maze[SIZE];
query qq[SIZE];
BIT bit;
int ans[SIZE];

int main()
{
	freopen("8.txt","r",stdin);
	int T,cas=1;
	int a,b,c;
	input(T);
	while(T--)
	{
		bit.init();
		printf("Case %d:\n",cas++);
		input(n>>q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			maze[i]=road(a,i);
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			a++;b++;
			qq[i]=query(a,b,c,i);
		}
		sort(maze+1,maze+n+1);
		sort(qq+1,qq+q+1);

		int ptr=1;
		for(int i=1;i<=q;i++)
		{
			int hh=qq[i].hh;
			for(;ptr<=n && maze[ptr].height<=hh;ptr++)
			{
				bit.add(maze[ptr].pos,1);
			}
			ans[qq[i].pos]=bit.sum(qq[i].ll,qq[i].rr);
		}

		for(int i=1;i<=q;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}


