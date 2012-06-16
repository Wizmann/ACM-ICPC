//Result: 1283	Accepted	3MS	320K	G++	 3117B	2012-06-12 20:12:21	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define inf 1e10
#define eps 1e-8

const double pi=acos(-1);

inline bool zero(double x)
{
	return fabs(x)<eps?true:false;
}

inline double mul(double x){return x*x;}

struct point
{
	double x,y;
	point(){}
	point(double  i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

struct segment
{
	point p1,p2;

	segment(){}
	segment(point i_p1,point i_p2)
	{
		p1=i_p1;
		p2=i_p2;
	}
};

struct line
{
	double a,b,c;
	
	friend bool operator == (const line x,const line y)
	{
		double d;
		if(!zero(y.a)) d=x.a/y.a;
		else if(!zero(y.b)) d=x.b/y.b;
		else if(zero(y.c))
		{
			if(!zero(x.b)||!zero(x.a)) return true;
			else if(zero(x.c)) return true;
			else return false;
		}
		else return false;

		if(x.a==d*y.a&&x.b==d*y.b&&x.c==d*y.c) return true;
		else return false;
	}	
	inline void setline(double ta,double tb,double tc)
	{
		a=ta;b=tb;c=tc;
	}
};

double xmult(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

line makeLine(point p1,point p2)
{
	line res;
	int sig=1;
	res.a=p2.y-p1.y;
	if(res.a<0)
	{
		sig=-1;
		res.a=sig*res.a;
	}
	res.b=sig*(p1.x-p2.x);
	res.c=sig*(p1.y*p2.x-p2.y*p1.x);
	return res;
}
line makeLine(segment s){return makeLine(s.p1,s.p2);}

bool lineIntersect(line l1,line l2,point &p)//直线是否相交，并求交点
{
	double d=l1.a*l2.b-l2.a*l1.b;
	if(fabs(d)<eps) return false;
	else
	{
		p.x = (l2.c*l1.b-l1.c*l2.b)/d;
		p.y = (l2.a*l1.c-l1.a*l2.c)/d;
		return true;
	}
}

bool segIntersect(segment l1,segment l2,point &p)//线段相交，包括特殊的情况
{
	if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   (xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2)<=eps)&&
	   (xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2)<=eps))//跨立实验
	{
		lineIntersect(makeLine(l1),makeLine(l2),p);
		return true;
	}
	else return false;
}

double pntDistance(point& a,point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	double lx,ly,rx,ry;
	double x,y,angle;
	input(T);
	while(T--)
	{
		input(lx>>ly>>rx>>ry>>x>>y>>angle);
		angle=(angle/360.)*2*pi;
		//print(sin(angle));
		segment a,b,c,d;
		a=segment(point(lx,ly),point(rx,ly));
		b=segment(point(lx,ly),point(lx,ry));
		c=segment(point(rx,ry),point(rx,ly));
		d=segment(point(rx,ry),point(lx,ry));
		
		segment star;
		double wish=1e5;
		double end_x=cos(angle)*wish+x;
		double end_y=sin(angle)*wish+y;
		star=segment(point(x,y),point(end_x,end_y));
		point tmpp;
		if(segIntersect(a,star,tmpp) || segIntersect(b,star,tmpp) ||
			segIntersect(c,star,tmpp) || segIntersect(d,star,tmpp))
		{
			print("yes");
		}
		else print("no");
	}
	return 0;
}
