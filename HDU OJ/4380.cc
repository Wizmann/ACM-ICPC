//Result:2012-08-22 11:47:45	Accepted	4380	1234MS	568K	1673 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define HOUSE 128
#define GOLD 1024
#define abs(x) ((x)>0?(x):-(x))

typedef long long llint;

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

inline llint xmult(const point& sp,const point& ep,const point& op)
{
	return ((llint)(sp.x-op.x)*(ep.y-op.y)-(llint)(sp.y-op.y)*(ep.x-op.x));
}

point house[HOUSE],gold[GOLD];
int toGod[HOUSE][HOUSE];
const point god=point(-123456,-234567);

int n,m;

void makeToGod(int a,int b)
{
	point ta=house[a];
	point tb=house[b];
	int res=0;
	llint S=abs(xmult(ta,tb,god));
	for(int i=0;i<m;i++)
	{
		llint Ts=0;
		Ts+=abs(xmult(ta,tb,gold[i]));
		Ts+=abs(xmult(ta,god,gold[i]));
		Ts+=abs(xmult(tb,god,gold[i]));
		if(Ts==S) res++;
	}
	toGod[a][b]=res;
}
	
int slove(int a,int b,int c)
{
	int sum=abs(toGod[a][c]+toGod[b][c]-toGod[a][b]);
	if(sum&1) return 1;
	else return 0;
}


int main()
{
	freopen("input.txt","r",stdin);
	int a,b,cas=1;
	while(input(n>>m))
	{
		printf("Case %d: ",cas++);
		memset(toGod,0,sizeof(toGod));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			house[i]=point(a,b);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			gold[i]=point(a,b);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				makeToGod(i,j);
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					ans+=slove(i,j,k);
				}
			}
		}
		print(ans);
	}
	return 0;
}

