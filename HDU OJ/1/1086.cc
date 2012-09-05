//Result:2012-07-16 17:02:28	Accepted	1086	31MS	484K	2910 B	G++	Wizmann
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
#define SIZE 128
#define eps 1e-9
#define ext 1e10

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
    friend bool operator == (const point& pa,const point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};

struct segment
{
    point p1,p2;
    segment(){}
    segment(const point& i_p1,const point& i_p2)
    {
        p1=i_p1;p2=i_p2;
    }
};

struct line
{
    double a,b,c;
    line(){}
    line(double i_a,double i_b,double i_c)
    {
        a=i_a;b=i_b;c=i_c;
    }
};

inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

line makeLine(point p1,point p2)
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

bool onSegment(segment s,point p)
{
    return fabs(xmult(s.p2,p,s.p1))<eps && (p.x-s.p1.x)*(p.x-s.p2.x)<=0 && (p.y-s.p1.y)*(p.y-s.p2.y)<=0;
}

double pointDis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


segment array[SIZE+5];
int n;

int main()
{
	double a,b,c,d;
	point tmp;
	while(input(n) && n)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			array[i]=segment(point(a,b),point(c,d));
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(segIntersect(array[i],array[j],tmp)) ans++;
			}
		}
		print(ans);
	}
	return 0;
}
		
	
	
