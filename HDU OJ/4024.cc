//Result:2012-08-30 19:52:26	Accepted	4024	15MS	268K	1858 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double eps=1e-8;
const double inf=1e9;

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
	point(double ix,double iy){x=ix;y=iy;}
	friend point operator + (const point& a,const point& b)
	{
		point res;
		res.x=a.x+b.x; res.y=a.y+b.y;
		return res;
	}
	friend point operator - (const point& a,const point& b)
	{
		point res;
		res.x=a.x-b.x; res.y=a.y-b.y;
		return res;
	}
	friend point operator * (const point& a,double b)
	{
		point res;
		res.x=a.x*b; res.y=a.y*b;
		return res;
	}
};
inline double pointDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}


point runner,sniper;
point dir;
const point ROOT=point(0,0);
double vs,vb,L;

double slove()
{
	double tb=L/vb;
	double l=tb,r=inf;
	
	while(zero(l-r)<0)
	{
		double mid=(l+r)/2;
		point now=runner+dir*mid;
		double dis=pointDis(now,sniper);
		if(dis<L)//如果距离小于射程，则枪手要向远处跑，从而使射程达到最大
		{
			if(dis<L-(mid-tb)*vs) l=mid;
			else r=mid;
		}
		else//反之，枪手要向近处追赶敌人
		{
			if((mid-tb)*vs+L<dis) l=mid;
			else r=mid;
		}
	}
	return l;
}
		

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	while(1)
	{
		double sum=0;
		scanf("%lf%lf",&a,&b);
		runner=point(a,b);
		sum+=fabs(a)+fabs(b);

		scanf("%lf%lf",&a,&b);
		sniper=point(a,b);
		sum+=fabs(a)+fabs(b);

		scanf("%lf%lf",&a,&b);
		dir=point(a,b);
		sum+=fabs(a)+fabs(b);
		
		scanf("%lf%lf",&vs,&vb);
		sum+=fabs(vs)+fabs(vb);

		scanf("%lf",&L);
		sum+=fabs(L);

		if(zero(sum)==0) break;
		
		printf("%.3lf %.3lf\n",L,slove());
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////

//Result:2012-08-30 19:56:58	Accepted	4024	15MS	264K	3621 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double eps=1e-8;
const double inf=1e9;

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
	point(double ix,double iy){x=ix;y=iy;}
	friend point operator + (const point& a,const point& b)
	{
		point res;
		res.x=a.x+b.x; res.y=a.y+b.y;
		return res;
	}
	friend point operator - (const point& a,const point& b)
	{
		point res;
		res.x=a.x-b.x; res.y=a.y-b.y;
		return res;
	}
	friend point operator * (const point& a,double b)
	{
		point res;
		res.x=a.x*b; res.y=a.y*b;
		return res;
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
	line make_vertical(const point &p)
	{
		line res=*this;
		swap(res.a,res.b);
		res.b*=-1.;
		res.c=-(res.a*p.x+res.b*p.y);
		return res;
	}
	double distopoint(const point &p)
	{
		return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
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
        res.a=sig*res.a;
    }
    res.b=sig*(p1.x-p2.x);
    res.c=sig*(p1.y*p2.x-p2.y*p1.x);
    return res;
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

inline double pointDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

point runner,sniper;
point dir;
const point ROOT=point(0,0);
double vs,vb,L;


double dotmult(point sp,point ep,point op)
{
	return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}

double slove()
{
	double a,b,c,tleft,tright;
	double vr=pointDis(dir,ROOT);
	if(vr>vs || vr>vb) return inf;
	line runaway=makeline(runner,runner+dir);
	double H=runaway.distopoint(sniper);

	double tb=L/vb;

	point p;
	line tmp=runaway.make_vertical(sniper);
	lineIntersect(tmp,runaway,p);
	double D;
	if(dotmult(sniper,runner+dir,runner)<0) D=-pointDis(runner,p)-tb*vr;//如果垂点在射线外，则要做特殊处理
	else D=pointDis(runner,p)-tb*vr;
	double tt=inf;
	
	
	a=mul(vs)-mul(vr);
	b=2*D*vr+2*vs*L;
	c=mul(L)-mul(D)-mul(H);
	tleft=(-b-sqrt(mul(b)-4*a*c))/(2*a);
	tright=(-b+sqrt(mul(b)-4*a*c))/(2*a);
	//printf("%lf %lf %lf\n",a,b,c);
	if(tleft>=0) tt=min(tt,tleft);
	if(tright>=0) tt=min(tt,tright);
	//print(tleft<<" "<<tright);
	
	
	vs=-vs;
	a=mul(vs)-mul(vr);
	b=2*D*vr+2*vs*L;
	c=mul(L)-mul(D)-mul(H);
	tleft=(-b-sqrt(mul(b)-4*a*c))/(2*a);
	tright=(-b+sqrt(mul(b)-4*a*c))/(2*a);
	
	if(tleft>=0) tt=min(tt,tleft);
	if(tright>=0) tt=min(tt,tright);
	//print(tleft<<" "<<tright);
	return tt+tb;
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	while(1)
	{
		double sum=0;
		scanf("%lf%lf",&a,&b);
		runner=point(a,b);
		sum+=fabs(a)+fabs(b);

		scanf("%lf%lf",&a,&b);
		sniper=point(a,b);
		sum+=fabs(a)+fabs(b);

		scanf("%lf%lf",&a,&b);
		dir=point(a,b);
		sum+=fabs(a)+fabs(b);
		
		scanf("%lf%lf",&vs,&vb);
		sum+=fabs(vs)+fabs(vb);

		scanf("%lf",&L);
		sum+=fabs(L);

		if(zero(sum)==0) break;
		
		printf("%.3lf %.3lf\n",L,slove());
	}
	return 0;
}

