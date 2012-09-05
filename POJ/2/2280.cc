//Result: wizmann	2280	Accepted	336K	1657MS	C++	2289B	2012-09-05 16:42:25
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const double eps=1e-8;
const double inf=1e8;

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
	int type;
	double ang;
	point(){}
	point(double ix,double iy,int it)
	{
		x=ix;y=iy;type=it;
	}
	friend bool operator == (const point &a,const point &b)
	{
		return zero(a.x-b.x)==0 && zero(a.y-b.y)==0;
	}
	friend bool operator < (const point &a,const point &b)
	{
		return a.ang<b.ang;
	}
};


inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

int n;
point array[SIZE];
point tmp[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	int type;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%d",&a,&b,&type);
			array[i]=point(a,b,type);
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			memcpy(tmp,array,sizeof(array));
			for(int j=0;j<n;j++)
			{
				if(tmp[j].type)
				{
					tmp[j].x=2*array[i].x-tmp[j].x;
					tmp[j].y=2*array[i].y-tmp[j].y;
				}
				tmp[j].ang=atan2(tmp[j].y-array[i].y,tmp[j].x-array[i].x);
			}
			swap(tmp[i],tmp[0]);
			sort(tmp+1,tmp+n);
			
			
			int j=1,k=2;
			while(j<n && zero(tmp[j].ang)<=0)
			{
				int on=2;
				while(k<n && xmult(tmp[j],tmp[k],tmp[0])>=0)
				{
					if(zero(xmult(tmp[j],tmp[k],tmp[0]))==0) on++;
					k++;
				}
				ans=max(ans,max(k-j+1,n-(k-j+1)+on));
				j++;
			}
		}
		print(ans);
	}
	return 0;
}
