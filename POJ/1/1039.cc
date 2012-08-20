//Result:Wizmann	1039	Accepted	204K	329MS	C++	4171B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const double eps=1e-8;
const double inf=1e6;

typedef struct point
{
	double x,y;
	
	inline void setpoint(double a,double b){x=a;y=b;}
	inline void printpoint()
	{
		printf("%.2f,%.2f\n",x,y);
	}
}point;

typedef struct segment
{
	point p1,p2;
	
	inline void setsegment(point a,point b){p1=a;p2=b;}
	inline void printsegment()
	{
		p1.printpoint();p2.printpoint();
	}
}segment;

typedef struct line
{
	double a,b,c;
	
	inline void setline(double ta,double tb,double tc)
	{
		a=ta;b=tb;c=tc;
	}
}line;

double vectorProduct(point sp,point ep,point op)
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

line makeLine(segment s)
{
	return makeLine(s.p1,s.p2);
}

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

bool segIntersect(segment l1,segment l2,point &p)
{
	if((max(l1.p1.x,l1.p2.x)>min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   (vectorProduct(l1.p1,l2.p1,l2.p2)*vectorProduct(l1.p2,l2.p1,l2.p2)<=0)&&
	   (vectorProduct(l2.p1,l1.p1,l1.p2)*vectorProduct(l2.p2,l1.p1,l1.p2)<=0))//跨立实验
	{
		lineIntersect(makeLine(l1),makeLine(l2),p);
		return true;
	}
	else return false;
}

bool online(segment s,point p)
{
	return(vectorProduct(s.p2,p,s.p1)==0&&(p.x-s.p1.x)*(p.x-s.p2.x)<=0&&(p.y-s.p1.y)*(p.y-s.p2.y)<=0);
}

bool segOrdIntersect(segment s1,segment s2,point &p)//普通相交，无特殊情况
{
	if((segIntersect(s1,s2,p))&&
	   (!online(s1,s2.p1))&&
	   (!online(s1,s2.p2))&&
	   (!online(s2,s1.p1))&&
	   (!online(s2,s1.p2)))
	{
		segIntersect(s1,s2,p);
		return true;
	} 
	else return false;
}

segment extendSegment(point p1,point p2,int flag)
{
	//flag==0时，不延长;
	//flag==1时，从p1向p2延长
	//flag==2时，从p2向p1延长
	//flag==3时，双向延长
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=fabs(inf/(p1.x-p2.x));
	if(d==0||fabs(p1.y-p2.y)>eps) d=fabs(inf/(p1.y-p2.y));
	if(flag & 1)
	{
		res.p2.x+= (p2.x-p1.x)*d;
		res.p2.y+= (p2.y-p1.y)*d;
	}
	if(flag & 2)
	{
		res.p1.x+= (p1.x-p2.x)*d;
		res.p1.y+= (p1.y-p2.y)*d;
	}
	return res;
}

inline double sqr(double a){return a*a;}

double distance(point p1,point p2)
{
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

point array[50];
int n;

double check(segment s)
{
	double res=inf;
	point p;
	segment t;
	for(int i=0;i<n-1;i++)
	{
		t.setsegment(array[i],array[i+1]);
		t.p1.y+=eps;
		t.p2.y+=eps;
		if(segIntersect(s,t,p)) res=min(p.x,res);
		//p.printpoint();
		t.p1.y-=(1+2*eps);
		t.p2.y-=(1+2*eps);
		if(segIntersect(s,t,p)) res=min(p.x,res);
		//p.printpoint();
	}
	return res;
}


int main()
{
	double a,b;
	while(scanf("%d",&n),n)
	{
		memset(array,0,sizeof(array));
		double ans=-inf;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i].setpoint(a,b);
			array[i+n].setpoint(a,b-1);
		}
		segment base;
		base.p1=array[0];
		base.p1.y+=eps;
		base.p2=array[n];
		base.p2.y-=eps;
		segment ray;
		point tp;
		for(int i=0;i<2*n;i++)
		{
			for(int j=i+1;j<2*n;j++)
			{
				ray=extendSegment(array[i],array[j],3);
				if(!segIntersect(base,ray,tp)) continue;
				ray=extendSegment(tp,array[j],1);
				//tp.printpoint();
				if(fabs(tp.x-array[j].x)<eps)
				{
					if(fabs(tp.x-array[i].x)<eps) continue;
					ray=extendSegment(tp,array[i],1);
				}
				double res=check(ray);
				//printf("I:%d,J:%d,RES=%.2f\n",i,j,res);
				ans=max(ans,res);
			}
		}
		if(ans==inf) puts("Through all the pipe.");
		else printf("%.2f\n",ans);
	}
	return 0;
}
