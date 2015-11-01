#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const double eps = 1e-6;

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

inline double pntDis(const point& a, const point& b) {
    return sqrt(mul(a.x - b.x) + mul(a.y - b.y));
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
		return fabs(xmult(c,p1,p2))/pntDis(p1,p2);
	}	
};

int main() {
    int T;
    input(T);
    while (T--) {
        point c;
        int r;
        input(c.x >> c.y >> r);
        
        vector<point> points(3);
        
        for (int i = 0; i < 3; i++) {
            input(points[i].x >> points[i].y);
        }
        
        bool res = false;
        for (int i = 0; i < 3; i++) {
            segment s(points[i], points[(i + 1) % 3]);
            double d = s.distopoint(c);
            bool b = zero(pntDis(points[i], c) - r) < 0 && zero(pntDis(points[(i + 1) % 3], c) - r) < 0;
            if (zero(d - r) <= 0 && !b) {
                res = true;
            }
        }
        
        puts(res? "Yes": "No");
    }
    return 0;
}
