//Result:1025118 	5984 	Save the Students! 	Accepted 	C++ 	0.680 	2012-06-24 04:34:15
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
#define SIZE 55
#define eps 1e-6

const double pi=acos(-1.);

inline bool zero(double a)
{
	if(fabs(a)<eps) return true;
	else return false;
}

inline double mul(double x)
{
	return x*x;
}

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y){x=i_x;y=i_y;}
};

double dis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

struct shape
{
	virtual bool point_in(const point& p)=0;
};

struct circle : public shape
{
	point c;
	int r;
	
	circle(){}
	circle(int i_a,int i_b,int i_c)
	{
		c=point(i_a,i_b);
		r=i_c;
	}
	
	virtual bool point_in(const point& p)
	{
		return dis(c,p)<=r;
	}
};

double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

struct square : public shape
{
	point lb;
	int r;
	
	square(){}
	square(int i_a,int i_b,int i_c)
	{
		lb=point(i_a,i_b);
		r=i_c;
	}
	
	virtual bool point_in(const point& p)
	{
		if(p.x<0 || p.y<0) return false;
		if(p.x-lb.x>= 0 && p.x-lb.x<=r && p.y-lb.y>=0 && p.y-lb.y<=r) return true;
		else return false;
	}
};

struct triangle : public shape
{
	point tp[3];
	
	triangle(){}
	triangle(const point& p0,const point& p1,const point& p2)
	{
		tp[0]=p0;
		tp[1]=p1;
		tp[2]=p2;
	}
	
	virtual bool point_in(const point& p)
	{
		double S=fabs(xmult(tp[1],tp[2],tp[0]));
		double sp=0;
		for(int i=0;i<3;i++)
		{
			sp+=fabs(xmult(tp[i],tp[(i+1)%3],p));
		}
		if(zero(sp-S))
		{
			//print(sp<<' '<<S);
			return true;
		}
		else return false;
	}
};

shape* array[SIZE];
int n;

int main()
{

	int T;
	int a,b,c;
	char cmd[5];
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",cmd);
			if(*cmd=='C')
			{
				scanf("%d%d%d",&a,&b,&c);
				array[i]=new circle(a,b,c);
			}
			else if(*cmd=='S')
			{
				scanf("%d%d%d",&a,&b,&c);
				array[i]=new square(a,b,c);
			}
			else if(*cmd=='T')
			{
				point tp[3];
				for(int j=0;j<3;j++)
				{
					scanf("%d%d",&a,&b);
					tp[j]=point(a,b);
				}
				array[i]=new triangle(tp[0],tp[1],tp[2]);
			}
		}
		int sum=0;
		for(int i=-SIZE;i<SIZE*2;i++)
		{
			for(int j=-SIZE;j<SIZE*2;j++)
			{
				for(int k=0;k<n;k++)
				{
					point pa=point(i,j);
					if(array[k]->point_in(pa))
					{
						sum++;
						//print(pa.x<<' '<<pa.y);
						break;
					}
				}
			}
		}
		print(sum);
		for(int i=0;i<n;i++) delete array[i];
	}
	return 0;
}
		
			
		
