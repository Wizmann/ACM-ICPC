//Result:wizmann	1556	Accepted	864K	16MS	G++	3513B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100
#define mul(x) ((x)*(x))
#define INF 1<<30
#define eps 1e-5
#define pb push_back

struct point
{
	double x,y;

	point(){}
	point(double i_fx,double i_fy)
	{
		x=i_fx;y=i_fy;
	}

	void setpoint(double i_fx,double i_fy)
	{
		x=i_fx;y=i_fy;
	}

	double pointDis(const point& i_cp)
	{
		return sqrt(mul(i_cp.x-x)+mul(i_cp.y-y));
	}
	
	inline void printpoint()
	{
		print(x<<' '<<y);
	}
};

struct segment
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
		print("");
	}
};

double xmult(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}//可以进行重载

bool segIntersect(segment l1,segment l2)
{
	if((max(l1.p1.x,l1.p2.x)>min(l2.p1.x,l2.p2.x))&&
	   (max(l1.p1.y,l1.p2.y)>min(l2.p1.y,l2.p2.y))&&
	   (max(l2.p1.x,l2.p2.x)>min(l1.p1.x,l1.p2.x))&&
	   (max(l2.p1.y,l2.p2.y)>min(l1.p1.y,l1.p2.y))&&//快速排斥实验
	   fabs((xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2))<=eps)&&
	   fabs((xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2))<=eps))//跨立实验
	{
		return true;
	}
	else return false;
}

int n;
vector<point> pnt;
vector<segment> seg;
double g[SIZE][SIZE];
double ans;
double dis[SIZE];

void check()
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++) g[i][j]=INF;
	}
	int sz=pnt.size();
	for(int i=0;i<sz;i++)
	{
		for(int j=i+1;j<sz;j++)
		{
			bool insec=false;
			for(int k=0;k<(int)seg.size();k++)
			{
				if(segIntersect(segment(pnt[i],pnt[j]),seg[k]))
				{
					insec=true;
					break;
					//print(i<<' '<<j);
				}
			}
			if(!insec) g[j][i]=g[i][j]=pnt[i].pointDis(pnt[j]);
		}
	}
}

void dij()
{
	int sz=pnt.size();
	for(int i=0;i<sz;i++) dis[i]=INF;
	dis[0]=0;
	bitset<SIZE> visit;
	visit.reset();
	for(int i=0;i<sz;i++)
	{
		int pos;
		double minval=INF;
		for(int j=0;j<sz;j++)
		{
			if(dis[j]<minval && !visit[j])
			{
				pos=j;
				minval=dis[j];
			}
		}
		
		visit[pos]=1;
		for(int j=0;j<sz;j++)
		{
			if(!visit[j] && dis[j]>g[pos][j]+minval)
			{
				dis[j]=g[pos][j]+minval;
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n) && n!=-1)
	{
		pnt.clear();
		seg.clear();
		double x,y;
		pnt.pb(point(0,5));
		for(int i=0;i<n;i++)
		{
			input(x);
			vector<double> vec;
			vec.pb(0);
			for(int j=0;j<4;j++)
			{
				input(y);
				vec.pb(y);
				pnt.pb(point(x,y));
			}
			vec.pb(10);
			for(int i=0;i<(int)vec.size();i+=2)
			{
				//print(x<<' '<<vec[i]); print(x<<' '<<vec[i+1]);
				seg.pb(segment(point(x,vec[i]),point(x,vec[i+1])));
			}
		}
		pnt.pb(point(10,5));
		//for(int i=0;i<(int)seg.size();i++)
		//{
		//	seg[i].printsegment();
		//}
		
		//for(int i=0;i<(int)pnt.size();i++)
		//{
		//	pnt[i].printpoint();
		//}
		check();
		dij();
		
		printf("%.2f\n",dis[pnt.size()-1]);
	}
	return 0;
}
		






