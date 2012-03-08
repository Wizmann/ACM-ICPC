//Result:wizmann	3805	Accepted	768K	47MS	G++	3875B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define eps 1e-8
#define SIZE 1024

inline int _sign(double x)
{
    if(x>eps) return 1;
    else if(x<-eps) return 2;
    else return 0;
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

struct segment
{
    point p1,p2;
    segment(){}
    segment(point i_p1,point i_p2)
    {
        p1=i_p1;p2=i_p2;
    }
};

double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double pointDis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct cmp
{
    point p;
    cmp(const point &i_p)
    {
        p=i_p;
    }
    bool operator()(const point &a,const point &b)
	{
		if(fabs(xmult(a,b,p))<eps)	return pointDis(a,p)<pointDis(b,p);
		return xmult(a,b,p)>0;
	}
};

int m,n;

point black[SIZE],white[SIZE];

bool segIntersect(segment l1,segment l2)//线段相交，包括特殊的情况
{
	if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   (xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2)<=eps)&&
	   (xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2)<=eps))//跨立实验
	{
		//lineIntersect(makeLine(l1),makeLine(l2),p);
		return true;
	}
	else return false;
}

int findtop(point* array,int sz)
{
	int res=0;
	for(int i=0;i<sz;i++)
	{
		if(array[i].y<array[res].y) res=i;
		else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
	}
	return res;
}

int grahamScan(point* array,int sz)
{
	int top=findtop(array,sz);
	swap(array[0],array[top]);
	sort(array+1,array+sz,cmp(array[0]));
	
	top=1;
	for(int i=2;i<sz;i++)
	{
		while(top && xmult(array[i],array[top],array[top-1])>=0)
		{
			top--;
		}
		array[++top]=array[i];
	}
	return top+1;
}

bool inPolygen(point* array,int sz,point& p)
{
    int s[3]={1,1,1};
    for(int i=0;i<sz && s[1]|s[2];i++)
    {
        s[_sign(xmult(array[(i+1)%sz],p,array[i]))]=0;
    }

    return s[1]|s[2];
}

bool polygenIntersection()//凸包交
{
    if(n==1) black[n++]=black[0];
    if(m==1) white[m++]=white[0];
    if(n==2 && m==2)
    {
        return segIntersect(segment(black[0],black[1]),
							segment(white[0],white[1]));
    }
    else
    {
        if(m>2)//是否是包含关系
        {
			for(int i=0;i<n;i++)
			{
				if(inPolygen(white,m,black[i])) return true;
			}
		}
        if(n>2)
        {
			for(int i=0;i<m;i++)
			{
				if(inPolygen(black,n,white[i])) return true;
			}
		}

        for(int i=0;i<n;i++)//是否有边交点
        {
            for(int j=0;j<m;j++)
            {
                if(segIntersect(segment(black[i],black[(i+1)%n]),
								segment(white[j],white[(j+1)%m])))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(input(n>>m)&& m+n)
    {
        double a,b;
        memset(black,0,sizeof(black));
        memset(white,0,sizeof(white));
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a,&b);
            black[i]=point(a,b);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lf%lf",&a,&b);
            white[i]=point(a,b);
        }
        if(n*m==0 || n*m==1)//特判
		{
			print("YES");
			continue;
		}
        n=grahamScan(black,n);//构造凸包
        m=grahamScan(white,m);

        bool flag=polygenIntersection();
        if(!flag) print("YES");
        else print("NO");
    }
    return 0;
}
