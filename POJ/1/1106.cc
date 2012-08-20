//Result:wizmann	1106	Accepted	756K	16MS	G++	2227B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200
#define mul(x) ((x)*(x))


const double pi=acos(-1.);
const double eps=1e-8;

inline double zero(double x)
{
	if(fabs(x)<eps) return 0;
	else if(x<-eps) return -1;
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
};

struct circle
{
	point c;
	double radius;
	circle(){}
	circle(const point& i_p,double i_r)
	{
		c=i_p;
		radius=i_r;
	}
};

struct node
{
	point c;
	double angle;

	friend bool operator < (const node& a,const node& b)
	{
		return a.angle<b.angle;
	}
};


circle ts;
node array[SIZE];
int n,ind;

double pointDis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

void make_node()
{
	double x=ts.c.x;
	double y=ts.c.y;
	double r=ts.radius;
	point start=point(x-r,y);
	for(int i=0;i<ind;i++)
	{
		double a=r;
		double b=pointDis(array[i].c,ts.c);
		double c=pointDis(start,array[i].c);
		double angle=acos((mul(a)+mul(b)-mul(c))/(2*a*b))/(2*pi)*360.;

		if(array[i].c.y>y) array[i].angle=angle;
		else array[i].angle=360.-angle;
	}
	sort(array,array+ind);
}

int search_exe(int now,double next)
{
	node tmp;
	tmp.angle=next+eps;
	int ptr=lower_bound(array,array+ind,tmp)-array;
	while(array[ptr].angle>next || ptr>=ind) ptr--;
	return ptr-now+1>0?ptr-now+1:0;
}

int search(int nr)
{
	double now=array[nr].angle;
	if(now+180.<=360.)
	{
		double next=now+180.;
		return search_exe(nr,next);
	}
	else
	{
		double next=now+180.-360.;
		return search_exe(nr,360.)+search_exe(0,next);
	}
}



int main()
{
	freopen("l.txt","r",stdin);
	double a,b,c;
	while(scanf("%lf%lf%lff",&a,&b,&c)!=EOF)
	{
		if(c<0) break;
		int ans=0;
		ind=0;
		ts=circle(point(a,b),c);
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			if(zero(pointDis(point(a,b),ts.c)-ts.radius)<=0) array[ind++].c=point(a,b);
		}
		make_node();
		for(int i=0;i<ind;i++)
		{
			ans=max(ans,search(i));
		}
		print(ans);
	}
	return 0;
}
