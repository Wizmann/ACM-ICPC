//Result:2012-09-06 20:35:55	Accepted	3694	0MS	260K	2561 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double inf=1e10;
const double eps=1e-8;

#define SIZE 5

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
inline double pntDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}



inline double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

namespace ConvexHull
{
	int sz;
	point array[SIZE];
	point stack[SIZE];
	point *p;
	inline void push(point n){*p=n;p++;}
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
			while(xmult(array[i],*(p-1),*(p-2))>0) pop();
			push(array[i]);
		}
		return p-stack;
	}
}




int main()
{
	freopen("input.txt","r",stdin);
	double a,b,c,d,e,f,g,h;
	while(1)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h);
		if(!zero(a+1) && !zero(b+1) && !zero(c+1) && !zero(d+1) &&
				!zero(e+1) && !zero(f+1) && !zero(g+1) && !zero(h+1)) break;

		ConvexHull::array[0]=point(a,b);
		ConvexHull::array[1]=point(c,d);
		ConvexHull::array[2]=point(e,f);
		ConvexHull::array[3]=point(g,h);
		ConvexHull::init(4);
		int num=ConvexHull::graham();
		if(num==4)
		{
			printf("%.4lf\n",pntDis(ConvexHull::array[0],ConvexHull::array[2]) + 
								pntDis(ConvexHull::array[1],ConvexHull::array[3]));
		}
		else
		{
			double ans=inf;
			for(int i=0;i<4;i++)
			{
				double res=0;
				for(int j=0;j<4;j++)
				{
					res+=pntDis(ConvexHull::array[i],ConvexHull::array[j]);
				}
				ans=min(ans,res);
			}
			printf("%.4lf\n",ans);
		}			
	}
	return 0;
}

