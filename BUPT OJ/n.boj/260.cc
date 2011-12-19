//Result:260 	Accepted 	82ms 	292kb 	G++	5221B	2011-12-11 22:46:51 	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

#define llint long long
#define uint unsigned int
#define input(x) std::cin>>x
#define print(x) std::cout<<x<<std::endl
#define elif else if
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation
#define eps 1e-8
#define inf 1e8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define mul(x) ((x)*(x))

using namespace std;

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

point me;
segment wall;
point pnt[1024]; 
int n;
char bs[1024];

int cmp(const void *a,const void *b)
{
	point *ta=(point*)a,*tb=(point*)b;
	return mul(ta->x-me.x)+mul(ta->y-me.y)-mul(tb->x-me.x)-mul(tb->y-me.y);
}

bool lineIntersect(line l1,line l2,point &p)//直线是否相交，并求交点
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


//计算叉积
double vectorProduct(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}//可以进行重载


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
line makeLine(segment s){return makeLine(s.p1,s.p2);}//由线段生成一条直线
bool onLine(line l,point p) //点是否在直线上
{
	if(fabs(l.a*p.x+l.b*p.y-l.c)<=eps) return true;
	else return false;
}

bool segIntersect(segment l1,segment l2,point &p)//线段相交，包括特殊的情况
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

segment extendSegment(point p1,point p2,int flag,double ext)//线段延长
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



int main()
{
	freopen("a.txt","r",stdin);
	double a,b;
	while(input(n) && n)
	{
		memset(pnt,0,sizeof(pnt));
		memset(bs,0,sizeof(bs));
		
		input(a>>b);
		me.setpoint(a,b);
		point st,end;
		input(a>>b);
		st.setpoint(a,b);
		input(a>>b);
		end.setpoint(a,b);
		wall.setsegment(st,end);
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			pnt[i].setpoint(a,b);
		}
		
		//TODO:
		//1.Sort
		//2.foreach point
		//    judge -> at the same side of the wall
		//    foreach next points
		//         judge -> two point in the same line
		//3.Output
		
		wall=extendSegment(wall.p1,wall.p2,3,-eps);
		
		qsort(pnt,n,sizeof(point),cmp);
		//for(int i=0;i<n;i++) pnt[i].printpoint();
		for(int i=0;i<n;i++)
		{
			if(bs[i]) continue;
			point _tp;
			segment tmp(me,pnt[i]);
			tmp=extendSegment(tmp.p1,tmp.p2,3,-eps);
			if(segIntersect(tmp,wall,_tp)) bs[i]=1;
			
			for(int j=i+1;j<n;j++)
			{
				line t=makeLine(tmp);
				if(onLine(t,pnt[j])) bs[j]=1;
			}
		}
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(!bs[i]) ans++;
		}
		print(ans);
	}
	return 0;
}
