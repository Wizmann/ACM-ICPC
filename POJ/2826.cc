//Result:wizmann	2826	Accepted	784K	625MS	G++	2722B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define eps 1e-8
#define INF 10100

struct point
{
	double x,y;
	
	point(){}
	point(double a,double b)
	{
		x=a;y=b;
	}
	
	//void printPoint(){print(x<<' '<<y);}
};

struct segment
{
	point p1,p2;
	
	segment(){};
	
	void setSegment(point a,point b)
	{
		p1=a;p2=b;
	}	
};

struct line
{
	double a,b,c;
	
	line(){}
	line(const segment& seg)
	{
		this->makeline(seg.p1,seg.p2);
	}
	
	void makeline(point p1,point p2)
	{
		a=p2.y-p1.y;
		int sig=1;
		if(a<0)
		{
			sig=-1;
			a*=sig;
		}
		b=sig*(p1.x-p2.x);
		c=sig*(p1.y*p2.x-p2.y*p1.x);
	}
		
};

double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

bool lineIntersect(line l1,line l2,point &p)
{
	double d=l1.a*l2.b-l2.a*l1.b;
	if(fabs(d)<eps) return false;
	else
	{
		p.x=(l2.c*l1.b-l1.c*l2.b)/d;
		p.y=(l2.a*l1.c-l1.a*l2.c)/d;
		return true;
	}
}


bool segIntersect(segment s1,segment s2,point &p)
{

	if(max(s1.p1.x,s1.p2.x)>=min(s2.p1.x,s2.p2.x) &&
		max(s1.p1.y,s1.p2.y)>=min(s2.p1.y,s2.p2.y) &&
		max(s2.p1.x,s2.p2.x)>=min(s1.p1.x,s1.p2.x) &&
		max(s2.p1.y,s2.p2.y)>=min(s1.p1.y,s1.p2.y) &&
		xmult(s1.p1,s2.p1,s2.p2)*xmult(s1.p2,s2.p1,s2.p2)<=eps &&
		xmult(s2.p1,s1.p1,s1.p2)*xmult(s2.p2,s1.p1,s1.p2)<=eps)
	{
		lineIntersect(line(s1),line(s2),p);
		return true;
	}
	else return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	double a,b,c,d;
	input(T);
	while(T--)
	{
		//print("Case: "<<T);
		segment seg1,seg2;
		point cross;
		input(a>>b>>c>>d);
		seg1.setSegment(point(a,b),point(c,d));
		input(a>>b>>c>>d);
		seg2.setSegment(point(a,b),point(c,d));
		
		if(segIntersect(seg1,seg2,cross))
		{
			//print(cross.x<<' '<<cross.y);
			segment parSeg,strSeg1,strSeg2;
			double miny=min(max(seg1.p1.y,seg1.p2.y),max(seg2.p1.y,seg2.p2.y));
			parSeg.setSegment(point(-INF,miny-eps),point(INF,miny-eps));
			
			point cr1,cr2,tp1,tp2;
			if(!segIntersect(seg1,parSeg,cr1) || !segIntersect(seg2,parSeg,cr2))
			{
				print("0.00");
			}
			else
			{
				strSeg1.setSegment(point(cr1.x,INF),point(cr1.x,cr1.y));
				strSeg2.setSegment(point(cr2.x,INF),point(cr2.x,cr2.y));
				if( (segIntersect(seg2,strSeg1,tp1) || segIntersect(seg1,strSeg2,tp2)))
				{
					print("0.00");
				}
				else
				{
					double bottom=cr1.x-cr2.x;
					double height=miny-cross.y;
					double ans=bottom*height/2.0;
					printf("%.2f\n",fabs(ans)+1e-6);
				}
			}
		}
		else print("0.00");
	}
	return 0;
}
		
