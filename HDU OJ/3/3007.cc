//Result:2012-02-18 15:58:42	Accepted	3007	703MS	488K	1784 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define eps 1e-6
#define SIZE 512

struct point
{
	double x,y;

	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

point pnt[SIZE];
int n;

inline bool zero(double x){return x<eps?true:false;}
inline double mul(double x){return x*x;}

double dis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

point getCenter(const point& p0,const point& p1,const point& p2)
{
	point cp;
	double a1=p1.x-p0.x, b1=p1.y-p0.y, c1=(mul(a1)+mul(b1))/2;
    double a2=p2.x-p0.x, b2=p2.y-p0.y, c2=(mul(a2)+mul(b2))/2;
    double d = a1 * b2 - a2 * b1;
    cp.x = p0.x + (c1 * b2 - c2 * b1) / d;
    cp.y = p0.y + (a1 * c2 - a2 * c1) / d;
	return cp;
}

double minCircleCover(point& ansPnt)
{
	double r=0;
	random_shuffle(pnt,pnt+n);
	ansPnt=pnt[0];

	for(int i=1;i<n;i++)
	{
		if(zero(dis(pnt[i],ansPnt)-r)) continue;
		ansPnt=pnt[i];
		r=0;
		for(int j=0;j<i;j++)
		{
			if(zero(dis(pnt[j],ansPnt)-r)) continue;
			ansPnt.x=(pnt[i].x+pnt[j].x)/2;
			ansPnt.y=(pnt[i].y+pnt[j].y)/2;
			r=dis(ansPnt,pnt[j]);
			for(int k=0;k<j;k++)
			{
				if(zero(dis(pnt[k],ansPnt)-r)) continue;
				ansPnt=getCenter(pnt[i],pnt[j],pnt[k]);
				r=dis(ansPnt,pnt[k]);
			}
		}
	}
	return r;
}


int main()
{
	freopen("input.txt","r",stdin);
	while(input(n) && n)
	{
		memset(pnt,0,sizeof(pnt));
		for(int i=0;i<n;i++)
		{
			input(pnt[i].x>>pnt[i].y);
		}
		point ansPnt;
		double ans=minCircleCover(ansPnt);
		printf("%.2lf %.2lf %.2lf\n",ansPnt.x,ansPnt.y,ans);
	}
	return 0;
}
