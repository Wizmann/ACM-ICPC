//Result:wizmann	2079	Accepted	2336K	110MS	G++	2502B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50100

const double eps=1e-8;
const double inf=1e100;

inline double mul(double x)
{
	return x*x;
}

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

struct point
{
	double x,y;
	point(){}
	point(double ix,double iy)
	{
		x=ix;y=iy;
	}
};

double pntDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double xmult(const point &sp,const point &ep,const point &op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

double Area(const point &a,const point &b,const point &c)
{
	return fabs(xmult(a,b,c))/2.0;
}


namespace ConvexHull
{
	int sz;
	point array[SIZE],stack[SIZE];
	point *p;

	inline void push(point n){*p=n;p++;}
	inline void pop(){p--;}
	inline void init(int isz)
	{
		sz=isz;
		memset(stack,0,sizeof(stack));
		p=stack;
	}

	int cmp(const point &p1,const point &p2)
	{
		if(xmult(p1,p2,array[0])>0) return 1;
		else if(zero(xmult(p1,p2,array[0]))==0 && pntDis(p1,array[0])<pntDis(p2,array[0])) return 1;
		else return 0;
	}

	int findtop()
	{
		int res=0;
		for(int i=1;i<sz;i++)
		{
			if(array[i].y<array[res].y) res=i;
			else if(array[i].y==array[res].y && array[i].x<array[res].x) res=1;
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
			while(zero(xmult(array[i],*(p-1),*(p-2)))>0) pop();
			push(array[i]);
		}
		return p-stack;
	}
		
	double maxTriangle(int num)
	{
		double ret=0,tmp;
		int p=1,q=2;
		stack[num]=stack[0];
		for(int i=0;i<num;i++)
		{
			while(Area(stack[i],stack[q],stack[p+1])>(tmp=Area(stack[i],stack[q],stack[p]))) p=(p+1)%num;
			ret=max(ret,tmp);
			while(Area(stack[i],stack[q+1],stack[p])>(tmp=Area(stack[i],stack[q],stack[p]))) q=(q+1)%num;
			ret=max(ret,tmp);
		}
		return ret;
	}
}

int n;

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	while(input(n) && n!=-1)
	{
		ConvexHull::init(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			ConvexHull::array[i]=point(a,b);
		}
		int len=ConvexHull::graham();

		printf("%.2lf\n",ConvexHull::maxTriangle(len));
	}
	return 0;
}
