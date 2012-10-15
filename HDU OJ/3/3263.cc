//Result:2012-10-14 19:56:31	Accepted	3263	0MS	280K	3335 B	G++	Wizmann
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

inline int mul(int x){	return x*x;}

const double eps=1e-8;
const double inf=1e16;

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
	point(double ix,double iy){x=ix;y=iy;}
	friend bool operator < (const point& pa,const point& pb)
	{
		return pa.x<pb.x;
	}
	friend bool operator == (const point& pa,const point& pb)
	{
		return (zero(pa.x-pb.x)==0 && (zero(pa.y-pb.y)==0));
	}
};

inline double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

double pntDis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


struct segment
{
	point p1,p2;
	segment(){}
	segment(const point& ip1,const point& ip2)
	{
		p1=ip1;p2=ip2;
	}
	double distoline(const point &c)//点到线段所在直线的最小距离
	{
		return fabs(xmult(c,p1,p2))/pntDis(p1,p2);
	}
};

struct polygen
{
	int sz;
	point array[SIZE+5];
	polygen(){}
	polygen(int isz){sz=isz;}
};

polygen poly;

namespace ConvexHull//一定要多于三个点
{
	int sz;
	point array[SIZE];
	point stack[SIZE];
	point *p;
	inline void push(point n){*p=n;	p++;}
	inline void pop(){p--;}
	inline void init(int isz)
	{
		sz=isz;
		memset(stack,0,sizeof(stack));
		p=stack;
	}

	int cmp(point p1,point p2)
	{
		if(xmult(p1,p2,array[0])>0) return 1;
		else if(xmult(p1,p2,array[0])==0 && pntDis(p1,array[0])<pntDis(p2,array[0])) return 1;
		else return 0;
	}
	int findtop()
	{
		int res=0;

		for(int i=1;i<sz;i++)
		{
			if(array[i].y<array[res].y) res=i;
			else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
		}
		return res;
	}

	int graham()
	{
		int top=findtop();
		push(array[top]);
		swap(array[0],array[top]);
		sort(array+1,array+sz,cmp);

		push(array[1]);
		push(array[2]);
		for(int i=3;i<sz;i++)
		{
			while(xmult(array[i],*(p-1),*(p-2))>0) pop();//有等号时，不包括点都在一条直线的情况
			push(array[i]);
		}
		return p-stack;
	}
};

double checkMaxLen(int a,int b)
{
	return pntDis(poly.array[a],poly.array[b]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,sz;
	double a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&sz);
		poly=polygen(sz);
		for(int i=0;i<sz;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly.array[i]=point(a,b);
		}

		double maxlen=-inf;
		for(int i=0;i<sz;i++)
		{
			for(int j=0;j<sz;j++) if(i!=j)
			{
				maxlen=max(maxlen,checkMaxLen(i,j));
			}
		}
		int csz;
		scanf("%d",&csz);
		ConvexHull::init(csz);
		for(int i=0;i<csz;i++)
		{
			scanf("%lf%lf",&a,&b);
			ConvexHull::array[i]=point(a,b);
		}
		csz=ConvexHull::graham();

		double coinlen=inf;

		for(int i=1;i<=csz;i++)
		{
			double tmp=0;
			for(int j=0;j<csz;j++)
			{
				double dis=segment(ConvexHull::stack[(i-1+csz)%csz],ConvexHull::stack[i]).distoline(ConvexHull::stack[j]);
				if(dis>tmp) tmp=dis;
			}
			if(coinlen>tmp) coinlen=tmp;
		}
		if(zero(maxlen-coinlen)>=0) puts("legal");
		else puts("illegal");
	}
	return 0;
}


