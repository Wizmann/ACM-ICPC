//Result:2012-07-06 22:26:21	Accepted	3881	1656MS	2848K	2707 B	G++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010

const double eps=1e-12;
const double inf=1e100;
const int INF=1<<30;

struct point
{
	double x,y;
	point(){}
	point(double i_a,double i_b)
	{
		x=i_a;y=i_b;
	}
};

struct island
{
	point p;
	int ind;

	island(){}
	island(const point& i_p,int i_ind)
	{
		p=i_p;ind=i_ind;
	}
	friend bool operator < (const island& a,const island& b)
	{
		if(a.p.x!=b.p.x) return a.p.x<b.p.x;
		else return a.p.y>b.p.y;
	}
};

inline double mul(double x){return x*x;}
inline int zero(double x)
{
	if(fabs(x)<eps) return 0;
	else if(x>eps) return 1;
	else return -1;
}
int n;
island array[SIZE];
point vec;
const double pi=acos(-1.);
double wind;

double xmult(const point&s,const point&e,const point& o)
{
	return (s.x-o.x)*(e.y-o.y)-(s.y-o.y)*(e.x-o.x);
}

double pntDis(const point&a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

point rotate(point v,point p,double angle,double scale)
{
	point ret=p;
	v.x-=p.x;v.y-=p.y;
	p.x=scale*cos(angle);
	p.y=scale*sin(angle);
	ret.x+=v.x*p.x-v.y*p.y;
	ret.y+=v.x*p.y+v.y*p.x;
	return ret;
}


double getTan(int a,int b)
{
	double dx=array[a].p.x-array[b].p.x;
	double dy=array[a].p.y-array[b].p.y;
	if(!zero(dy)) return inf;
	else return dx/dy;
}

void slove(int& a,int &b)
{
	a=b=INF;
	double mini_angle=inf;
	for(int i=0;i<n-1;i++)
	{
		int j=i+1;
		double t=getTan(i,j);
		while(j<n && !zero(t-getTan(i,j))) j++;
		t=fabs(t);
		if(zero(mini_angle-t)>=0)
		{
			if(zero(mini_angle-t)>0) a=b=INF;
			mini_angle=t;
			int ta,tb;
			ta=array[i].ind;
			int ptr=i;
			for(int k=i+1;k<j;k++)
			{
				tb=array[k].ind;
				if(array[ptr].p.y>array[k].p.y) swap(ta,tb);
				if(ta<a || (ta==a && tb<b))
				{
					a=ta;b=tb;
				}
				if(array[k].ind<ta)
				{
					ta=array[k].ind;
					ptr=k;
				}
			}
		}
		if(i+1<j) i=j-2;
		else i=j-1;
	}
}
				

int main()
{
	freopen("input.in","r",stdin);
	double a,b;
	while(scanf("%d%lf%lf",&n,&a,&b)==3)
	{
		vec=point(a,b);
		wind=pntDis(vec,point(0,0));
		double angle=asin(xmult(vec,point(0,wind),point(0,0))/(wind*wind));

		if(a>=0 && b<=0) angle=pi-angle;
		else if(a<=0 && b<=0) angle=-pi-angle;
		
		//print(angle*180/pi);

		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i]=island(point(a,b),i+1);
			array[i].p=rotate(array[i].p,point(0,0),angle,1.);
		}
		sort(array,array+n);
		int ans_a,ans_b;
		slove(ans_a,ans_b);
		printf("%d %d\n",ans_a,ans_b);
	}
	return 0;
}


