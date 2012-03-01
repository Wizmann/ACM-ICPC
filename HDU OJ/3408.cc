//Result:Accepted	3408	0MS	504K	3744 B	G++	Wizmann

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define MAKELONG 10000.00
#define eps 1e-5
#define inf 10000000000000000.0

inline bool zero(double x)
{
	if(fabs(x)<eps) return true;
	else return false;
}

struct point
{
	double x,y;
	point(){}
	point(double  i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

typedef struct line
{
	double a,b,c;
	
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
	inline void setline(double ta,double tb,double tc)
	{
		a=ta;b=tb;c=tc;
	}
}line;


struct segment
{
	point p1,p2;

	segment(){}
	segment(point i_p1,point i_p2)
	{
		p1=i_p1;
		p2=i_p2;
	}
};

struct pig
{
	vector<point> pntVec;
	vector<point> hit;

	pig()
	{
		pntVec.clear();
		hit.clear();
	}
};

pig array[10];
point MM,arrow;
int n;

double xmult(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}//可以进行重载


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

line makeLine(segment s){return makeLine(s.p1,s.p2);}//由线段生成一条直线
bool lineIntersect(line l1,line l2,point &p)//直线是否相交，并求交点
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

void checkIntersection(segment& kill,pig& node)
{
	int sz=node.pntVec.size();
	for(int i=0;i<sz;i++)
	{
		segment tseg(node.pntVec[i%sz],node.pntVec[(i+1)%sz]);
		point p;
		if(segIntersect(kill,tseg,p))
		{
			node.hit.push_back(p);
		}
	}
}

inline double mul(double x)
{
	return x*x;
}

double pntDistance(point& a,point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	while(input(n) && n)
	{
		input(a>>b);
		MM=point(a,b);
		input(a>>b);
		arrow=point(a,b);
		for(int i=0;i<n;i++)
		{
			int m;
			input(m);
			pig t=pig();
			for(int j=0;j<m;j++)
			{
				input(a>>b);
				t.pntVec.push_back(point(a,b));
			}
			array[i]=t;
		}

		point end(MM.x+arrow.x*MAKELONG,MM.y+arrow.y*MAKELONG);
		segment kill(MM,end);

		for(int i=0;i<n;i++)
		{
			checkIntersection(kill,array[i]);
		}
		int pos=-1;
		double mindis=inf;
		for(int i=0;i<n;i++)
		{
			int sz=array[i].hit.size();
			for(int j=0;j<sz;j++)
			{
				double t=pntDistance(MM,array[i].hit[j]);
				if(mindis>t)
				{
					pos=i;
					mindis=t;
				}
			}
		}
		if(pos!=0) print("MISS");
		else print("HIT");
	}
	return 0;
}


