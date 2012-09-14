//Result:	5255	Cops and Robbers	Accepted	C++	0.012	2012-09-14 09:16:39
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE=512;
const double eps=1e-8;
const double inf=1e100;

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

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

struct segment
{
    point p1,p2;
    segment(){}
    segment(const point& i_p1,const point& i_p2)
    {
        p1=i_p1;p2=i_p2;
    }
};

struct line
{
    double a,b,c;
    line(){}
    line(double i_a,double i_b,double i_c)
    {
        a=i_a;b=i_b;c=i_c;
    }
};

line makeLine(point p1,point p2)
{
    line res;
    int sig=1;
    res.a=p2.y-p1.y;
    if(zero(res.a)<0)
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

inline double pntDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

inline double xmult(const point &sp,const point &ep,const point &op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
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

bool segIntersect(segment l1,segment l2,point &p)//线段相交，包括特殊的情况
{
    if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
       (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
       (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
       (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//快速排斥实验
       (xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2)<=eps)&&
       (xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2)<=eps))//跨立实验
    {
        lineIntersect(makeLine(l1),makeLine(l2),p);
        return true;
    }
    else return false;
}

bool onSegment(segment s,point p)
{
    return fabs(xmult(s.p2,p,s.p1))<eps && (p.x-s.p1.x)*(p.x-s.p2.x)<=0 && (p.y-s.p1.y)*(p.y-s.p2.y)<=0;
}


namespace ConvexHull
{
	int sz;
	point array[SIZE],stack[SIZE];
	point *p;
	double area;
	inline void push(point n){*p=n;p++;}
	inline void pop(){p--;}
	inline void init(int isz)
	{
		sz=isz;
		memset(stack,0,sizeof(stack));
		p=stack;
	}

	int cmp(point p1,point p2)
	{
		 if(xmult(p1,p2,array[0])>0) return 1;
		 else if(xmult(p1,p2,array[0])==0 && pntDis(p1,array[0])<pntDis(p2,array[0])) return 1;
		 else return 0;
	}

	int findtop()
	{
		int res=0;
		for(int i=1;i<sz;i++)
		{
			if(array[i].y<array[res].y) res=i;
			else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
		}
		return res;
	}

	int graham()
	{
		int top=findtop();
		push(array[top]);
		swap(array[0],array[top]);
		sort(array+1,array+sz,cmp);

		push(array[1]);
		push(array[2]);
		for(int i=3;i<sz;i++)
		{
			while(zero(xmult(array[i],*(p-1),*(p-2)))>0) pop();
			push(array[i]);
		}
		return p-stack;
	}

	void getarea(int num)
	{
		area=0;
		for(int i=0;i<num;i++)
		{
			int j=(i+1)%num;
			area+=stack[i].x*stack[j].y;
			area-=stack[i].y*stack[j].x;
		}
		area/=2;
		area=fabs(area);
	}

    bool inPolygen(int num,const point& a)
    {
        int cnt=0;
        segment shoot(a,point(1e10,a.y));
        for(int i=0;i<num;i++)
        {
            int ptr=-1;
            int j=(i+1)%num;

            segment edge(stack[i],stack[j]);
            if(onSegment(edge,a)) return true;

            if(zero(stack[i].y-stack[j].y)==0) continue;
            if(onSegment(shoot,stack[i])) ptr=i;
            else if(onSegment(shoot,stack[j])) ptr=j;

            if(ptr!=-1)
            {
                if(zero(stack[ptr].y-max(stack[i].y,stack[j].y))==0) cnt++;
            }            
            else
            {
                point c;
                if(segIntersect(shoot,edge,c))  cnt++;
            }
        }
        //print(cnt);
        return cnt%2==1;
    }
}

point cops[SIZE],robs[SIZE];
point citizen[SIZE];
int c,r,n;
int status[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int len,cas=1;
	double a,b;
	while(input(c>>r>>n) && c+r+n)
	{
		memset(status,-1,sizeof(status));
		for(int i=0;i<c;i++)
		{
			scanf("%lf%lf",&a,&b);
			cops[i]=point(a,b);
		}
		for(int i=0;i<r;i++)
		{
			scanf("%lf%lf",&a,&b);
			robs[i]=point(a,b);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			citizen[i]=point(a,b);
		}
		
		if(c>=3)
		{
			ConvexHull::init(c);
			for(int i=0;i<c;i++)
			{
				ConvexHull::array[i]=cops[i];
			}
			len=ConvexHull::graham();
			if(len>=3)
			{
				ConvexHull::getarea(len);
				for(int i=0;i<n;i++)
				{
					if(ConvexHull::inPolygen(len,citizen[i])) if(status[i]==-1)
					{
						status[i]=1;
					}
				}
			}
		}
		
		if(r>=3)
		{
			ConvexHull::init(r);
			for(int i=0;i<r;i++)
			{
				ConvexHull::array[i]=robs[i];
			}
			len=ConvexHull::graham();
			if(len>=3)
			{
				ConvexHull::getarea(len);
				for(int i=0;i<n;i++)
				{
					if(ConvexHull::inPolygen(len,citizen[i])) if(status[i]==-1)
					{
						status[i]=0;
					}
				}
			}
		}

		printf("Data set %d:\n",cas++);
		for(int i=0;i<n;i++)
		{
			printf("     Citizen at (%.0lf,%.0lf) is ",citizen[i].x,citizen[i].y);
			if(status[i]==1) printf("safe.\n");
			else if(status[i]==0) printf("robbed.\n");
			else printf("neither.\n");
		}
		puts("");
	}
	return 0;
}
