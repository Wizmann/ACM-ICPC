//Result:wizmann	3227	Accepted	812K	16MS	G++	3498B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const double inf=1e20;
const double eps=1e-7;
const double ext=1e3;

inline double mul(double x){return x*x;}
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

struct segment
{
	point p1,p2;
	segment(){}
	segment(const point& ip1,const point& ip2)
	{
		p1=ip1;p2=ip2;
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
};

inline double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

line makeline(point p1,point p2)
{
	line res;
	int sig=1;
	res.a=p2.y-p1.y;
	if(zero(res.a)<0)
	{
		sig=-1;
		res.a=res.a*sig;
	}
	res.b=sig*(p1.x-p2.x);
	res.c=sig*(p1.y*p2.x-p2.y*p1.x);
	return res;
}
line makeline(segment s)
{
	return makeline(s.p1,s.p2);
}

bool lineIntersect(line l1,line l2,point &p)
{
	double d=l1.a*l2.b-l2.a*l1.b;
	if(zero(d)==0) return false;
	else
	{
		p.x=(l2.c*l1.b-l1.c*l2.b)/d;
		p.y=(l2.a*l1.c-l1.a*l2.c)/d;
		return true;
	}
}

bool onSegment(segment s,point p)
{
	return zero(xmult(s.p2,p,s.p1))==0 &&
		   zero((p.x-s.p1.x)*(p.x-s.p2.x))<=0 &&
		   zero((p.y-s.p1.y)*(p.y-s.p2.y))<=0;
}

bool segIntersect(segment l1,segment l2,point &p)
{
	if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x)) &&
	   (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y)) &&
	   (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x)) &&
	   (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y)) &&
	   (xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2)<=eps) &&
	   (xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2)<=eps))
	{
		lineIntersect(makeline(l1),makeline(l2),p);
		return true;
	}
	else if(onSegment(l1,l2.p1))
	{
		p=l2.p1;
		return true;
	}
	else if(onSegment(l1,l2.p2))
	{
		p=l2.p2;
		return true;
	}
	else if(onSegment(l2,l1.p1))
	{
		p=l1.p1;
		return true;
	}
	else if(onSegment(l2,l1.p2))
	{
		p=l1.p2;
		return true;
	}
	else return false;
}

segment extendSegment(point p1,point p2,int flag,double ext)
{
	segment res;
	double d=0;

	res.p1=p1;
	res.p2=p2;
	if(zero(p1.x-p2.x)!=0) d=ext/fabs(p1.x-p2.x);
	if(zero(d)==0 || zero(p1.y-p2.y)>eps)
	{
		d=ext/fabs(p1.y-p2.y);
	}
	if(flag & 1)
	{
		res.p2.x+=(p2.x-p1.x)*d;
		res.p2.y+=(p2.y-p1.y)*d;
	}
	if(flag & 2)
	{
		res.p1.x+=(p1.x-p2.x)*d;
		res.p1.y+=(p1.y-p2.y)*d;
	}
	return res;
}



inline double pointDis(point p1,point p2)
{
	return sqrt(mul(p1.x-p2.x)+mul(p1.y-p2.y));
}

int n;
double x,y;
point god;
point array[SIZE];

double slove()
{
	double res=0;
	segment scan=segment(god,array[0]);
	for(int i=1;i<n;i++)
	{
		if(zero(xmult(scan.p2,array[i],god)<=0)) continue;
		segment edge(array[i-1],array[i]);
		point p;
		segIntersect(extendSegment(scan.p1,scan.p2,1,ext),edge,p);
		res+=pointDis(p,array[i]);
		//print(">>"<<pointDis(p,array[i]));
		scan=segment(god,array[i]);
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>x))
	{
		if(n==0) break;
		god=point(0,x);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			array[i]=point(x,y);
		}
		printf("%.2f\n",slove());
	}
	return 0;
}

