#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>

using std::set;

#define eps 1e-8
#define inf 1e8
#define zero(x) (((x)>0?(x):-(x))<eps)

//数据类型
typedef struct point
{
	double x,y;
	
	point(){x=y=inf;}
	point(double a,double b){x=a;y=b;}
	inline void setpoint(double a,double b){x=a;y=b;}
	inline void printpoint()
	{
		printf("%.2f,%.2f\n",x,y);
	}
}point;

typedef struct segment
{
	point p1,p2;
	
	segment(){}
	segment(double x1,double y1,double x2,double y2)
	{
		p1.setpoint(x1,y1);
		p2.setpoint(x2,y2);
	}
	segment(point t1,point t2){p1=t1;p2=t2;}
	
	inline void setsegment(point a,point b){p1=a;p2=b;}
	inline void setsegment(double x1,double y1,double x2,double y2)
	{
		p1.setpoint(x1,y1);
		p2.setpoint(x2,y2);
	}
	inline void printsegment()
	{
		p1.printpoint();p2.printpoint();
	}
}segment;

typedef struct line
{
	double a,b,c;
	
	friend bool operator == (const line x,const line y)
	{
		double d;
		if(!zero(y.a)) d=x.a/y.a;
		else if(!zero(y.b)) d=x.b/y.b;
		else if(zero(y.c))
		{
			if(!zero(x.b)||!zero(x.a)) return true;
			else if(zero(x.c)) return true;
			else return false;
		}
		else return false;

		if(x.a==d*y.a&&x.b==d*y.b&&x.c==d*y.c) return true;
		else return false;
	}	
	inline void setline(double ta,double tb,double tc)
	{
		a=ta;b=tb;c=tc;
	}
}line;


//由两点生成一条直线
line makeLine(point p1,point p2)
{
	line res;
	int sig=1;
	res.a=p2.y-p1.y;
	if(res.a<0)
	{
		sig=-1;
		res.a=sig*res.a;
	}
	res.b=sig*(p1.x-p2.x);
	res.c=sig*(p1.y*p2.x-p2.y*p1.x);
	return res;
}


point array[230];
set<double> s;

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		array[i].setpoint(a,b);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			line l=makeLine(array[i],array[j]);
			if(!zero(l.a)) s.insert(l.b/l.a);
			else s.insert(100000000000.0);
		}
	}
	
	printf("%d\n",s.size());
	return 0;
}		
			
