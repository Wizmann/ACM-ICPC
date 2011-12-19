//Result:wizmann	3304	Accepted	392K	110MS	G++	5437B	2011-07-14 14:58:41
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

const double eps=1e-8;
const double inf=1e10;

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
		if(fabs(x.a-y.a)<eps&&fabs(x.b-y.b)<eps&&fabs(x.c-y.c)<eps) return true;
		else return false;
	}	
	inline void setline(double ta,double tb,double tc)
	{
		a=ta;b=tb;c=tc;
	}
}line;

inline double max(double a,double b)
{
	return a>b?a:b;
}
inline double min(double a,double b)
{
	return a<b?a:b;
}

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
	if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   fabs((vectorProduct(l1.p1,l2.p1,l2.p2)*vectorProduct(l1.p2,l2.p1,l2.p2))<=eps)&&
	   fabs((vectorProduct(l2.p1,l1.p1,l1.p2)*vectorProduct(l2.p2,l1.p1,l1.p2))<=eps))//跨立实验
	{
		lineIntersect(makeLine(l1),makeLine(l2),p);
		return true;
	}
	else return false;
}

bool onSegment(segment s,point p)
{
	return(fabs(vectorProduct(s.p2,p,s.p1))<eps&&(p.x-s.p1.x)*(p.x-s.p2.x)<=0&&(p.y-s.p1.y)*(p.y-s.p2.y)<=0);
}

bool onLine(line l,point p)
{
	if(fabs(l.a*p.x+l.b*p.y-l.c)<=eps) return true;
	else return false;
}

bool segOrdIntersect(segment s1,segment s2,point &p)//普通相交，无特殊情况
{
	if((segIntersect(s1,s2,p))&&
	   (!onSegment(s1,s2.p1))&&
	   (!onSegment(s1,s2.p2))&&
	   (!onSegment(s2,s1.p1))&&
	   (!onSegment(s2,s1.p2)))
	{
		segIntersect(s1,s2,p);
		return true;
	} 
	else return false;
}

segment extendSegment(point p1,point p2,int flag,double ext)
{
	//flag==0时，不延长;
	//flag==1时，从p1向p2延长
	//flag==2时，从p2向p1延长
	//flag==3时，双向延长
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=ext/fabs(p1.x-p2.x);
	if(d==0||fabs(p1.y-p2.y)>eps) d=ext/fabs(p1.y-p2.y);
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

double distance(double a,double b,double c,double d)
{
	point ta(a,b),tb(c,d);
	return distance(ta,tb);
}

int n;
segment seg[120];

int main()
{
	int t;
	double a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		segment miah;
		point cr;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			seg[i].setsegment(a,b,c,d);
		}
		bool flag=false;
		if(n==1) flag=true;
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(distance(seg[i].p1,seg[j].p1)>eps)
					{
						flag=true;
						miah=extendSegment(seg[i].p1,seg[j].p1,3,inf);
						for(int k=0;k<n;k++)
						{
							if(!segIntersect(miah,seg[k],cr))
							{
								flag=false;
								break;
							}
						}
						if(flag==true) break;
					}
						
					if(distance(seg[i].p1,seg[j].p2)>eps)
					{
						flag=true;
						miah=extendSegment(seg[i].p1,seg[j].p2,3,inf);
						for(int k=0;k<n;k++)
						{
							if(!segIntersect(miah,seg[k],cr))
							{
								flag=false;
								break;
							}
						}
						if(flag==true) break;
					}
						
					if(distance(seg[i].p2,seg[j].p1)>eps)
					{
						flag=true;
						miah=extendSegment(seg[i].p2,seg[j].p1,3,inf);
						for(int k=0;k<n;k++)
						{
							if(!segIntersect(miah,seg[k],cr))
							{
								flag=false;
								break;
							}
						}
						if(flag==true) break;
					}
						
					if(distance(seg[i].p2,seg[j].p2)>eps)
					{
						flag=true;
						miah=extendSegment(seg[i].p2,seg[j].p2,3,inf);
						for(int k=0;k<n;k++)
						{
							if(!segIntersect(miah,seg[k],cr))
							{
								flag=false;
								break;
							}
						}
						if(flag==true) break;
					}
				}
				if(flag==true) break;
			}
		}	
		if(flag==true) puts("Yes!");
		else puts("No!");	
	}
	return 0;
}
