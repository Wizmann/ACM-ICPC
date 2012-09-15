//Result:2012-09-14 13:46:41	Accepted	1589	375MS	2096K	3346 B	G++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010

const double eps=1e-8;
const double inf=1e100;

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

inline double mul(double x)
{
	return x*x;
}

inline double xmult(const point &sp,const point &ep,const point &op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

inline double pntDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

bool cmpX(const point &a,const point &b)
{
	return a.x>b.x;
}

bool cmpY(const point &a,const point &b)
{
	return a.y<b.y;
}

point array[SIZE];
point ym[SIZE];


double minDisPointPair(int st,int end,point *ip)
{
	double res=inf;
	if(end-st<19)
	{
		for(int i=st;i<=end;i++)
		{
			for(int j=i+1;j<=end;j++)
			{
				res=min(res,pntDis(ip[i],ip[j]));
			}
		}
		return res;
	}
	else
	{
		int mid=(st+end)>>1;
		res=min(minDisPointPair(st,mid,ip),minDisPointPair(mid+1,end,ip));
		int yn=0;
		
		for(int i=st;i<=end;i++)
		{
			if(ip[i].x>=ip[mid].x-res && ip[i].x<=ip[mid].x+res) ym[yn++]=ip[i];
		}
		sort(ym,ym+yn,cmpY);
		for(int i=0;i<yn;i++)
		{
			for(int j=i+1;j<yn;j++)
			{
				if(ym[j].y-ym[i].y>=res) break;
				res=min(res,pntDis(ym[i],ym[j]));
			}
		}
		return res;
	}
}


namespace ConvexHull
{
	int sz;
	point stack[SIZE];
	point *p;
	inline void push(point ip){*p=ip;p++;}
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
		else if(zero(xmult(p1,p2,array[0]))==0 && pntDis(p1,array[0])<pntDis(p2,array[0])) return 1;
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
			while(zero(xmult(array[i],*(p-1),*(p-2)))>0) pop();
			push(array[i]);
		}
		return p-stack;
	}
	double maxPntDis(int num)
	{
		double ans=0;
		int q=1;
		stack[num]=stack[0];
		for(int p=0;p<num;p++)
		{
			while(xmult(stack[p+1],stack[q+1],stack[p])>xmult(stack[p+1],stack[q],stack[p]))
			{
				q=(q+1)%num;
			}
			ans=max(ans,max(pntDis(stack[p],stack[q]),pntDis(stack[p+1],stack[q+1])));
		}
		return ans;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	int n,cas=1;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i]=point(a,b);
		}
		
		sort(array,array+n,cmpX);
		printf("Case %d:\n",cas++);
		printf("Distance of the nearest couple is %.3lf\n",minDisPointPair(0,n-1,array));
		ConvexHull::init(n);
		int len=ConvexHull::graham();
		printf("Distance of the most distant couple is %.3lf\n\n",ConvexHull::maxPntDis(len));
	}
	return 0;
}


