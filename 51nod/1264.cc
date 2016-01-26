#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const double eps = 1e-6;
const double pi = acos(-1);

//判定正负零，消除误差的影响
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

//点类
struct point
{
    double x,y;
    point(){}
    point(double i_x,double i_y)
    {
        x=i_x;y=i_y;
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
    friend bool operator == (const point& pa,const point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};

//返回vector(op->sp)与vector(op->ep)的向量积
//abs(xmult(sp,ep,op)) = 2* 三角形面积（sp,ep,op)
//xmult(sp,ep,op) = |op->sp| * |op->ep| * sin(sop) -> 边op->sp到边op->ep的夹角
//正负性用右手定则判定，从手指从op->sp握到op->ep方向
inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}


inline double pointDis(point p1,point p2)
{
	return sqrt(mul(p1.x-p2.x)+mul(p1.y-p2.y));
}

inline double pointMulDis(point p1,point p2)
{
	return mul(p1.x-p2.x)+mul(p1.y-p2.y);
}



//线段
struct segment
{
	point p1,p2;
	segment(){}
	segment(const point &ip1,const point &ip2)
	{
		p1=ip1;p2=ip2;
	}
	double distopoint(const point &c)//点到线段的最小距离
	{
		double x=mul(p1.x-c.x)+mul(p1.y-c.y);
		double y=mul(p2.x-c.x)+mul(p2.y-c.y);
		double z=mul(p1.x-p2.x)+mul(p1.y-p2.y);
		if(x+z-y<0 || y+z-x<0) return sqrt(min(x,y));
		return fabs(xmult(c,p1,p2)/sqrt(z));
	}
	double distoline(const point &c)//点到线段所在直线的最小距离
	{
		return fabs(xmult(c,p1,p2))/pointDis(p1,p2);
	}	
};


//直线
struct line
{
    double a,b,c;
    line(){}
    line(double i_a,double i_b,double i_c)
    {
        a=i_a;b=i_b;c=i_c;
    }
    
    //判定直线相等
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
	
	//求过p点的，垂直于l的直线
	line make_vertical(const point &p)
	{
		line res=(*this);
		swap(res.a,res.b);
		res.b*=-1;
		res.c=-(res.a*p.x+res.b*p.y);

		return res;
	}
	
	//点到直线的距离,精度问题！！！
	//可以采用点到线段所在直线的长度代替，见Segment类
	double distopoint(const point &p)
	{
		return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
	}
};


//返回vector(op->sp)与vector(op->ep)的数量积
//dotmult(sp,ep,op) = |op->sp| * |op->ep| * cos(sop) -> 边op->sp到边op->ep的夹角
double dotmult(point sp,point ep,point op)
{
	return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}

//求向量的夹角，从(sp->op)到(ep->op)，较精确
double getangle(const point &sp,const point &ep,const point &op)
{
	double a=atan2(sp.y-op.y,sp.x-op.x);
	double b=atan2(ep.y-op.y,ep.x-op.x);
	if(b-a>pi) a+=2*pi;
	if(a-b>pi) b+=2*pi;
	return a-b;
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

//线段延长
segment extendSegment(point p1,point p2,int flag,double ext)
{
	//flag==0时，不延长;
	//flag==1时，从p1向p2延长
	//flag==2时，从p2向p1延长
	//flag==3时，双向延长
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=ext/fabs(p1.x-p2.x);
	if(d==0||fabs(p1.y-p2.y)>eps) d=ext/fabs(p1.y-p2.y);
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

bool onSegment(segment s,point p)
{
	return zero(xmult(s.p2,p,s.p1))==0 &&
			zero((p.x-s.p1.x)*(p.x-s.p2.x))<=0 &&
			zero((p.y-s.p1.y)*(p.y-s.p2.y))<=0;
}


int main() {
    int T;
    input(T);
    
    while (T--) {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        
        point p1 = {x1, y1};
        point p2 = {x2, y2};
        point p3 = {x3, y3};
        point p4 = {x4, y4};
        
        point tmp;
        
        segment s1 = {p1, p2};
        segment s2 = {p3, p4};
        
        if (segIntersect(s1, s2, tmp)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
