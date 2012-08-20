//Result:wizmann	1474	Accepted	764K	0MS	G++	3850B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define pb push_back

const double eps=1e-10;

inline int zero(double x)
{
	if(x<-eps) return -1;
	else if(fabs(x)<eps) return 0;
	else return 1;
}

struct point
{
	double x,y;
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
	
	void setpoint(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
	
	friend bool operator == (const point& pa,const point& pb)
	{
		return zero(pa.x-pb.x) && zero(pa.y-pb.y);
	}
};

struct segment
{
	point p1,p2;
	
	segment(){}
	segment(double x1,double y1,double x2,double y2)
	{
		p1.setpoint(x1,y1);
		p2.setpoint(x2,y2);
	}
	segment(point t1,point t2){p1=t1;p2=t2;}
	
	inline void setsegment(point a,point b){p1=a;p2=b;}
	inline void setsegment(double x1,double y1,double x2,double y2)
	{
		p1.setpoint(x1,y1);
		p2.setpoint(x2,y2);
	}
};


struct line
{
	double a,b,c;
	
	friend bool operator == (const line x,const line y)
	{
		if(fabs(x.a-y.a)<eps&&fabs(x.b-y.b)<eps&&fabs(x.c-y.c)<eps) return true;
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
	if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   fabs((xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2))<=eps)&&
	   fabs((xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2))<=eps))//跨立实验
	{
		lineIntersect(makeLine(l1),makeLine(l2),p);
		return true;
	}
	else return false;
}


struct polygen
{
	point pvec[SIZE];
	point core[SIZE];
	int sz;//kernel points
	polygen(){sz=0;}
	
	inline void push_point(const point& p)
	{
		pvec[sz++]=p;
	}
	
	void Cut(segment s)
	{
		int q=0;
		//print(sz);
		for(int i=0;i<sz;i++)
		{
			if(xmult(pvec[i],s.p2,s.p1)>=0)
			{
				//因为线段是顺时针给出的，如果是逆时针就是<=0
				core[q++]=pvec[i]; //若是则存储
			}
			else
			{
				point cp;
                if(xmult(pvec[i],s.p2,s.p1) * xmult(pvec[(i+1)%sz],s.p2,s.p1)<0)
                {
					point cp;
					line l1=makeLine(s);
					line l2=makeLine(pvec[i],pvec[(i+1)%sz]);
					lineIntersect(l1,l2,cp);
					core[q++]=cp;
				}
			}
		}
		//最后的p数组存放半平面的点集合
		for(int i=0;i<q;i++)
		{
			pvec[i]=core[i];
		}
		//print("CORE: "<<core.size());
		sz=q;
		//print(sz);
	}
	
	void getKernel()
	{
		int n=sz;
		point p[SIZE];
		for(int i=0;i<n;i++) p[i]=pvec[i];
		for(int i=0;i<n;i++)
		{
			segment s(p[i],p[(i+1)%n]);
			Cut(s);
		}
	}
};

int n;
polygen poly;

int main()
{
	double a,b;
	int cas=1;
	while(input(n) && n)
	{
		poly=polygen();
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly.push_point(point(a,b));
		}
		poly.getKernel();
		printf("Floor #%d\n",cas++);
		if(poly.sz>0) print("Surveillance is possible.");
		else print("Surveillance is impossible.");
		puts("");
	}
	return 0;
}
