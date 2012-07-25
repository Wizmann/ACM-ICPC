//Result:	wizmann	3675	Accepted	784K	0MS	G++	3021B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512

const double eps=1e-8;
const double inf=1e10;
const double pi=acos(-1.);

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
	
	point operator - (const point &p) const
	{
		return point(x-p.x,y-p.y);
	}
	
	point operator * (double val) const
	{
		return point(x*val,y*val);
	}
	
	point operator + (const point &p) const
	{
		return point(x+p.x,y+p.y);
	}
	
};

inline double pointDis(point p1,point p2)
{
	return sqrt(mul(p1.x-p2.x)+mul(p1.y-p2.y));
}

inline double pointMulDis(point p1,point p2)
{
	return mul(p1.x-p2.x)+mul(p1.y-p2.y);
}

inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

double dotmult(point sp,point ep,point op)
{
	return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}

double get_angle(const point &sp,const point &ep,const point &op)
{
	double a=atan2(sp.y-op.y,sp.x-op.x);
	double b=atan2(ep.y-op.y,ep.x-op.x);
	if(b-a>pi) a+=2*pi;
	if(a-b>pi) b+=2*pi;
	return a-b;
}
const point ZERO(0,0);

struct polygen
{
	point p[SIZE];
	int sz;
	
	polygen(){}
	polygen(int isz){sz=isz;}
};


struct circle
{
	point c;
	double r;
	circle(){}
	circle(const point &ic,double ir)
	{
		c=ic;r=ir;
	}
	
	void __cap_add(const point& u,const point& v,point* p,int& ind)
	{
		double a=pointMulDis(v,u);
		double b=-2*dotmult(v,ZERO,u);
		double c=mul(u.x)+mul(u.y)-mul(r);
		double d=mul(b)-4*a*c;
		p[ind++]=u;
		if(zero(d)<0) return;	
		d=sqrt(d);
		double t1=(-b+d)/(2*a);
		double t2=(-b-d)/(2*a);
		if(t1>t2) swap(t1,t2);
		if(zero(t1)>0 && zero(t1-1)<0) p[ind++]=u+(v-u)*t1;
		if(zero(t2)>0 && zero(t2-1)<0 && zero(t1-t2)!=0) p[ind++]=u+(v-u)*t2;
	}

	double __cap_area(const point& u,const point& v)
	{
		if(zero(hypot((u.x + v.x)/2.0,(u.y + v.y)/2.0)-r)<0)
		{
			return xmult(u,v,ZERO)/2;
		}
		else 
		{
			double t=get_angle(v,u,ZERO);
			return mul(r)*t/2;
		}
	}
	double cross_area_polygen(const polygen &poly)
	{
		point st[SIZE<<1];
		int ind=0;
		for(int i=0;i<poly.sz;i++)
		{
			int j=(i+1)%poly.sz;
			__cap_add(poly.p[i],poly.p[j],st,ind);
		}
		double res=0;
		for(int i=0;i<ind;i++)
		{
			int j=(i+1)%ind;
			//print(st[i].x<<' '<<st[i].y);
			res+=__cap_area(st[i],st[j]);
		}
		return fabs(res);
	}
		
};

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	double a,b;
	while(input(a))
	{
		circle c=circle(ZERO,a);
		input(n);
		polygen poly=polygen(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly.p[i]=point(a,b);
		}
		printf("%.2f\n",c.cross_area_polygen(poly));
	}
	return 0;
}
