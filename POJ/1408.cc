//Result:wizmann	1408	Accepted	248K	172MS	C++	4878B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const double eps=1e-7;

typedef struct point
{
	double x,y;
	
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
	segment(point t1,point t2){p1=t1;p2=t2;}
	
	inline void setsegment(point a,point b){p1=a;p2=b;}
	inline void printsegment()
	{
		p1.printpoint();p2.printpoint();
	}
}segment;

typedef struct line
{
	double a,b,c;
	
	inline void setline(double ta,double tb,double tc)
	{
		a=ta;b=tb;c=tc;
	}
}line;

double vectorProduct(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

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

line makeLine(segment s)
{
	return makeLine(s.p1,s.p2);
}

bool lineIntersect(line l1,line l2,point &p)
{
	double d=l1.a*l2.b-l2.a*l1.b;
	if(fabs(d)<eps) return false;
	else
	{
		p.x = (l2.c*l1.b-l1.c*l2.b)/d;
		p.y = (l2.a*l1.c-l1.a*l2.c)/d;
		return true;
	}
}

bool segIntersect(segment l1,segment l2,point &p)
{
	if((max(l1.p1.x,l1.p2.x)>min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   (vectorProduct(l1.p1,l2.p1,l2.p2)*vectorProduct(l1.p2,l2.p1,l2.p2)<=0)&&
	   (vectorProduct(l2.p1,l1.p1,l1.p2)*vectorProduct(l2.p2,l1.p1,l1.p2)<=0))//跨立实验
	{
		lineIntersect(makeLine(l1),makeLine(l2),p);
		return true;
	}
	else return false;
}

bool online(segment s,point p)
{
	return(vectorProduct(s.p2,p,s.p1)==0&&(p.x-s.p1.x)*(p.x-s.p2.x)<=0&&(p.y-s.p1.y)*(p.y-s.p2.y)<=0);
}

bool segOrdIntersect(segment s1,segment s2,point &p)//普通相交，无特殊情况
{
	if((segIntersect(s1,s2,p))&&
	   (!online(s1,s2.p1))&&
	   (!online(s1,s2.p2))&&
	   (!online(s2,s1.p1))&&
	   (!online(s2,s1.p2)))
	{
		segIntersect(s1,s2,p);
		return true;
	} 
	else return false;
}

segment extendSegment(point p1,point p2,int flag)
{
	const double inf=1e3;
	//flag==0时，不延长;
	//flag==1时，从p1向p2延长
	//flag==2时，从p2向p1延长
	//flag==3时，双向延长
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=fabs(inf/(p1.x-p2.x));
	if(d==0||fabs(p1.y-p2.y)>eps) d=fabs(inf/(p1.y-p2.y));
	if(flag & 1)
	{
		res.p2.x+= (p2.x-p1.x)*d;
		res.p2.y+= (p2.y-p1.y)*d;
	}
	if(flag & 2)
	{
		res.p1.x+= (p1.x-p2.x)*d;
		res.p1.y+= (p1.y-p2.y)*d;
	}
	return res;
}

inline double sqr(double a){return a*a;}

double distance(point p1,point p2)
{
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

int n;
point array[4][32];
point p_stack[5];
point *st;

inline void stack_init(){memset(p_stack,0,sizeof(p_stack));st=p_stack;}
inline void push(point t){*st=t;st++;}

double area()
{
	double s1=0,s2=0;
	for(int i=0;i<4;i++)
	{
		s1+=p_stack[(i+1)%4].y*p_stack[i].x;
		s2+=p_stack[(i+1)%4].y*p_stack[(i+2)%4].x;
	}
	return fabs((s1-s2)/2);
}

int main()
{
	freopen("input.txt","r",stdin);
	double a;
	while(scanf("%d",&n),n)
	{
		memset(array,0,sizeof(array));
		array[0][0].setpoint(0,0);
		array[0][n+1].setpoint(1,0);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&a);
			array[0][i].setpoint(a,0);
		}
		array[1][0].setpoint(0,1);
		array[1][n+1].setpoint(1,1);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&a);
			array[1][i].setpoint(a,1);
		}
		array[2][0].setpoint(0,0);
		array[2][n+1].setpoint(0,1);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&a);
			array[2][i].setpoint(0,a);
		}
		array[3][0].setpoint(1,0);
		array[3][n+1].setpoint(1,1);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&a);
			array[3][i].setpoint(1,a);
		}
		
		double ans=0;
		for(int i=0;i<=n;i++)
		{
			segment left=extendSegment(array[0][i],array[1][i],3);
			segment right=extendSegment(array[0][i+1],array[1][i+1],3);
			stack<point> s1;
			stack<point> s2;
			for(int i=0;i<=n+1;i++)
			{
				segment ray=extendSegment(array[2][i],array[3][i],3);
				//array[2][i].printpoint();
				//array[3][i].printpoint();
				point t;
				if(segIntersect(left,ray,t))
				{
					s1.push(t);
					//t.printpoint();
				}
				if(segIntersect(right,ray,t))
				{
					s2.push(t);
					//t.printpoint();
				}
			}	
			
			while(s1.size()>=2)
			{
				stack_init();
				push(s1.top());
				push(s2.top());
				s1.pop();s2.pop();
				push(s2.top());
				push(s1.top());
				double t=area();
				//printf("T:%f\n",t);
				ans=max(t,ans);
			}
		}
		cout<<fixed<<setprecision(6)<<ans<<endl;

	}
	return 0;
}  
				
	
