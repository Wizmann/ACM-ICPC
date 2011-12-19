#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const double eps=1e-5;
const double inf=1e10;

typedef struct point
{
	double x,y;
	
	point(){x=y=inf;}
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

bool online(segment s,point p)
{
	return(fabs(vectorProduct(s.p2,p,s.p1))<eps&&(p.x-s.p1.x)*(p.x-s.p2.x)<=0&&(p.y-s.p1.y)*(p.y-s.p2.y)<=0);
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
	const double ext=1e-4;
	//flag==0时，不延长;
	//flag==1时，从p1向p2延长
	//flag==2时，从p2向p1延长
	//flag==3时，双向延长
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=fabs(ext/(p1.x-p2.x));
	if(d==0||fabs(p1.y-p2.y)>eps) d=fabs(ext/(p1.y-p2.y));
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

segment shortenSegment(point p1,point p2,int flag)
{
	const double sht=0.0001;
	//flag==0时，不缩短;
	//flag==1时，p2端缩短
	//flag==2时，p1端缩短
	//flag==3时，双向缩短
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=fabs(sht/(p1.x-p2.x));
	if(d==0||fabs(p1.y-p2.y)>eps) d=fabs(sht/(p1.y-p2.y));
	if(flag & 1)
	{
		res.p2.x-= (p2.x-p1.x)*d;
		res.p2.y-= (p2.y-p1.y)*d;
	}
	if(flag & 2)
	{
		res.p1.x-= (p1.x-p2.x)*d;
		res.p1.y-= (p1.y-p2.y)*d;
	}
	return res;
}


inline double sqr(double a){return a*a;}

double distance(point p1,point p2)
{
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

segment array[120];
int n;
int ans[4];
//No ComPoint//Countless ComPoint//End ComPoint//Ord ComPoints

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	double a,b,c,d;
	while(t--)
	{
		memset(array,0,sizeof(array));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			array[i].setsegment(a,b,c,d);
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				point cr;
				if(!segIntersect(array[i],array[j],cr)) ans[0]++;
				else
				{
					//cr.printpoint();
					segment tmp1=shortenSegment(array[i].p1,array[i].p2,3);
					segment tmp2=shortenSegment(array[j].p1,array[j].p2,3);
					
					if(cr.x>=inf&&cr.y>=inf)
					{
						line a,b;
						a=makeLine(array[i]);
						b=makeLine(array[j]);
						if(a==b)
						{		
							if(segIntersect(tmp1,array[j],cr)&&segIntersect(tmp2,array[i],cr)) ans[1]++;
							else ans[2]++;
						}
						else ans[2]++;
					}
					else
					{
						//cr.printpoint();
						//tmp1.printsegment();
						//tmp2.printsegment();
						if(online(tmp1,cr)&&online(tmp2,cr)) ans[3]++;
						else ans[2]++;
					}
				}
			}
			
		}
		for(int i=0;i<4;i++) printf("%d\n",ans[i]);
		puts("");
	}
	return 0;
}				
