//Result:2012-07-26 19:33:59	Accepted	4311	156MS	3676K	1266 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define INF 1LL<<60

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

int xs[SIZE+5],ys[SIZE+5];
llint sumx[SIZE+5],sumy[SIZE+5];
int n;
point array[SIZE+5];

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		input(n);
		memset(sumx,0,sizeof(sumx));
		memset(sumy,0,sizeof(sumy));
		
		/*
		 * 对于原坐标系中两点间的 Chebyshev 距离，是将坐标轴顺时针旋转45度并将所有点的坐标值放大sqrt(2)倍所得到的新坐标系中的Manhattan距离的二分之一。
		 * 假设有两点(x1,y1), (x2,y2)，不妨设 x1>x2（否则交换这两点即可）。
		 * 则Chebyshev距离 D1 = max(|x1-x2|, |y1-y2|)
		 * 这两点个对应到新坐标系中的坐标为 (x1-y1, x1+y1), (x2-y2, x2+y2)
		 * 则Manhattan 距离D2 = |x1-y1-x2+y2| + |x1+y1-x2-y2|
		*/
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			int ta=a-b,tb=a+b;
			array[i]=point(ta,tb);
			xs[i]=ta;ys[i]=tb;
		}
		sort(xs,xs+n);
		sort(ys,ys+n);

		for(int i=0;i<n;i++)
		{
			if(i)
			{
				sumx[i]+=sumx[i-1];
				sumy[i]+=sumy[i-1];
			}
			sumx[i]+=xs[i];
			sumy[i]+=ys[i];
		}
		llint ans=INF;
		for(int i=0;i<n;i++)
		{
			llint res=0;
			int x=array[i].x;
			int y=array[i].y;

			llint p=upper_bound(xs,xs+n,x)-xs-1;
			res+=(p+1)*x-sumx[p];
			res+=(sumx[n-1]-sumx[p])-x*(n-p-1);

			p=upper_bound(ys,ys+n,y)-ys-1;
			res+=(p+1)*y-sumy[p];
			res+=(sumy[n-1]-sumy[p])-y*(n-p-1);

			ans=min(ans,res);
		}
		print(ans/2);
	}
	return 0;
}

