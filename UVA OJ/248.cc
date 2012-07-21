//Result:248 	Cutting Corners 	Accepted 	C++ 	0.468 	2012-07-20 07:07:55
/*
 * 1.构建矩形，因为给出了三个点，所以矩形是完全确定的。
 * 	 我们就要找到三个点当中的最中间的那个点。从而构建出一个有序的边序列(顺时针、逆时针均可)，用来表示我们的建筑物。
 *   又因为建筑是不可横穿的，所以我们加上对角线，每个建筑存六条边。
 *   这样就不存在一条横穿建筑但是不与建筑物的任意一条边相交的路径了。
 *   如果只存四边的话，对于过对角线的特殊情况是判定无力的。
 *   这样的“六边”矩形我们管它叫“包子”。:-)
 * 
 * 2.删点，对于在建筑物里的点，因为不可能到达，所以标记删除。因为是矩形，所以可以用叉乘求面积的方法，目测比较快。
 * 3.建图，穷举每一条可能的路径，验证这条路径不可能与任一一个建筑相交。对于过建筑外沿的边，我们要加以特殊判定。
 * 4.SPFA，这个没的说了。
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

const double eps=1e-8;
const double inf=1e10;

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

inline double pointDis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

inline double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

inline double dotmult(point sp,point ep,point op)
{
	return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}

struct segment
{
	point p1,p2;
	segment(){}
	segment(const point &ip1,const point &ip2)
	{
		p1=ip1;p2=ip2;
	}
};

bool segIntersect(segment l1,segment l2,point &p)//线段相交，包括特殊的情况
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

bool onSegment(segment s,point p)
{
    return fabs(xmult(s.p2,p,s.p1))<eps && (p.x-s.p1.x)*(p.x-s.p2.x)<=0 && (p.y-s.p1.y)*(p.y-s.p2.y)<=0;
}

struct rect
{
	point p[4];
	segment s[6];
	double area;

	rect(){}
	rect(const point *ip)
	{
		this->setRect(ip);
	}
	void setRect(const point *ip)
	{
		for(int i=0;i<3;i++)
		{
			p[i]=ip[i];
		}
		int ptr=-1;
		for(int i=0;i<3;i++)
		{
			if(zero(dotmult(p[(i+1)%3],p[(i+2)%3],p[i]))==0)
			{
				ptr=i;
				break;
			}
		}

		if(ptr==-1) print("Not a Rect");
		else
		{
			swap(p[0],p[ptr]);
			area=fabs(xmult(p[1],p[2],p[0]));
			double dx=p[0].x-p[1].x;
			double dy=p[0].y-p[1].y;
			p[3]=point(p[2].x-dx,p[2].y-dy);
			swap(p[2],p[3]);
		}
		for(int i=0;i<4;i++)
		{
			s[i]=segment(p[i],p[(i+1)%4]);
		}
		s[4]=segment(p[0],p[2]);
		s[5]=segment(p[1],p[3]);
	}
	
	bool inrect(const point& ip)
	{
		double res=0;
		for(int i=0;i<4;i++)
		{
			int j=(i+1)%4;
			res+=fabs(xmult(p[i],p[j],ip))/2;
		}
		bool flag=true;
		for(int i=0;i<4;i++)
		{
			if(onSegment(s[i],ip))
			{
				flag=false;
				break;
			}
		}
		return zero(res-area)==0 && flag;
	}
};

point start,end;
int n,sz;
rect house[SIZE];
int ind;
vector< pair<int,double> > g[SIZE];

void makeG()
{
	for(int i=0;i<SIZE;i++) g[i].clear();
	vector< pair<point,int> > pvec;
	pvec.push_back(make_pair(start,1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			pvec.push_back(make_pair(house[i].p[j],1));
		}
	}
	pvec.push_back(make_pair(end,1));
	sz=pvec.size();
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(house[j].inrect(pvec[i].first))
			{
				pvec[i].second=0;
				break;
			}
		}
	}
	
	for(int i=0;i<sz;i++)
	{
		if(!pvec[i].second) continue;
		for(int j=i+1;j<sz;j++)
		{
			if(!pvec[j].second) continue;
			
			segment edge(pvec[i].first,pvec[j].first);
			bool cross=false;
			for(int k=0;k<n && !cross;k++)
			{
				for(int l=0;l<6;l++)
				{
					if(onSegment(house[k].s[l],edge.p1) ||
						onSegment(house[k].s[l],edge.p2) ||
						onSegment(edge,house[k].s[l].p1) ||
						onSegment(edge,house[k].s[l].p2))
					{
						continue;
					}
					else
					{
						point c;
						if(segIntersect(edge,house[k].s[l],c))
						{
							cross=true;
							break;
						}
					}
				}
			}
			if(!cross)
			{
				double dis=pointDis(pvec[i].first,pvec[j].first);
				g[i].push_back(make_pair(j,dis));
				g[j].push_back(make_pair(i,dis));
			}
		}
	}
}

double spfa(int st,int end)
{
	double dis[SIZE<<2];
	fill(dis,dis+(SIZE<<2),inf);
	queue<int> q;
	q.push(st);
	bitset< (SIZE<<2) > visit;
	dis[st]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].first;
			double dist=g[now][i].second;
			
			if(dis[now]+dist<dis[next])
			{
				dis[next]=dis[now]+dist;
				if(!visit[next])
				{
					visit[next]=1;
					q.push(next);
				}
			}
		}
	}
	return dis[end];
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b,c,d;
	int cas=1;
	while(input(n) && n>=0)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		start=point(a,b);
		end=point(c,d);
		point array[3];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%lf%lf",&a,&b);
				array[j]=point(a,b);
			}
			house[i]=rect(array);
		}
		makeG();
		
		if(cas>1) puts("");
		printf("Scenario #%d\n",cas++);
		printf("   route distance: %.2f\n",spfa(0,sz-1));
	}
	return 0;
}
