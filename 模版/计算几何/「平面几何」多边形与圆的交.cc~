//Result:354 	Accepted 	30ms 	144kb 	G++	5345B	2012-07-22 17:36:27 	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const double inf=1e10;
const double eps=1e-8;
const double pi=acos(-1.);

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

inline double mul(double x)
{
	return x*x;
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

double pointDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

point rotate(point v,point circle,double angle,double scale)
{
	point ret=circle;
	v.x-=circle.x;v.y-=circle.y;
	circle.x=scale*cos(angle);
	circle.y=scale*sin(angle);
	ret.x+=v.x*circle.x-v.y*circle.y;
	ret.y+=v.x*circle.y+v.y*circle.x;
	return ret;
}


double get_angle(point sp,point ep,point op)
{
	double a=atan2(sp.y-op.y,sp.x-op.x);
	double b=atan2(ep.y-op.y,ep.x-op.x);
	if(b-a>pi) a+=2*pi;
	if(a-b>pi) b+=2*pi;
	return a-b;
}

struct segment
{
	point p1,p2;
	segment(){}
	segment(const point& ip1,const point& ip2)
	{
		p1=ip1;p2=ip2;
	}
	bool onSegment(const point& p) const
	{
		return zero(xmult(p2,p,p1))==0 && 
				zero((p.x-p1.x)*(p.x-p2.x))<=0 && 
				 zero((p.y-p1.y)*(p.y-p2.y))<=0;
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
	line(const point& p1,const point& p2)
	{
		int sig=1;
		a=p2.y-p1.y;
		if(zero(a)<0)
		{
			sig=-1;
			a=sig*a;
		}
		b=sig*(p1.x-p2.x);
		c=sig*(p1.y*p2.x-p2.y*p1.x);
	}
	line(const segment &s)
	{
		*this=line(s.p1,s.p2);
	}
	line make_vertical(const point &p)
	{
		line res=(*this);
		swap(res.a,res.b);
		res.b*=-1;
		res.c=-(res.a*p.x+res.b*p.y);

		return res;
	}
	
	double distopoint(const point &p)
	{
		return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
	}
};

bool lineIntersect(line l1,line l2,point &p)
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

struct polygen
{
	point p[SIZE];
	int sz;
	polygen(){}
	polygen(int in)
	{
		sz=in;
		memset(p,0,sizeof(p));
	}
};

struct circle
{
	point c;
	double r;
	circle(){}
	circle(const point& ic,double ir)
	{
		c=ic;r=ir;
	}

	int line_in_circle(line l)
	{
		if(zero(l.distopoint(c)-r)==0) return 1;
		else if(zero(l.distopoint(c)-r)<0) return 2;
		else return 0;
	}
	
	bool inCircle(const point& p)
	{
		return zero(pointDis(p,c)-r)<=0;
	}

	int cross_line(line l,point& a,point& b)
	{
		int ncr=line_in_circle(l);
		if(ncr==0)
		{
			a=b=point(-inf,-inf);
			return 0;
		}
		else
		{
			line v=l.make_vertical(c);
			point cr;
			
			if(!lineIntersect(l,v,cr))
			{
				//print("line Intersect FAILED!");
			}
			if(ncr==1)
			{
				a=cr;
				b=point(inf,inf);
				return 1;
			}
			else
			{
				double dis=sqrt( (mul(r)-mul(pointDis(c,cr))) / (mul(v.a)+mul(v.b)) );
				double mx=v.a*dis;
				double my=v.b*dis;
				a=point(cr.x+mx,cr.y+my);
				b=point(cr.x-mx,cr.y-my);
				return 2;
			}
		}
	}

	double get_cross_area_triangle(point p1,point p2)
	{
		point a,b;
		line l=line(p1,p2);
		int nc=cross_line(l,a,b);
		segment s(p1,p2);
		if(nc<2)
		{
			double ang=get_angle(p1,p2,c);
			return fabs(pi*r*r*ang/(2*pi));
		}
		else
		{
			bool ain=s.onSegment(a);
			bool bin=s.onSegment(b);
			if(!inCircle(p1)) swap(p1,p2);
			if(!ain&&!bin)
			{
				if(inCircle(p1) && inCircle(p2)) return fabs(xmult(p1,p2,c)/2);
				else
				{
					double ang=get_angle(p1,p2,c);
					return fabs(pi*r*r*ang/(2*pi));
				}
			}
			else if(ain&&bin)
			{
				double res=fabs(xmult(a,b,c)/2);
				if(pointDis(p1,a)>pointDis(p1,b)) swap(a,b);
				double ang=fabs(get_angle(p1,a,c))+fabs(get_angle(p2,b,c));
				res+=pi*r*r*ang/(2*pi);
				return res;
			}
			else if(ain||bin)
			{
				if(!ain) swap(a,b);
				double res=fabs(xmult(a,p1,c)/2);
				double ang=fabs(get_angle(p2,a,c));
				res+=pi*r*r*ang/(2*pi);
				return res;
			}
			else
			{
				//print("Impossible");
				return 0;
			}
		}
	}


	double get_cross_area(const polygen &poly)
	{
		double res=0;
		for(int i=0;i<poly.sz;i++)
		{
			int j=(i+1)%poly.sz;
			int sig=1;
			if(zero(xmult(poly.p[i],poly.p[j],c))<=0) sig=1;
			else sig=-1;
			res+=sig*get_cross_area_triangle(poly.p[i],poly.p[j]);
			//print(sig*get_cross_area_triangle(poly.p[i],poly.p[j]));
		}
		return fabs(res);
	}
};


int main()
{
	freopen("input.txt","r",stdin);
	int n;
	double a,b,c;
	while(input(n) && n)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		circle mia=circle(point(a,b),c);
		polygen poly=polygen(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly.p[i]=point(a,b);
		}

		printf("%.2lf\n",mia.get_cross_area(poly)+eps);
	}
	return 0;
}

