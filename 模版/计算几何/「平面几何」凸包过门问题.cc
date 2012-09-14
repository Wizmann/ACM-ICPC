//Result:1098	Accepted	12MS	312K	G++	 1413B	2012-09-13 20:41:23	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double inf=1e100;
const double eps=1e-8;

inline double mul(double x)
{
	return x*x;
}

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

struct point
{
	double x,y;
	point(){}
	point(double ix,double iy)
	{
		x=ix;y=iy;
	}
};

struct line
{
	double a,b,c;
	line(){}
	line(double ia,double ib,double ic)
	{
		a=ia;b=ib;c=ic;
	}

	double disToPoint(const point &p)
	{
		return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
	}
};

line makeline(const point &p1,const point &p2)
{
	line res;
	int sig=1;
	res.a=p2.y-p1.y;
	if(zero(res.a)<0)
	{
		sig=-1;
		res.a=sig*res.a;
	}
	res.b=sig*(p1.x-p2.x);
	res.c=sig*(p1.y*p2.x-p2.y*p1.x);
	return res;
}

point array[100];

int main()
{
	int n;
	double a,b;
	while(input(n) && n)
	{
		double ans=inf;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i]=point(a,b);
		}
		for(int i=0;i<n;i++)
		{
			int j=(i+1)%n;
			line l=makeline(array[i],array[j]);
			double t=0;
			for(int k=0;k<n;k++) if(k!=i && k!=j)
			{
				t=max(t,l.disToPoint(array[k]));
			}
			ans=min(ans,t);
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}


