//Result:wizmann	3335	Accepted	764K	16MS	G++	3446B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double inf=1e100;
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
	friend bool operator == (const point& pa,const point& pb)
	{
		return (!zero(pa.x-pb.x)) && (!zero(pa.y-pb.y));
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

line makeline(segment s)
{
	return makeline(s.p1,s.p2);
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

bool segIntersect(segment s1,segment s2,point &p)
{
	if( (max(s1.p1.x,s1.p2.x)>=min(s2.p1.x,s2.p2.x)) &&
		(max(s1.p1.y,s1.p2.y)>=min(s2.p1.y,s2.p2.y)) &&
		(max(s2.p1.x,s2.p2.x)>=min(s1.p1.x,s1.p2.x)) &&
		(max(s2.p1.y,s2.p2.y)>=min(s1.p1.y,s1.p2.y)) &&
		!zero(xmult(s1.p1,s2.p1,s2.p2) * xmult(s1.p2,s2.p1,s2.p2)) &&
		!zero(xmult(s2.p1,s1.p1,s1.p2) * xmult(s2.p2,s1.p1,s1.p2)))
	{
		lineIntersect(makeline(s1),makeline(s2),p);
		return true;
	}
	else return false;
}

struct polygen
{
	deque<point> pvec;
	
	//如果是顺时针序，则clockwise=true
	//否则是将其设为false
	void push_point(const point& i_p,bool clockwise=true)
	{
		if(clockwise) pvec.push_back(i_p);
		else pvec.push_front(i_p);
	}
	
	void KernelCut(segment s)
	{
		deque<point> core;
		int sz=(int)pvec.size();
		for(int i=0;i<sz;i++)
		{
			if(zero(xmult(pvec[i],s.p2,s.p1))>=0)
			{
				core.push_back(pvec[i]);
			}
			else
			{
				point cp;
				if(zero(xmult(pvec[i],s.p2,s.p1) * xmult(pvec[(i-1+sz)%sz],s.p2,s.p1))<0)
				{
					line l1=makeline(s);
					line l2=makeline(pvec[i],pvec[(i-1+sz)%sz]);
					lineIntersect(l1,l2,cp);
					core.push_back(cp);
				}
				
				if(zero(xmult(pvec[i],s.p2,s.p1) * xmult(pvec[(i+1)%sz],s.p2,s.p1))<0)
				{
					line l1=makeline(s);
					line l2=makeline(pvec[i],pvec[(i+1)%sz]);
					lineIntersect(l1,l2,cp);
					core.push_back(cp);
				}
			}
		}
		pvec=core;
	}

	void getKernel()
	{
		deque<point> backup;
		backup=pvec;
		int sz=backup.size();
		for(int i=0;i<sz;i++)
		{
			KernelCut(segment(backup[i],backup[(i+1)%sz]));
		}
	}
};

int main()
{
	int T,n;
	double a,b;
	input(T);
	while(T--)
	{
		polygen poly;
		input(n);
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			poly.push_point(point(a,b));
		}
		//poly.sort();
		poly.getKernel();
		if(poly.pvec.size()>0) print("YES");
		else print("NO");
	}
	return 0;
}
