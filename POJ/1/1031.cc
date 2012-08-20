//Result:wizmann	1031	Accepted	688K	0MS	G++	1320B	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

inline double mul(double x)
{
	return x*x;
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

double pointDis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double k,h;
int n;
point poly[SIZE];

const double pi=acos(-1.);
const point ZERO=point(0,0);

double getangle(const point &sp,const point &ep,const point &op)
{
	double a=atan2(sp.y-op.y,sp.x-op.x);
	double b=atan2(ep.y-op.y,ep.x-op.x);
	if(b-a>pi) a+=2*pi;
	if(a-b>pi) b+=2*pi;
	return a-b;
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	scanf("%lf%lf%d",&k,&h,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&a,&b);
		poly[i]=point(a,b);
	}
	double maxi,mini,sum;
	maxi=mini=sum=0;
	for(int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		
		double angle=getangle(poly[i],poly[j],ZERO);
		sum+=angle;
		mini=min(mini,sum);
		maxi=max(maxi,sum);
		
		if(maxi-mini>=2*pi)
		{
			maxi=mini+2*pi;
			break;
		}
	}
	printf("%.2f\n",k*h*(maxi-mini));
	return 0;
}
