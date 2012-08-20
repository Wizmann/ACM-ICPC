//Result:wizmann	1066	Accepted	256K	32MS	C++	2962B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32
#define eps 1e-9
#define INF 1<<25
#define pb push_back

struct point
{
	double x,y;

	point(double i_x=0,double i_y=0)
	{
		x=i_x;y=i_y;
	}
};

struct segment
{
	point p1,p2;

	segment(){}
	segment(point i_p1,point i_p2)
	{
		p1=i_p1;
		p2=i_p2;
	}

	void setSegment(point i_p1,point i_p2)
	{
		p1=i_p1;
		p2=i_p2;
	}
	
	segment makeShort()
	{
		segment res(p1,p2);
		res.p1.x-=eps;
		res.p1.y-=eps;
		res.p2.x-=eps;
		res.p2.y-=eps;
		return res;
	}
};

struct line
{
	double a,b,c;

	line(){}
	line(segment i_seg)
	{
		this->makeline(i_seg.p1,i_seg.p2);
	}
	void makeline(point p1,point p2)
	{
		a=p2.y-p1.y;
		int sig=1;
		if(a<0)
		{
			sig=-1;
			a*=sig;
		}
		b=sig*(p1.x-p2.x);
		c=sig*(p1.y*p2.x-p2.y*p1.x);
	}
};

double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

bool lineIntersect(line l1,line l2,point &p)
{
	double d=l1.a*l2.b-l2.a*l1.b;
	if(fabs(d)<eps) return false;
	else
	{
		p.x=(l2.c*l1.b-l1.c*l2.b)/d;
		p.y=(l2.a*l1.c-l1.a*l2.c)/d;
		return true;
	}
}

bool segIntersect(segment s1,segment s2,point &p)
{
	if(max(s1.p1.x,s1.p2.x)>=min(s2.p1.x,s2.p2.x) &&
			max(s1.p1.y,s1.p2.y)>=min(s2.p1.y,s2.p2.y) &&
			max(s2.p1.x,s2.p2.x)>=min(s1.p1.x,s1.p2.x) &&
			max(s2.p1.y,s2.p2.y)>=min(s1.p1.y,s1.p2.y) &&
			xmult(s1.p1,s2.p1,s2.p2)*xmult(s1.p2,s2.p1,s2.p2)<=eps &&
			xmult(s2.p1,s1.p1,s1.p2)*xmult(s2.p2,s1.p1,s1.p2)<=eps)
	{
		lineIntersect(line(s1),line(s2),p);
		return true;
	}
	else return false;
}

int n;
segment array[SIZE];
point gSpot;

int main()
{
	freopen("input.txt","r",stdin);
	double a,b,c,d;
	input(n);
	//0->N 1->S 2->W 3->E
	for(int i=0;i<n;i++)
	{
		input(a>>b>>c>>d);
		array[i].setSegment(point(a,b),point(c,d));
	}
	input(gSpot.x>>gSpot.y);
	int ans=INF;
	point tpt;
	for(double i=0;i<=100;i+=0.5)
	{
		int tans=0;
		segment tseg(gSpot,point(i,0));
		for(int k=0;k<n;k++)
		{
			if(segIntersect(tseg,array[k].makeShort(),tpt)) tans++;
		}
		ans=min(ans,tans);
	}
	
	for(double i=0;i<=100;i+=0.5)
	{
		int tans=0;
		segment tseg(gSpot,point(0,i));
		for(int k=0;k<n;k++)
		{
			if(segIntersect(tseg,array[k],tpt)) tans++;
		}
		ans=min(ans,tans);
	}
	
	for(double i=0;i<=100;i+=0.5)
	{
		int tans=0;
		segment tseg(gSpot,point(i,100));
		for(int k=0;k<n;k++)
		{
			if(segIntersect(tseg,array[k],tpt)) tans++;
		}
		ans=min(ans,tans);
	}
	
	for(double i=0;i<=100;i+=0.5)
	{
		int tans=0;
		segment tseg(gSpot,point(100,i));
		for(int k=0;k<n;k++)
		{
			if(segIntersect(tseg,array[k],tpt)) tans++;
		}
		ans=min(ans,tans);
	}
	
	if(n==0) ans=0;
	print("Number of doors = "<<ans+1);
	return 0;
}

