//Result:2012-08-19 10:43:59	Accepted	2483	875MS	1872K	2496 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 310

inline int lowbit(int x){return (x)&(-x);}

struct BIT
{
	int baum[SIZE];
	inline void init(){memset(baum,0,sizeof(baum));}
	
	inline void add(int pos,int val)
	{
		while(pos<SIZE)
		{
			baum[pos]+=val;
			pos+=lowbit(pos);
		}
	}
	inline int sum(int pos)
	{
		int res=0;
		while(pos>0)
		{
			res+=baum[pos];
			pos-=lowbit(pos);
		}
		return res;
	}
	inline int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

struct BIT_2D
{
	BIT baum[SIZE];
	inline void init()
	{
		for(int i=0;i<SIZE;i++) baum[i].init();
	}
	inline void add(int y,int x,int val)
	{
		while(y<SIZE)
		{
			baum[y].add(x,val);
			y+=lowbit(y);
		}
	}
	inline int sum(int y1,int x1,int y2,int x2)
	{
		int res=0;
		while(y2>0)
		{
			res+=baum[y2].sum(x1,x2);
			y2-=lowbit(y2);
		}
		y1--;
		while(y1>0)
		{
			res-=baum[y1].sum(x1,x2);
			y1-=lowbit(y1);
		}
		return res;
	}
};

int m,n;
BIT_2D bit;
int g[SIZE][SIZE];
int gx[SIZE][SIZE],gy[SIZE][SIZE];

bool judge(int y,int x,int len)
{
	int rux=x+len-1;
	int ruy=y;
	int ldx=x;
	int ldy=y+len-1;

	if(gx[ldy][ldx]>=len && gy[ruy][rux]>=len)
	{
		if(len==2) return true;
		else
		{
			int lux=x+1,luy=y+1;
			int rdx=x+len-2,rdy=y+len-2;

			int black=bit.sum(luy,lux,rdy,rdx);
			int all=(len-2)*(len-2);
			int white=all-black;
			if(abs(black-white)<=1) return true;
			else return false;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		input(n>>m);
		bit.init();
		memset(gx,0,sizeof(gx));
		memset(gy,0,sizeof(gy));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&g[i][j]);
				bit.add(i,j,g[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=n;j>0;j--)
			{
				if(g[i][j]==1) sum++;
				else sum=0;
				gx[i][j]=sum;
			}
		}
		for(int j=1;j<=n;j++)
		{
			int sum=0;
			for(int i=n;i>0;i--)
			{
				if(g[i][j]==1) sum++;
				else sum=0;
				gy[i][j]=sum;
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int sz=min(gx[i][j],gy[i][j]);
				for(int k=2;k<=sz;k++)
				{
					if(judge(i,j,k))
					{
						//print(i<<' '<<j);
						ans++;
					}
				}
			}
		}
		print(ans);
	}
	return 0;
}
