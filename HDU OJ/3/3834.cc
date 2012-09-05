//Result:2012-07-29 10:44:15	Accepted	3834	15MS	524K	4416 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double inf=1e12;
const double eps=1e-8;
const double pi=acos(-1.);

inline int zero(double x)
{
	if(x<-eps) return -1;
	else if(fabs(x)<eps) return 0;
	else return 1;
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
	
	point operator * (double a) const
	{
		point res=point(x*a,y*a);
		return res;
	}
	
	point operator + (const point &b) const
	{
		point tmp=point(x+b.x,y+b.y);
		return tmp;
	}
	
	point operator - (const point &b) const
	{
		point tmp=point(x-b.x,y-b.y);
		return tmp;
	}
};

inline double pointDis(const point &p1,const point &p2)
{
	return sqrt(mul(p1.x-p2.x)+mul(p1.y-p2.y));
}

inline double pointMulDis(const point &p1,const point &p2)
{
	return mul(p1.x-p2.x)+mul(p1.y-p2.y);
}

inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

//直线
struct line
{
    double a,b,c;
    line(){}
    line(double i_a,double i_b,double i_c)
    {
        a=i_a;b=i_b;c=i_c;
    }
	
	double distopoint(const point &p)//点到直线的距离
	{
		return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
	}
};

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

struct circle
{
	point c;
	double r;
	circle(){}
	circle(const point& ic,double ir)
	{
		c=ic;r=ir;
	}
};

point rotate(point v,point circle,double angle,double scale=1.0)
{
	point ret=circle;
	v.x-=circle.x;v.y-=circle.y;
	circle.x=scale*cos(angle);
	circle.y=scale*sin(angle);
	ret.x+=v.x*circle.x-v.y*circle.y;
	ret.y+=v.x*circle.y+v.y*circle.x;
	return ret;
}



double getangle(const point& sp,const point &ep,const point &op)
{
	double a=atan2(sp.y-op.y,sp.x-op.x);
	double b=atan2(ep.y-op.y,ep.x-op.x);
	if(b-a>pi) a+=2*pi;
	if(a-b>pi) b+=2*pi;
	return a-b;
}


circle g;
point me;
point dir;
double tt;
const point ZERO(0,0);

point slove(double ft,double dis)
{
	point a,b;
	double dirlen=pointDis(dir,ZERO);
	point tmp=point(dir.x*ft/dirlen,dir.y*ft/dirlen);
	tmp=tmp+me;
	
	
	double flag=1;
	double ang=getangle(me,g.c,tmp);
	if(ang>0) flag=1;
	else flag=-1;
	ang=fabs(ang);
	if(ang>pi) ang-=pi;
	
	double cenang=pi-ang*2;
	double disone=sin(cenang/2)*g.r*2;
	
	long long coli=(dis/disone)+eps;
	//print(coli);
	point last=rotate(tmp,g.c,flag*coli*cenang);
	point last1=rotate(tmp,g.c,flag*(coli+1)*cenang);
	
	dis-=disone*coli;
	
	last1=last1-last;
	double len=pointDis(last1,ZERO);
	last1.x/=len;last1.y/=len;
	last1=last1*dis;
	
	return last+last1;
}


point make_vertical_vector(point sp,point op,point np)
{
	double dx=sp.x-op.x;
	double dy=sp.y-op.y;
	swap(dx,dy);
	dx=-dx;
	
	return np+point(dx,dy);
}

double first_time_love()
{
	point next=me+dir;
	line l=makeline(me,next);
	double dis=l.distopoint(g.c);
	double res=sqrt(mul(g.r)-mul(dis));

	point pad=make_vertical_vector(next,me,g.c);
	
	double tmp=sqrt(pointMulDis(g.c,me)-mul(dis));
	
	if(xmult(me,pad,g.c)<0) res+=tmp;
	else res-=tmp;
	return res;
}
	
int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	double a,b,c;
	input(T);
	while(T--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		g.c=point(a,b);
		g.r=c;

		scanf("%lf%lf%lf",&a,&b,&c);
		me=point(a,b);
		g.r-=c;

		scanf("%lf%lf%lf",&a,&b,&c);
		dir=point(a,b);
		tt=c;
		
		double dis=pointDis(dir,ZERO)*tt;		
		double ft=first_time_love();
		//print(ft);
		if(ft>dis) print("first time call");
		else
		{
			dis-=ft;
			point ans=slove(ft,dis);
			printf("%.1lf %.1lf\n",ans.x+eps,ans.y+eps);
		}
	}
	return 0;
}
