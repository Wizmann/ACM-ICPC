#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 101

const double eps=1e-8;
const double inf=1e12;

struct point
{
	double x,y;
	point(){}
	point(double ix,double iy)
	{
		x=ix;y=iy;
	}
};

inline double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

double pntDis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct segment
{
	point p1,p2;
	segment(){}
	segment(const point& ip1,const point& ip2)
	{
		p1=ip1;p2=ip2;
	}
	double distoline(const point &c)
	{
		return fabs(xmult(c,p1,p2))/pntDis(p1,p2);
	}
};

struct polygen
{
	int sz;
	point array[SIZE];
	void init(int isz){sz=isz;}
};

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	double a,b;
	polygen poly;
	while(input(n) && n)
	{
		double ans=inf;
		poly.init(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly.array[i]=point(a,b);
		}

		for(int i=0;i<n;i++)
		{
			int j=(i+1)%n;
			double tmp=0;
			for(int k=0;k<n;k++)
			{
				double dis=segment(poly.array[i],poly.array[j]).distoline(poly.array[k]);
				tmp=max(tmp,dis);
			}
			ans=min(ans,tmp);
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}


