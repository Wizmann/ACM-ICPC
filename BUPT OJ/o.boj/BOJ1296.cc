//Result:1296	Accepted	12MS	360K	G++	 1756B	2012-02-20 22:10:38	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define eps 1e-8

inline double mul(double x)
{
	return x*x;
}

struct point
{
	double x,y;
	
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
	
	friend bool operator < (const point &a,const point &b)
	{
		return a.x<b.x;
	}
	
	double pntDis(const point& pnt)
	{
		return sqrt(mul(pnt.x-x)+mul(pnt.y-y));
	}
};

point lft[SIZE],rht[SIZE];

double getcos(double a,double b,double c)
{
	return ( (mul(a)+mul(b)-mul(c))/(2*a*b) ) + eps;
}

double calMinDis(point *st,point* end,int nst,int nend)
{
	double ans=100000000000000000000.;
	for(int i=0;i+1<nst;i++)
	{
		for(int j=0;j<nend;j++)
		{
			double a=end[j].pntDis(st[i]);
			double b=end[j].pntDis(st[i+1]);
			double c=st[i].pntDis(st[i+1]);
			
			ans=min(ans,a);
				ans=min(ans,b);
			
			if(getcos(a,c,b)<0 || getcos(b,c,a)<0)
			{
				
				continue;
			}
			
			double angle=acos( (mul(a)+mul(c)-mul(b))/(2*a*c) );
			//print(angle);
			//print(a*sin(angle));
			ans=min(ans,a*sin(angle));
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	int l,r;
	double a,b;
	while(input(l>>r))
	{
		printf("Case %d:\n",cas++);
		memset(lft,0,sizeof(lft));
		memset(rht,0,sizeof(rht));
		for(int i=0;i<l;i++)
		{
			input(a>>b);
			lft[i]=point(a,b);
		}
		for(int i=0;i<r;i++)
		{
			input(a>>b);
			rht[i]=point(a,b);
		}
		sort(lft,lft+l);
		sort(rht,rht+r);
		double ans=min(calMinDis(lft,rht,l,r),calMinDis(rht,lft,r,l));
		printf("%.3lf\n",ans);
	}
	return 0;
}
